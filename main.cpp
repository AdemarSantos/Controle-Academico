/*
Fase delta
PROJETO DE CONCLUS�O DA CADEIRA DE T�CNICAS DE PROGRAMA��O
PROPOSTA: CONSTRU��O DE UM CONTROLE ACAD�MICO UNIVERSIT�RIO
GRUPO:
-ADEMAR SANTOS
*/

#include "funcoes.h"
	
using namespace std;

int main() 
{
  	setlocale(LC_ALL,"");
	
	Coordenacao curso;
	  	
  	string id, senha;
	int cont1=0;
	
	short  opc=0;
	bool   sair=0, controle=0;
	
	CarregaDados(&curso);//carrega dados dos arquivos .txt
	
	do
	{
		cout <<"BEM VINDO AO CONTROLE ACAD�MICO UNIVERSIT�RIO"<<endl<<endl;
		cout <<"Com qual tipo de usu�rio voc� deseja entrar?"<<endl<<endl;
		
		cout <<"[0]Encerrar Processo"<<endl;
		cout <<"[1]Aluno"<<endl;
		cout <<"[2]Professor"<<endl;
		cout <<"[3]Coordena��o"<<endl<<endl;
		
		cout <<"Op��o: ";
		cin  >> opc;
		
		system("cls||clear");
		
		if(opc==0)//Encerra programa
			break;
		
		else if(opc==1)//Entrada como Aluno
		{
			cout <<"Entrada como: Aluno."<<endl;
			cout <<"Insira seus dados."<<endl<<endl;
			cout <<"Matr�cula: ";
			cin  >>id;
			cout <<"Senha: ";
			cin  >>senha;
			
			
			controle=0;
			cont1=0;
			
			while(cont1<curso.getNumAlunos())
			{
				if(id == curso.getAluno(cont1).getMatricula())
				{	
					if(senha == curso.getAluno(cont1).getSenha())
					{
						controle=1;
                        break;	
					}	
				}
				cont1++;
			}
			
			if(controle==0)//tratamento de erro para login ou senha invalidos
			{
				sair=ErroUsuario();
			}
			else 
			{
				
				MenuAluno(&curso, cont1);//menu para aluno
					
			}
		}
		else if(opc==2) //Entrada como Professor
		{
			
			cout <<"Entrada como: Professor."<<endl;
			cout <<"Insira seus dados."<<endl<<endl;
			cout <<"Usu�rio: ";
			cin  >>id;
			cout <<"Senha: ";
			cin  >>senha;
			
			controle=0;
			cont1=0;
			
			while(cont1<curso.getNumProfessores())
			{
				if(id == curso.getProfessor(cont1).getMatricula())
				{	
					if(senha == curso.getProfessor(cont1).getSenha())
					{
						controle=1;
                        break;	
					}	
				}
				cont1++;
			}
			
			if(controle==0)
				sair=ErroUsuario();
			else 
				MenuProfessor (&curso, cont1);
			
			
		}
		else if(opc==3) //Entrada como Coordena��o: LOGIN:"admin",SENHA:"admin"
	    {
			cout <<"Entrada como: Coordena��o."<<endl;
			cout <<"Insira seus dados."<<endl<<endl;
			cout <<"Matr�cula: ";
			cin  >>id;
			cout <<"Senha: ";
			cin  >>senha;
			
			cont1=0;
			
			if(id=="admin" && senha =="admin")
				MenuCoordenacao(&curso,cont1);
			else
			{
				system("cls || clear");
				cout <<"ERRO: USU�RIO N�O ENCONTRADO NO SISTEMA!"<<endl<<endl;
				cout <<"Senha ou id incorretos, tente novamente ou "<<endl;
				cout <<"procure a central de suporte para recuperar seus"<<endl;
				cout <<"dados entrada."<<endl;
				cout <<"Caso contr�rio, tente novamente."<<endl<<endl;
				cout <<"[0]Sair"<<endl<<"[1]Tentar novamente"<<endl;
				cout <<"[2]Contatar central de suporte"<<endl<<endl;
				cout <<"Op��o: ";
				cin  >>cont1;
				
				if(cont1==0)
					sair=1;
				else if(cont1==2)
				{
					system("cls||clear");
					cout <<"SUPORTE ACAD�MICO diz: ";
					cout <<"...Seu login � 'admin' e sua senha � 'admin'."<<endl;
					cout <<"Obrigado pela prefer�ncia!"<<endl<<endl;
					system("pause");
				}
			}
		}
		
		else
		{
			cout <<"Comando invalido, deseja tentar novamente?"<<endl<<endl;
			cout <<"[0]Sim"<<endl<<"[1]N�o"<<endl<<endl;
			cout <<"Op��o: ";
			cin  >>sair;
		}
		
		system("cls||clear");
	}
	while(sair==0);
	
	SalvaDados(&curso);
	
	return 0;
}