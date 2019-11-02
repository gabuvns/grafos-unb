// Arquivo provisorio
// Nao necessario para a versao final


#include <iostream>
#include <fstream>
#include <vector>
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

int main(){
	ifstream arquivo;
    int x, y;

    //Abre o arquivo
    arquivo.open("golfinhos.txt");

    //Se não conseguir abrir o arquivo, imprime mensagem de falha
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo"<<endl;
    }

    //Cria vetor de tamanho 63
    vector< vector<int> > grafo(63);
    //variavel que conta total de conexoes
    int conexoes = 0;

    //Le dados do arquivo e armazena no grafo
    while(arquivo >> x >> y){
        grafo[x].push_back(y);
        grafo[y].push_back(x);
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

    arquivo.close();
 
    return 0;
}
