#include "aluno.h"


Aluno::Aluno(string curso,int numCadeiras){
	this -> curso = curso;
	this -> numCadeiras = numCadeiras;
}

string Aluno ::getCurso(void){
	return curso;
}

void Aluno::MatriculaCadeira(cadeira cad){
	cad.nota1=0;
	cad.nota2=0;
	cad.nota3=0;
	ListaCadeirasMatricula.push_back(cad);
	numCadeiras++;	
}

void Aluno::imprimeCadMatriculadas(void){
	for(int i=0;i<numCadeiras;i++)
	{
		cout <<i+1<<"º Cadeira:"<<endl;
		cout <<"Nome: "<<ListaCadeirasMatricula[i].nome<<endl;
		cout <<"Período Padrão: "<<ListaCadeirasMatricula[i].periodo <<endl;
		cout <<"Carga Horário: "<<ListaCadeirasMatricula[i].cargaHoraria<<endl;
		cout <<"1ªNota: "<<ListaCadeirasMatricula[i].nota1<<endl;
		cout <<"2ªNota: "<<ListaCadeirasMatricula[i].nota2<<endl;
		cout <<"3ªNota: "<<ListaCadeirasMatricula[i].nota3<<endl<<endl<<endl;
	}
}

cadeira Aluno::getCadeiraMat(int aux){
	return ListaCadeirasMatricula[aux];
}

void Aluno::setCadeiraMatNota(int pos,float nota, cadeira cad, int i){
	
	if(pos==2)
	{
		cad.nota2=nota;
	}
	else if(pos==3)
	{
		cad.nota3=nota;
	}
    else
    {
		cad.nota1=nota;
	}	
	ListaCadeirasMatricula[i]=cad;	
}

int Aluno::getNumCadeira(void){
	return numCadeiras;
}

void Aluno :: TrancarCadeira(int remover){
    ListaCadeirasMatricula.erase (ListaCadeirasMatricula.begin() + remover);
    numCadeiras--;
}
