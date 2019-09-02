/*Desenvolvido por:
Carlos Gabriel Vilas Novas Soares  
Carolina Estrella
*/

#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <fstream>
#include "grafo.h"  
#define TAM 62

using namespace std;

bool connects(vector<vector<int> > grafo, int a, int b){
    for(int i=0; i < (int)grafo[a].size(); i++){
        if(grafo[a][i] == b){ //verifica se as conexoes do vertice atual tambem sao conexoes do vertice pai
            return true;
        }
    }
    return false;
}

double coeficiente(vector<vector<int> > grafo, int vertice){
    int triangulo = 0, tamvertice = grafo[vertice].size();
    double coef, possiveltriangulo;
    for(int j=0; j<tamvertice; j++){
        for(int k=j+1; k<tamvertice; k++){
            if(connects(grafo, grafo[vertice][j], grafo[vertice][k])){
                triangulo++; //atualiza o numero de triangulos formados entre os vertices ligados ao grafo[vertice] atual
            }
        }
    } 
    possiveltriangulo = (tamvertice * (tamvertice-1))/2; //calcula quantidade de possvieis triangulos que podem ser formados
    if(tamvertice <= 1)
        coef = 0;
    else
        coef = triangulo/possiveltriangulo;

    return coef;
}

//Nao eh ideal mas funciona
int total = 0;

typedef struct checagem {
    list<int> check[100];
    int num_elementos = 0;
}checa;

checa checa1;

void print_list(list<int> p){
    cout << "Valor listas: "<< endl;
    for(auto node : p ){
        cout << node << " ";
    }
    
}

//Carrega os candidatos em uma lista
list<int> carrega_possiveis(int vertice, list<int> p, Grafo graph){
    list<int> aux_lista;
    Vertice aux_vertice = graph.getEquivalente(vertice);

    for(auto vizinho_vertice : aux_vertice.conexoes){
        for(auto no_total: p){
            if(vizinho_vertice == no_total){
                aux_lista.push_back(vizinho_vertice);
            }
        }
    }
    
    return aux_lista;
}

list<int> carrega_xcluded(int vertice, list<int> x, Grafo graph){
    Vertice aux_vertex = graph.getEquivalente(vertice);

    for(auto node : x){
        for(auto vizinho_vertice : aux_vertex.conexoes){
            if(node == vizinho_vertice){
                x.push_back(node);
            }
        }
    }

    return x;
}

list<int> carrega_clique(int n_vertice, list<int> r){
    r.push_back(n_vertice);
    return r;
}

void print_clique(list<int> r){
    int tamanho = r.size();
    total++;
    cout << "Clique maximal de tamanho " << tamanho << " elementos: ";
    for(auto node: r){
        cout << node << " ";
    }
    cout << endl;
}

int checa_cliques(list<int>r){
    r.sort();
    
    int totalElementos = checa1.num_elementos;

    for(int i = 0; i < totalElementos;i++){
        checa1.check[i].sort();

        if(r == checa1.check[i]){
            return 0;
        }
    }

    for(auto elemento : r){
        checa1.check[totalElementos].push_back(elemento);
    }

    checa1.num_elementos++;
    
    return 1;
}

void bk(list<int> r, list<int> p, list<int> x, Grafo graph){
    if(p.empty() && x.empty()){
        if(checa_cliques(r)){
            print_clique(r);
        }
    }
   
    for(auto vertice : p){
        bk(carrega_clique(vertice, r),carrega_possiveis(vertice, p, graph), carrega_xcluded(vertice, x, graph), graph);    
    }
    return;
}

int main(){
    fstream arquivo;
    arquivo.open("golfinhos.txt");

    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo\n";
    }

    else{
        //Partes 1, 3 e 4
        int z, y;

        //Cria vetor de tamanho 63
        vector< vector<int> > grafo(63);
        //variavel que conta total de conexoes
        int conexoes = 0;

        while(arquivo >> z >> y){
            grafo[z].push_back(y);
            grafo[y].push_back(z);
            conexoes++;
        }

        int nos = (int)grafo.size()-1;
        double coeftotal = 0;

        for(int v=1; v <= nos; v++){
            int grau = 0;
            cout<< "Indice: " << v << endl;
            //verifica todos os vertices ligados ao indice atual
            for(auto x : grafo[v]){
                grau++;
                cout<<  " " << x;
            }
            cout<<endl;
            cout << "Grau: " << grau << endl;
            double coefaglomeracao = coeficiente(grafo, v);
            cout << "Coeficiente de Aglomeração: " << coefaglomeracao <<endl;
            coeftotal+=coefaglomeracao;
            cout<< "==========================================" <<endl;
        }

        cout<<endl;
        cout<< "Coeficiente médio de aglomeração: "<< coeftotal/nos << endl;
        cout<< "Total de conexoes: " << conexoes << endl;
        
        //resetamos o arquivo para seu inicio
        arquivo.clear();
        arquivo.seekg(0, std::ios::beg);
        // Parte 2 do trabalho, Bron-Kerborsch
        //Os numeros representam conexão bidirecionais
        int read_number[2];

        Grafo graph;
        
        //Lendo os numeros do arquivo
        //Assim que a linha é lida, é adicionada ao grafo e passa pra proxima linha
        
        while(!arquivo.eof()){
            for(int j = 0; j < 2;j++){
                arquivo >> read_number[j];
            }
            graph.addVertice(read_number[1], read_number[0]);
        }
        graph.setConexoesTotal(conexoes);
        
        // r = Cliques maximais
        // p = candidatos
        // x = nos ja analizados
    
        list<int> r, p, x;
        for(int i = 1; i <= 62; i++){
            p.push_back(i);
        }

        bk(r, p, x, graph);

        arquivo.close();
        
    }
    
    return 0;
}