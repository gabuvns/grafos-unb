#include<bits/stdc++.h> 
using namespace std;

class Materia{
    private:
        vector<Materia> posreq;
	    string *nome;
        string abreviatura;
	    int codigo;
	    int creditos;
        int V; //Nro de vértices
        list<int> *adj; //Ponteiro para um vetor contendo a lista de adjacência

    public:
        Materia(int V); //Construtor

        //Adiciona vértice para o grafo
        void addVertice(int x, int y); 

        void ordenacao_topologica();

        string getNome(){
            return this->nome;
        }
        void setNome(string nome){
            this->nome = nome;
        }
        string getAbreviatura(){
            return this -> abreviatura;
        }
        voit setAbrev(string nome){
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

        void setVertices(int v){
            this->vertices = 
        }

};