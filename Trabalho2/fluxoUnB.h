#include<bits/stdc++.h> 
using namespace std;

class Materia{
    private:
        vector<Materia> posreq;
	    string nome;
        string abreviatura;
	    int codigo;
	    int creditos;
        int V = 0; //Nro de vértices
        list<int> *adj; //Ponteiro para um vetor contendo a lista de adjacência

    public:
        Materia(int V); //Construtor

        //Adiciona vértice para o grafo
        void addVertice(int x, int y); 

        void ordenacao_topologica();

        void addConec(Materia aux){
            this->posreq.push_back(aux);
            this->V++;
        }

        string getNome(){
            return this->nome;
        }
        void setNome(string nome){
            this->nome =nome;
        }
        string getAbreviatura(){
            return this -> abreviatura;
        }
        void setAbrev(string nome){
            this->abreviatura = nome;
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
        void printPosreq(){
            cout << "conexoes:" << endl;
            for(auto i: posreq){
                cout << i.getNome() << " -> ";
            }
            cout <<endl;
        }
        

};