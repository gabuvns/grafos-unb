#ifndef _ESCOLA_H_
#define _ESCOLA_H_

#include <iostream>
#include <vector> 
#include "professor.h"
using namespace std;

class Escola{
    private:
        int livre;
        string codigo;
        vector<string> pref;
        vector<string> assigned;
    
    public:
        void setLivre(int l){
            this->livre = l;
        }
        //1 = totalmente livre, 0 =ja possui algum elemento
        int getLivre(){
            if(this->assigned.size() == 0){
                return 1;
            }
            else{
                return 0;
            }
    
        }

        void setCodigo(string cod){
            this->codigo = cod;
        }

        string getCodigo(){
            return this->codigo;
        }

        void setPref(vector<string> _pref){
            this->pref = _pref;
        }
        vector<string> getPref(){
            return this->pref;
        }

        vector<string> getAssigned(){
            return this->assigned;
        }
        int assignedsize(){
            return this->assigned.size();
        }
        void assignProfessor(string p){
            this->assigned.push_back(p);
        }
        void popProfessor(){
            this->assigned.pop_back();
        }
};
#endif