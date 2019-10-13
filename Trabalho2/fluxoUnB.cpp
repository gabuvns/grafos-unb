#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include "fluxoUnB.h"

using namespace std;

//Reformular
void gen_dot(){
	std::ofstream arquivo ("fluxo.dot");
	arquivo << "digraph fluxo {\n//Primeiro semestre\nIS;\nISC;\nC1;\nAPC;\nFTC;\n//Segundo semestre\nAPC -> CL;\nAPC -> LCL;\nC1 -> C2;\nIAL;\nAPC -> ED;\n//Terceiro semestre\nCL -> OAC;\nLCL -> OAC;\nED -> TP1;\nA1;\nC2 -> CN;\nC1 -> PE;\n//Quarto semestre\nED -> LC1;\nTP1 -> TP2;\nED -> TAG;\nED -> RC;\n//Quinto semestre\nTP1 -> ES;\nED -> LP;\nOAC -> PC;\nTP2 -> PC;\nED -> BD;\nED -> IIA;\n//Sexto semestre\nOAC -> SB;\nED -> SB;\nPC -> SO;\nA1 -> AC;\nED -> SI;\nPE -> CE;\nED -> CE;\n//Setimo semestre\nC1 -> PAA;\nED -> PAA;\nLP -> CMP;\nSB -> CMP;\nAC -> CMP;\nRC -> SC;\n}"<< endl;
	arquivo.close(); 
	system("dot -Tpng fluxo.dot -o fluxo.png");

}

bool is_number(const std::string &s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

Materia::Materia(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Materia::addVertice(int x, int y){

	ifstream arquivo;
	//abre o arquivo
	arquivo.open("grafoinput.txt");

	//se não conseguir abrir imprimir mensagem de erro
	if(!arquivo){
		cout << "Falha ao abrir arquivo" << endl;
	}

	//le e armazena vértices no grafo
	while(arquivo >> x >> y){
		adj[y].push_back(x);
	}
}

void Materia::ordenacao_topologica(){
	//Pilha que armazena resultado
	stack<int> pilha;

	//Vetor de visitados
	int n = 0;
	int visited[n];

	//inicializando vetor 
	memset(visited, 0, sizeof(visited));

	
}


void cria_conexao(int dst, int src, vector<Materia> vetor_mat){
		Materia itsrc = vetor_mat.begin();
		Materia itdest = vetor_mat.begin();

		for(auto it : vetor_mat){
			if(src == it->codigo){
				itsrc=it->foo;
			}
		}

		for(auto it : vetor_mat){
			if(dst == it->codigo){
				dst=it;
			}
		}
		itsrc.addConec(itdest);

}

void le_arquivo(){
	ifstream arquivo;
	vector<Materia> vetor_mat;
	
	//abre o arquivo
	arquivo.open("grafoinput.txt");
	//se não conseguir abrir imprimir mensagem de erro
	if(!arquivo){
		cout << "Falha ao abrir arquivo" << endl;
	}

	string rword;

	int codigo;
	int creditos;
	int total_elem = 0;
	Materia materia_aux(0); 

	while(arquivo >> rword){
		total_elem = stoi(rword);

		if(!rword.compare("materias")){
			arquivo >> rword;
			while(rword.compare("conexoes") != 0){
				for(int i = 0; i< total_elem;i++){
					materia_aux.setNome(rword);
					arquivo >> rword;
					materia_aux.setAbrev(rword);
					arquivo >> rword;
					materia_aux.setCodigo(stoi(rword));
					arquivo >> rword;
					materia_aux.setCreditos(stoi(rword));
					arquivo >> rword;		
					vetor_mat.push_back(materia_aux);
				}

			}	
		}
		//If colocado somente por segurança
		if(!rword.compare("conexoes")){
			arquivo >> rword;
			total_elem = stoi(rword);
			int dst, src;

			for(int i = 0; i < total_elem; i++){
				arquivo >> rword;
				dst = stoi(rword);
				arquivo >> rword;
				src = stoi(rword);
				cria_conexao(dst, src, vetor_mat);
			}		
		}

	}
	
}


int main(){
	
}