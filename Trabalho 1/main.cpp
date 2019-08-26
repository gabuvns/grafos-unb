#include <iostream>
#include <list>
#include <iterator>
#include <fstream>
#include "grafo.h"  
#define TAM 62

using namespace std;

fstream read_file(){
    fstream arquivo;

    arquivo.open("golfinhos.txt");

    if(!arquivo.is_open()){
        cout << "Erro ao abrir arquivo\n";
    }

    return arquivo;
}


int main(){
    fstream arquivo = read_file();
    
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

    arquivo.close();
    return 0;
}