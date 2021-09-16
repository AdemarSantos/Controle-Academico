#ifndef COORDENACAO_H
#define COORDENACAO_H

#include "aluno.h"
#include "usuario.h"
#include "professor.h"



class Coordenacao: public Usuario{
	protected: 
	    vector< cadeira >CadeiraGraduacao;
	    vector< Aluno >ListaAlunos;
	    vector< Professor >ListaProfessores;
		string curso;
		
		int NumAlunos;
		int NumProfessores;
		int NumCadeiras;
		
	public:
		//costrutor(NumAlunos,NumProfessores, NumCadeiras)
	    Coordenacao(int=0, int=0, int = 0 , string = " ");  
	    
	    //set para o curso da coordenação
		void setCurso( string ); 
		
	    //gets para controle da quantidade de objetos existentes e nome do curso
		int getNumAlunos(void);
		int getNumProfessores(void);
		int getNumCadeiras(void);
		string getCurso(void); 
		
		//sets objetos
		void setAlunoSenha (int,string);
		void setAlunoCadeira(int,cadeira);
		void setProfessorSenha (int,string);
		void setAlunoTrancamento(int aux, int aux1);
		
		
		//gets objetos
		Aluno getAluno(int);
    	Professor getProfessor(int);
    	cadeira getCadeira(int);
		
		//Acrescimo ao vector
	    void addListaAlunos( Aluno ); 
		void addListaProfessores( Professor ); 
		void AddCadeiraGraduacao( cadeira );
		
		//Remoção do vector
		void RemoveCadeiraGraduacao( int );
		void RemoveListaAlunos( int );
	    void RemoveListaProfessores( int );
	     
		//Impressão
	    void ImprimeCadeira( void );  
		void ImprimeAlunos( void ); 
		void imprimePorfessores( void ); 
    	
    	void AtribuiNota(string, int , float, int);
    	void ConsultarNotas(string);
    	
};

#endif