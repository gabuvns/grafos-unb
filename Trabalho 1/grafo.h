#include <iostream>
#define TAM 62

using namespace std;

class vertice{
    private:
        int numero = -1;
        int grau = 0;
        

    public:
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


class grafo{
    private:
        vertice matriz[TAM];
    
    public:
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
            //
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

        //O primeiro numero representa o item, e os subsequentes suas conexoes
        void printGrafo(){
            cout << "Indice" << "     " << "Conexoes" << endl;
            for(int i = 0; i < TAM ; i ++){
                cout << matriz[i].getNumero() << "(" <<matriz[i].getGrau() << ")";

                for(auto iterator : matriz[i].conexoes){
                    cout << "->" << iterator;
                }
                cout << "\n";
            }
        }
};
