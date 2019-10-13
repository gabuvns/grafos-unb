#include <iostream>
#include <vector>
using namespace std;

class Materia{
    private:
        vector<Materia> posreq;
	    string *nome;
        string abreviatura;
	    int codigo;
	    int creditos;

        public:
            string* getNome(){
                return this->nome;
            }
            void setNome(string *nome){
                this->nome = nome;
            }

            int getCodigo(){
                return this->codigo;
            }
            void setCodigo(int codigo){
                this->codigo = codigo;
            }
            int getCreditos(){
                return this->creditos;
            }
            void setCreditos(int creditos){
                this->creditos = creditos;
            }

};
