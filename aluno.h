#ifndef ALUNO_H
#define ALUNO_H


#define LIMITECADEIRAS 30 //DEFINE QUE O LIMITE DE CADEIRAS Ã‰ 30 POR ALUNO

#include "usuario.h" //inclui a classe base usuario


class Aluno: public Usuario {
  
  private: 

    vector< cadeira >ListaCadeirasMatricula; //array de cadeiras
    int numCadeiras;
    string curso;

  public:
  
    Aluno( string="Engenharia Elétrica",int = 0);//costrutor
    

    void TrancarCadeira(int);//tranca a acadeira desejada
    
	//gets
	string getCadeiras(void);
    int getNumCadeira(void);
    string getCurso(void);
		
	//sets
	void setCadeiras(string);
    void setNumCadeiras(int);

	//set
    string setListaCadeiras( int );
    
    //get objeto
    cadeira getCadeiraMat(int);
    
    void setCadeiraMatNota(int,float,cadeira, int);
    void MatriculaCadeira(cadeira);
    void imprimeCadMatriculadas(void);
    
    //void InicializaStruct(void);
};
#endif