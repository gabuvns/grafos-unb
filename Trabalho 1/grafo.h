#include <iostream>
#define TAM 62

using namespace std;

class Vertice{
    private:
        int numero;
        int grau;
        
    public:
        Vertice(){
            numero = -1;
            grau = 0;    
        }
        list<int> conexoes;

        int getGrau(){
            return this->grau;
        }
        void setNumero(int numero){
            this->numero = numero;
        }

        void addConexao(int numero){
            conexoes.push_back(numero);
            this->grau++;
        }

        int getNumero(){
            return this->numero;
        }
};

class Grafo{
    private:
        Vertice matriz[TAM];
        int conexoesTotal;
    
    public:
        Grafo(){
            conexoesTotal = 0;
        }

        void setConexoesTotal(int number){
            this->conexoesTotal = number;
        }

        void addVertice(int num1, int num2){
            int num1Repetido = 0;
            int num2Repetido = 0;

            //Verifica se o numero ja existe ou nao na matriz
            if(this->matriz[num1-1].getNumero() == -1){
                this->matriz[num1-1].setNumero(num1); 
            }

            if(this->matriz[num2-1].getNumero() == -1){
                this->matriz[num2-1].setNumero(num2); 
            }

            //Aqui testamos os dois numeros por ser um grafo sem direção
            
            for(auto iterator : this->matriz[num1-1].conexoes){
                if(num2 == iterator){
                    num1Repetido = 1;
                }
            }

            if(!num1Repetido){
                this->matriz[num1-1].addConexao(num2);
            }

            for(auto iterator : this->matriz[num2-1].conexoes){
                if(num1 == iterator){
                    num2Repetido = 1;
                }
            }

            if(!num2Repetido){
                this->matriz[num2-1].addConexao(num1);
            }

        }

        void printGrafo(){
            for(int i = 0; i < TAM ; i ++){
                cout << "Indice: " << matriz[i].getNumero() << endl;
                cout << "Grau: " <<matriz[i].getGrau() << endl;
                cout << "Conexoes: ";

                for(auto iterator : matriz[i].conexoes){
                    cout << iterator << " "; 
                }
                cout << "\n==============================================\n";
            }
            cout << "Total de Conexoes: " << conexoesTotal << endl;
        }
};
