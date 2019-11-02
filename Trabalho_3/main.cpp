#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include "professor.h"

using namespace std;

vector<string> normalize( string line){
    vector<string> aux;
    regex reg(":|,");
    regex reg2(" ");
    line = regex_replace(line,reg2,"");
    
    regex reg1("|\\(|\\)|");
    line = regex_replace(line,reg1,"");
    line = regex_replace(line,reg," ");
    
    string pars = " ";
    int pos = 0;
    while((pos = line.find(pars)) != string::npos){
        aux.push_back(line.substr(0,pos));
        line.erase(0,pos+pars.length());
    }
    aux.push_back(line);
    
    return aux;
}

Professor cria_professor(vector<string> nolido){
    Professor paux;
    vector<string> preferencias;
    paux.setCodigo(nolido[0]);
    paux.setHabilitacoes(stoi(nolido[1]));
    for(size_t i =2; i < nolido.size(); i++){
        preferencias.push_back(nolido[i]);
    }
    paux.setPref(preferencias);
    return paux;

}
void printa_professores(vector<Professor> professores){
    for(auto i: professores){
            cout << "Codigo: " << i.getCodigo() << endl;
            cout << "Hab: " << i.getHabilitacoes() << endl;
            cout << "Preferencias: ";

            for(auto j: i.getPref()){
                cout << j << " ";
            }   
            cout << endl;
        
        }
}   

vector<Professor> pega_input(){
    ifstream arquivo;
    arquivo.open("input_professores.txt");
    vector<Professor> professores;
    vector<string> info_lida;

    if(!arquivo){
        cout << "Erro ao ler o arquivo dos professores" <<endl;
    }
    
    for(string linha;getline(arquivo, linha);){
       info_lida = normalize(linha);
       professores.push_back(cria_professor(info_lida));
    }
    printa_professores(professores);
    return professores;
}
int main(){
    pega_input();
}