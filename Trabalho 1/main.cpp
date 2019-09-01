/*Desenvolvido por:
Carlos Gabriel Vilas Novas Soares  
Carolina Estrella
*/

#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include "grafo.h"  
#define TAM 62

using namespace std;
int total = 0;
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
    total++;
    cout << "Clique maximal encontrado!" << endl << "Elementos do clique: ";
    for(auto node: r){
        cout << node << " ";
    }
    cout << endl;
}

void bk(list<int> r, list<int> p, list<int> x, Grafo graph){
    if(p.empty() && x.empty()){
        print_clique(r);
    }
    
    list<int>::iterator it;
    for(it = p.begin(); it != p.end();++it){
        // print_list(p);
        int vertice = *it;
       
        bk(carrega_clique(vertice, r),carrega_possiveis(vertice, p, graph), carrega_xcluded(vertice, x, graph), graph);    
       
        //Complemento relativo
        // p.remove(vertice); 
        //x.push_back(vertice);
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
        //Os numeros representam conexão bidirecionais
        int read_number[2];

        Grafo graph;
        
        //Lendo os numeros do arquivo
        //Assim que a linha é lida, é adicionada ao grafo e passa pra proxima linha
        int conexoes = 0;
        while(!arquivo.eof()){
            for(int j = 0; j < 2;j++){
                arquivo >> read_number[j];
            }
            graph.addVertice(read_number[1], read_number[0]);
            conexoes++;
        }
        graph.setConexoesTotal(conexoes);
        graph.printGrafo();
        
        //Bron-Kerborsch
        
        // r = Cliques maximais
        // p = candidatos
        // x = nos ja analizados
    
        list<int> r, p, x;
        
        for(int i = 1; i <= 62; i++){
            p.push_back(i);
        }

        bk(r, p, x, graph);

        arquivo.close();
        cout <<total;
    }
    
    return 0;
}