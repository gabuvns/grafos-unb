using namespace std;
#include <iostream>
#include <vector> 
using namespace std;

class Professor{
    private:
        string codigo;
        int habilitacoes;
        vector<string> pref;
    
    public:
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