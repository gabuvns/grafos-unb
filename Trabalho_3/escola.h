#ifndef _ESCOLA_H_
#define _ESCOLA_H_

#include <iostream>
#include <vector> 
using namespace std;

class Escola{
    private:
        bool livre;
        string codigo;
        vector<string> pref;
    
    public:
        void setLivre(bool l){
            this->livre = l;
        }
        bool getLivre(){
            return this->livre;
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
};
#endif