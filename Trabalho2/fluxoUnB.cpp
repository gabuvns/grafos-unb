#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include "fluxoUnB.h"

using namespace std;

//Reformular


bool is_number(const std::string &s) {
  return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

Materia::Materia(int V){
	this->V = V;
	adj = new list<int>[V];
}

// void Materia::addVertice(int x, int y){

// 	ifstream arquivo;
// 	//abre o arquivo
// 	arquivo.open("grafoinput.txt");

// 	//se não conseguir abrir imprimir mensagem de erro
// 	if(!arquivo){
// 		cout << "Falha ao abrir arquivo" << endl;
// 	}

// 	//le e armazena vértices no grafo
// 	while(arquivo >> x >> y){
// 		adj[y].push_back(x);
// 	}
// }

// void Materia::ordenacao_topologica(){
// 	//Pilha que armazena resultado
// 	stack<int> pilha;

// 	//Vetor de visitados
// 	int n = 0;
// 	int visited[n];

// 	//inicializando vetor 
// 	memset(visited, 0, sizeof(visited));

	
// }


void inicializa(){
	vector<Materia> v_principal;
	vector<int> conexoes;
	Materia m_aux(0);

	m_aux.setNome("Calculo_1");
	m_aux.setAbrev("C1");
	m_aux.setCodigo(113034);
	m_aux.setCreditos(6);
	conexoes.push_back(113042);
	conexoes.push_back(115045);
	conexoes.push_back(117536);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Introducao_aos_Sistemas_Computacionais");
	m_aux.setAbrev("ISC");
	m_aux.setCodigo(113468);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Fundamentos_Teoricos_da_Computacao");
	m_aux.setAbrev("FTC");
	m_aux.setCodigo(113450);
	m_aux.setCreditos(4);
	conexoes.push_back(117366);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Algoritmo_Programacao_Computadores");
	m_aux.setAbrev("APC");
	m_aux.setCodigo(113476);
	m_aux.setCreditos(6);
	conexoes.push_back(129011);
	conexoes.push_back(116319);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Informatica_e_Sociedade");
	m_aux.setAbrev("IS");
	m_aux.setCodigo(116726);
	m_aux.setCreditos(2);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Circuitos_Logicos");
	m_aux.setAbrev("CL");
	m_aux.setCodigo(129011);
	m_aux.setCreditos(4);
	conexoes.push_back(116394);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Estrutura_de_Dados");
	m_aux.setAbrev("ED");
	m_aux.setCodigo(116319);
	m_aux.setCreditos(4);
	conexoes.push_back(117889);
	conexoes.push_back(117366);
	conexoes.push_back(117901);
	conexoes.push_back(116572);
	conexoes.push_back(116378);
	conexoes.push_back(116343);
	conexoes.push_back(116653);
	conexoes.push_back(116432);
	conexoes.push_back(116416);
	conexoes.push_back(117943);
	conexoes.push_back(117536);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Calculo_2");
	m_aux.setAbrev("C2");
	m_aux.setCodigo(113042);
	m_aux.setCreditos(6);
	conexoes.push_back(113417);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Introducao_Algebra_Linear");
	m_aux.setAbrev("IAL");
	m_aux.setCodigo(113093);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Organizacao_e_Arquitetura_de_Computadores");
	m_aux.setAbrev("OAC");
	m_aux.setCodigo(116394);
	m_aux.setCreditos(4);
	conexoes.push_back(117935);
	conexoes.push_back(116432);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Tecnicas_de_Progamacao_1");
	m_aux.setAbrev("TP1");
	m_aux.setCodigo(117889);
	m_aux.setCreditos(4);
	conexoes.push_back(117897);
	conexoes.push_back(116441);
	conexoes.push_back(117536);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Algebra_1");
	m_aux.setAbrev("A1");
	m_aux.setCodigo(113107);
	m_aux.setCreditos(4);
	conexoes.push_back(116882);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Calculo_Numerico");
	m_aux.setAbrev("CN");
	m_aux.setCodigo(113417);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Probabilidade_e_Estatistica");
	m_aux.setAbrev("PE");
	m_aux.setCodigo(113468);
	m_aux.setCreditos(4);
	conexoes.push_back(117943);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Logica_Computacional_1");
	m_aux.setAbrev("LC1");
	m_aux.setCodigo(113468);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Tecnicas_de_Progamacao_2");
	m_aux.setAbrev("TP2");
	m_aux.setCodigo(113034);
	m_aux.setCreditos(6);
	conexoes.push_back(117935);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Teoria_e_Aplicacao_de_Grafos");
	m_aux.setAbrev("TAG");
	m_aux.setCodigo(117901);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Redes_de_Computadores");
	m_aux.setAbrev("RC");
	m_aux.setCodigo(116572);
	m_aux.setCreditos(4);
	conexoes.push_back(117927);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Linguagens_de_Progamacao");
	m_aux.setAbrev("LP");
	m_aux.setCodigo(116343);
	m_aux.setCreditos(4);
	conexoes.push_back(116441);
	conexoes.push_back(117951);
	conexoes.push_back(121771);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Progamacao_Concorrente");
	m_aux.setAbrev("PC");
	m_aux.setCodigo(117935);
	m_aux.setCreditos(4);
	conexoes.push_back(121771);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Sistemas_de_Informacao");
	m_aux.setAbrev("SI");
	m_aux.setCodigo(116416);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Engenharia_de_Software");
	m_aux.setAbrev("ES");
	m_aux.setCodigo(116441);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Banco_de_Dados");
	m_aux.setAbrev("BD");
	m_aux.setCodigo(116378);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Introducao_a_Inteligencia_Artificial");
	m_aux.setAbrev("IIA");
	m_aux.setCodigo(116653);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Software_Basico");
	m_aux.setAbrev("SB");
	m_aux.setCodigo(116432);
	m_aux.setCreditos(4);
	conexoes.push_back(117951);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Computacao_Experimental");
	m_aux.setAbrev("CE");
	m_aux.setCodigo(117943);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Projeto_e_Analise_de_Algoritmos");
	m_aux.setAbrev("PAA");
	m_aux.setCodigo(117536);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Compiladores");
	m_aux.setAbrev("COM");
	m_aux.setCodigo(117951);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Seguranca_Computacional");
	m_aux.setAbrev("SC");
	m_aux.setCodigo(117927);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Topicos_Avancados_em_Computadores");
	m_aux.setAbrev("TAC");
	m_aux.setCodigo(116921);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();

	m_aux.setNome("Automatos_e_Computabilidade");
	m_aux.setAbrev("AC");
	m_aux.setCodigo(116882);
	m_aux.setCreditos(6);
	conexoes.push_back(117951);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();
	
	m_aux.setNome("Fundamentos_de_Sistemas_Operacionais");
	m_aux.setAbrev("SO");
	m_aux.setCodigo(121771);
	m_aux.setCreditos(4);
	m_aux.setVetor(conexoes);
	v_principal.push_back(m_aux);
	conexoes.clear();
	

	for(auto i: v_principal){
		cout << "Nome:" << i.getNome() <<endl;
		cout << "tamanho vetor "<< i.getTamVetor() << endl;
		i.printVetor();
		cout <<endl;
	}


}


int main(){
	inicializa();
}