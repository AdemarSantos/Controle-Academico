#ifndef USUARIO_H
#define USUARIO_H

//Principais inclus�es feitas aqui, uma vez que todos incluem usu�rio
#include <iostream> 
#include <cstring> 
#include <clocale>
#include <cstdlib>
#include <vector>
#include <fstream>

using namespace std;

struct cadeira{

	string nome; 
	string periodo; 
	string cargaHoraria;
	float nota1;
	float nota2;
	float nota3;
};

//Classe base usuario
class Usuario{
	protected:
		
    string nome; // nome ususario do sistema 
    string campus; //campus do usuario
    string matricula; // matricula do usuario
    string senha; // senha do usuario

	public:
		//construtor (nome, campus, matricula, senha)
		Usuario(string = "Departamento de Engenharia El�trica",
		string = "Campina Grande", string= "admin", string = "admin"); 
		
	    //sets
	    void setNome( string ); // altera o nome do usuario
	    void setCampus( string ); // altera o campus do usuario
	    void setMatricula( string ); // altera a matricula
	    void setSenha ( string ); // altera a senha
	    
	    string getNome( void ); // retorna o nome
	    string getCampus( void ); // retorna o campus
	    string getMatricula( void ); // retorna a matrícula 
	    string getSenha( void ); // retorna a senha
    
    	void imprimeUsuario();
};

#endif