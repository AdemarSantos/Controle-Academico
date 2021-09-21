//metodos da classe usuario

#include "usuario.h" // adiciona o arquivo usuario

Usuario::Usuario (string name , string camp, string mat, string sen)
{
	nome=name;
	matricula=mat;
	campus=camp;
	senha=sen;
}


//sets
void Usuario::setNome(string name)
{
  nome = name;
}

void Usuario::setCampus(string camp)
{
  campus = camp;
}

void Usuario::setMatricula(string mat)
{
  matricula = mat;
}

void Usuario::setSenha(string sen){
  senha = sen;
}


//gets
string Usuario::getNome( void ){// retorna o nome
	return nome;
} 
string Usuario::getCampus( void ){// retorna o campus
	return campus;
} 
string Usuario::getMatricula( void ){// retorna a matricula 
	return matricula;
} 
string Usuario::getSenha( void ){// retorna a senha
	return senha;
} 
    