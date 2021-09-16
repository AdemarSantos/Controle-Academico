#include "coordenacao.h"


//construtor para inicializa��o do n�mero de alunos e do n�mero de professores
Coordenacao::Coordenacao(int Num_alunos, int Num_professores, int Num_cadeiras, string curso){ 
NumAlunos=Num_alunos;
NumProfessores=Num_professores;
NumCadeiras = Num_cadeiras;
this -> curso = curso;
}


//set
void Coordenacao::setCurso( string curso){

  this -> curso = curso;

}


//sets objetos
void Coordenacao::setAlunoSenha (int aux,string senha){
	ListaAlunos[aux].setSenha(senha);
}
void Coordenacao::setAlunoCadeira(int aux, cadeira cad){
	ListaAlunos[aux].MatriculaCadeira(cad);
}
void Coordenacao::setProfessorSenha (int aux,string senha){
	ListaProfessores[aux].setSenha(senha);
}
void Coordenacao::setAlunoTrancamento(int aux, int aux1){
	ListaAlunos[aux].TrancarCadeira(aux1);
}

//Acesso aos objetos do vector
Aluno Coordenacao::getAluno(int aux){
	return ListaAlunos[aux];
}

Professor Coordenacao::getProfessor(int aux){
	return ListaProfessores[aux];
}

cadeira Coordenacao::getCadeira(int aux){
	return 	CadeiraGraduacao[aux];
}



//Retorno do n�mero de alunos (gets)
int Coordenacao::getNumAlunos(void){
	return NumAlunos;
}

int Coordenacao::getNumProfessores(void){
	return NumProfessores;
}

int Coordenacao::getNumCadeiras(void){
	return NumCadeiras;
}

string Coordenacao::getCurso( void ){

  return curso;

}



//M�todo de adi��o de objetos/struct do vector
void Coordenacao::AddCadeiraGraduacao( cadeira cadeiraAUX ){ //adiciona cadeiras a coordena��o
	CadeiraGraduacao.push_back( cadeiraAUX ); //adiciona um nova caderira ao vetor
	NumCadeiras++;
}

void Coordenacao::addListaAlunos( Aluno alunos ){ //fun��o adiciona lista de alunos
	NumAlunos++; //numero de professores
	ListaAlunos.push_back( alunos ); //adiciona um novo aluno a lista
}

void Coordenacao::addListaProfessores(Professor professores){ //fun��o adiciona novo professor
  ListaProfessores.push_back(professores); //adiciona um novo professor ao vetor
  NumProfessores++; //numero de professores no momento

}


//M�todo de subtra��o de de objetos/struct do vector
void Coordenacao::RemoveListaAlunos( int aluno ){ //fun��o adiciona lista de alunos

	if(NumAlunos > 0)
	{
		ListaAlunos.erase( ListaAlunos.begin() + aluno ); //remove do vetor um aluno
		NumAlunos--;
	}
	else
		cout << "erro!!" << endl;
}

void Coordenacao::RemoveListaProfessores( int professor ){ //fun��o adiciona lista de alunos
  
    if( NumProfessores > 0 )
	{
        ListaProfessores.erase( ListaProfessores.begin() + professor ); //remove do vetor um aluno
        NumProfessores--;
	}
    else
		cout << "erro!!" << endl;
}

void Coordenacao::RemoveCadeiraGraduacao( int cadeira ){ // fun��o remove uma cadeira do vetor
	
	if(NumCadeiras > 0)
	{
    	CadeiraGraduacao.erase(CadeiraGraduacao.begin() + cadeira ); //remove do vetor um aluno
    	NumCadeiras--;
    }
    else
    	cout << "erro!!" << endl;
}


//M�todo de impress�o 
void Coordenacao::ImprimeAlunos( void ){
	for(int AUXcont = 0; AUXcont != NumAlunos; AUXcont++ )
	{
		cout << "ALUNO: "<<AUXcont+1<<endl;
		cout << "Nome: "     <<ListaAlunos[ AUXcont ].getNome()   <<endl;
		cout << "Curso: "    <<ListaAlunos[ AUXcont ].getCurso()  <<endl;
		cout << "Campus: "   <<ListaAlunos[ AUXcont ].getCampus() <<endl;
		cout << "Senha: "    <<ListaAlunos[ AUXcont ].getSenha()  <<endl;
		cout << "Matricula: " <<ListaAlunos[AUXcont].getMatricula()<<endl<<endl;
	}
}

void Coordenacao::imprimePorfessores( void ){

  int AUXcont(0); //variavel auxiliar para auxiliar o loop

  for( AUXcont = 0; AUXcont != NumProfessores; ++AUXcont ){
	  
	cout << "PROFESSOR: "<<AUXcont+1<<endl;  
    cout << "Nome: "    <<ListaProfessores[AUXcont].getNome()      << endl;
    cout << "Curso: "   <<ListaProfessores[AUXcont].getDisciplina()<< endl;
    cout << "Campus: "  <<ListaProfessores[AUXcont].getCampus()    << endl;
    cout << "Senha: "   <<ListaProfessores[AUXcont].getSenha()     << endl;
    cout << "Identifica��o: "<<ListaProfessores[AUXcont].getMatricula()<<endl<<endl;

  }

}

void Coordenacao::ImprimeCadeira(void){ // imprime a lista de todas as cadeiras da coordena��o

	for(int contador = 0; contador != NumCadeiras; ++contador )
	{
		cout <<"CADEIRA: "<<contador+1<<endl;	
		cout <<"Nome: "<<CadeiraGraduacao[contador].nome<<endl;
		cout <<"Per�odo: "<<CadeiraGraduacao[contador].periodo<<endl;
		cout <<"Carga hor�ria: "<<CadeiraGraduacao[contador].cargaHoraria<<endl<<endl;
	}
}

void Coordenacao::AtribuiNota(string discip, int pos, float nota, int alun){//disciplina,aluno,posi��o da nota, nota e contador
	
	for (int i = 0; i < NumAlunos; i++){
		for (int j = 0; j < ListaAlunos[i].getNumCadeira(); j++){
			Aluno alu = ListaAlunos[i];
			
			cadeira cad = alu.getCadeiraMat(j);
			if (discip == cad.nome){

					alu.setCadeiraMatNota(pos,nota,cad,alun-1);
					ListaAlunos[alun-1]=alu;
					break;
			}
		}
	}
	cout<<endl;
}


//Consulta/imprime
void Coordenacao::ConsultarNotas(string discip){//passar disciplina do professor

	int cont=0;
	
	//passar por todos os alunos
		//if se a cadeiro do aluno == cadeira pesquisada: mostra nota
		
	for (int i = 0; i < NumAlunos; i++){
		for (int j = 0; j < ListaAlunos[i].getNumCadeira(); j++){
			Aluno alu = ListaAlunos[i];
			cadeira cad = alu.getCadeiraMat(j);
			if (discip == cad.nome){
				
				cout<<cont+1<<"�Aluno:"<<endl;
				cout<<"Nome: "<<alu.getNome()<<endl;
				cout<<1<<"� Nota:"<<alu.getCadeiraMat(j).nota1<<endl;
				cout<<2<<"� Nota:"<<alu.getCadeiraMat(j).nota2<<endl;
				cout<<3<<"� Nota:"<<alu.getCadeiraMat(j).nota3<<endl;
				cout<<endl;
			    cont++;
				
			}
		}
	}
	cout<<endl;
}