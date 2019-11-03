#include <iostream>
#include <vector>
#include <regex>
#include <fstream>
#include "professor.h"
#include "escola.h"

using namespace std;

// Pegando input
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

//Definicoes dos professores
Professor cria_professor(vector<string> nolido){
    Professor paux;
    vector<string> preferencias;
    paux.setCodigo(nolido[0]); 
    paux.setHabilitacoes(stoi(nolido[1]));
    paux.setLivre(1);
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
                cout << j << " " ;
            }   

            cout << endl;
        }
}   

vector<Professor> pega_input_professor(){
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

    
    arquivo.close();
    
    // printa_professores(professores);
    
    return professores;
}

//Definicoes das escolas
Escola cria_escola(vector<string> nolido){
    Escola eaux;
    vector<string> preferencias;
    eaux.setCodigo(nolido[0]);
    eaux.setLivre(1);
    for(size_t i = 1; i < nolido.size(); i++){
        preferencias.push_back(nolido[i]);
    }
    eaux.setPref(preferencias);
   
    return eaux;

}

void printa_escolas(vector<Escola> escolas){
    for(auto i: escolas){
            cout << "Codigo: " << i.getCodigo() << endl;
            cout<< "Preferencias: ";
            for(auto j: i.getPref()){
                cout <<  j << " " ;
            }   
            cout << endl;
        }
}   

vector<Escola> pega_input_escola(){
    ifstream arquivo;
    
    arquivo.open("input_escolas.txt");
    vector<Escola> escolas;
    vector<string> info_lida;

    if(!arquivo){
        cout << "Erro ao ler o arquivo das escolas" <<endl;
    }
    
    for(string linha;getline(arquivo, linha);){
       info_lida = normalize(linha);
       escolas.push_back(cria_escola(info_lida));
    }
    
    arquivo.close();
    
    // printa_escolas(escolas);
    
    return escolas;
}

int professoreslivres(vector<Professor> professores){
    for(auto i: professores){
        if(i.getLivre()){
            cout << "Professor livre: " << i.getCodigo() <<endl;
            return 1;
        }
    }
    return 0;
}
Escola pega_escola(vector<Escola> escola, string codigo){
    for(auto i : escola){
        if(!codigo.compare(i.getCodigo())){
            return i;
        }
    }
}

Professor pega_professor(vector<Professor> professor, string codigo){
    for(auto i : professor){
        if(!codigo.compare(i.getCodigo())){
            return i;
        }
    }
}
int possui_req(Escola escola, Professor paux1, vector<Professor> professores){
    for(auto i: escola.getPref()){
        if(paux1.getHabilitacoes()>= stoi(i)){    
            return 1;
        }
        else{
            return 0;
        }
    }
}
int compareprofessors(Professor paux1, Professor paux2){
    
    return paux1.getHabilitacoes() > paux2.getHabilitacoes();
}
void casamento_estavel(vector<Professor> professores, vector<Escola> escolas){
    while(professoreslivres(professores)){
        Professor paux;
        Escola eaux;
        for(auto i : professores){
            for(auto j : i.getPref()){
                eaux = pega_escola(escolas, j);
                if(possui_req(eaux, i, professores)){
                    if(eaux.getLivre() == 1){
                        cout <<"entrou i :" << i.getCodigo() << "entrou j:" << j << endl;

                        eaux.assignProfessor(i.getCodigo());
                        paux.setEscola(eaux.getCodigo());
                        paux.setLivre(0);
                        eaux.setLivre(0);
                    
                    
                    }
                    else{
                        if(eaux.assignedsize() == 0){
                            if(compareprofessors(paux, pega_professor(professores, eaux.getAssigned()[0]))){
                                pega_professor(professores, eaux.getAssigned()[0]).setEscola("");
                                pega_professor(professores, eaux.getAssigned()[0]).setLivre(1);
                                paux.setLivre(0);
                                paux.setEscola(eaux.getCodigo());
                                eaux.popProfessor();
                                eaux.assignProfessor(paux.getCodigo());
                            }
                        }
                    }
                }
            }
        }
    }
}

void print_relacoes(vector<Professor> professores, vector<Escola> escola){
    for(auto i : professores){
        cout << "Nome Prof: " << i.getCodigo() << endl;
        cout << "Escola:" <<i.getEscola() << endl;
    }
    for(auto i : escola){
        cout <<  "Nome escola: " << i.getCodigo() << endl;
        cout << "Professor(es): ";
        for(auto j: i.getPref()){
            cout << j << " ";
        }
        cout <<endl;
    }
    
}

int main(){
    vector<Professor> professores = pega_input_professor();
    vector<Escola> escolas = pega_input_escola();
    casamento_estavel(professores, escolas);
    print_relacoes(professores, escolas);

}