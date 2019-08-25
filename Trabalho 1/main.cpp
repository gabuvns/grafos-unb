#include <iostream>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;


int main(){
    fstream arquivo;

    arquivo.open("golfinhos.txt");
    if(arquivo.is_open()){
        
    }
    else{
        cout << "Erro ao abrir arquivo";
    }
}