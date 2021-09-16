#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "usuario.h"


class Professor : public Usuario {
	private:
		string disciplina;
    	string idade;
		friend class Coordenacao;
	public:
		
		
		//construtor
    Professor(string = " ");  
        
		//gets
		string getDisciplina(void);
		string getIdade(void);
		
		//sets
		void setDisciplina(string);
		void setIdade(string);
};
#endif