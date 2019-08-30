#include <iostream>
#include <fstream>
#include <vector>
using namespace std;


int main(){
	ifstream arquivo;
    int x, y;

    //Abre o arquivo
    arquivo.open("golfinhos.txt");

    //Se não conseguir abrir o arquivo, imprime mensagem de falha
    if(!arquivo.is_open()){
        cout << "Erro ao abrir o arquivo"<<endl;
    }

    //Cria vetor de tamanho 62
    vector<int> grafo[10000];
    //variavel que conta total de conexoes
    int conexoes = 0;

    //Le dados do arquivo e armazena no grafo
    while(arquivo >> x >> y){
        grafo[x].push_back(y);
        grafo[y].push_back(x);
        conexoes++;
    }

    for(int v=1; v <= 62; v++){
        int grau = 0;
        cout<< "Indice: " << v <<endl;
        //verifica todos os vertices ligados ao indice atual
        for(auto x : grafo[v]){
            grau++;
            cout<< "->" << x;
        }
        cout<<endl;
        cout << "Grau: " << grau<<endl;
        cout<< "==========================================" <<endl;
    }

    cout<< "Total de conexoes: " <<conexoes <<endl;
    arquivo.close();
 
    return 0;
}