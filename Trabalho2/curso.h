class Materia{
    private:
        vector<Materia> posreq;
	    string nome[50];
        string abreviatura;
	    int codigo;
	    int creditos;

        public:
            string getNome(){
                return this->nome;
            }
            void setNome(string nome){
                this->nome = nome;
            }

            void getCodigo(){
                return this->codigo;
            }
            void setCodigo(int codigo){
                this->codigo = codigo;
            }
            void getCreditos(){
                return this->creditos;
            }
            void setCreditos(int creditos){
                this->creditos = creditos;
            }


}
