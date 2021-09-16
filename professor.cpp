#include "professor.h"

//construtor 
Professor::Professor(string disciplina){
  disciplina=disciplina;
}
int ministrarcadeiras(string );
float colocarnota (string );


//sets
void Professor::setDisciplina(string disciplina){
  this -> disciplina = disciplina;
}
void Professor::setIdade(string idade_){
	idade=idade_;
}

//gets
string Professor::getDisciplina(void){
  return disciplina;
}
string Professor::getIdade(void){
	   return idade;	
}

