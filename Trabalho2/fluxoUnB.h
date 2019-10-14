#include<bits/stdc++.h>
#include <iostream>
#include <vector> 
using namespace std;

class Materia{
    private:
        vector<int> posreq;
	    string nome;
        string abreviatura;
	    int codigo;
	    int creditos;
        int V = 0; //Nro de vé rtices
        list<int> *adj; //Ponteiro para um vetor contendo a lista de adjacência

    public:
        Materia(int V); //Construtor

        //Adiciona vértice para o grafo
        void addVertice(int x, int y); 

        void ordenacao_topologica();
        void printVetor(){
            for(int i: this->posreq){
                cout << "->" << i;
            }
            cout <<endl;
        }
        void setVetor(vector<int> v){
            this->posreq = v;
            this->V = v.size();
        }


        int getTamVetor(){
            return this->posreq.size();
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
        // void printPosreq(){
        //     cout << "conexoes:" << endl;
        //     for(auto i: this->posreq){
        //         cout << i.getNome() << " -> ";
        //     }
        //     cout <<endl;
        // }
        

};