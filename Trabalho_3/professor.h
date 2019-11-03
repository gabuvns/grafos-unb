#ifndef _PROFESSOR_H_
#define _PROFESSOR_H_
#include <iostream>
#include "escola.h"
#include <vector> 
using namespace std;

class Professor{
    private:
        int livre;
        string e_escola;     
        string codigo;
        int habilitacoes;
        vector<string> pref;
    
    public:
        
        void setEscola(string e){
            this->e_escola = e;
        }
        string getEscola(){
            return this->e_escola;
        }
        void setLivre(int l){
            this->livre = l;
        }
        int getLivre(){
            return this->livre;
        }
        
        void setCodigo(string cod){
            this->codigo = cod;
        }
        string getCodigo(){
            return this->codigo;
        }
        void setHabilitacoes(int hab){
            this->habilitacoes = hab;
        }
        int getHabilitacoes(){
            return this->habilitacoes;
        }
        void setPref(vector<string> _pref){
            this->pref = _pref;
        }
        vector<string> getPref(){
            return this->pref;
        }
};

#endif