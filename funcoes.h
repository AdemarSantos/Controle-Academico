#ifndef FUNCOES_H
#define FUNCOES_H

#include "coordenacao.h"
#include "usuario.h"


void CarregaDados(Coordenacao *curso){//carrega dados do txt
	int cont1=0;
	Aluno discente;
	Professor docente;
	cadeira cadeira;
    fstream arquivo;
    string id, senha, nome, campus, curso1, disciplina, perio, ch, linha,idade;

  	
	arquivo.open("alunos",ios::in);
	
	while(getline(arquivo,linha)) //Momento em que o vector aluno recebe txt
	{
		
		if(cont1%6==0)//Nome
			nome=linha;
		else if(cont1%6==1)//Curso
			curso1=linha;
		else if(cont1%6==2)//Campus	
			campus=linha;
		else if(cont1%6==3)//Matr�cula
			id=linha;
		else if(cont1%6==4)//Senha
			senha=linha;
		
		else if(cont1%6==5)//passagem dos dados para o objeto
		{
			discente.setNome(nome);
			//discente.setCurso(curso1);
			discente.setCampus(campus);
			discente.setMatricula(id);
			discente.setSenha(senha);
			
			curso->addListaAlunos(discente);	
		};
        cont1++;
	}
	arquivo.close();

	cont1=0;
	
		arquivo.open("professores",ios::in);
	
	while(getline(arquivo,linha)) //Momento em que o vector aluno recebe txt
	{
		
		if(cont1%7==0)//Nome
			nome=linha;
		else if(cont1%7==1)//Idade
			idade=linha;
		else if(cont1%7==2)
			disciplina=linha;
		else if(cont1%7==3)//Campus	
			campus=linha;
		else if(cont1%7==4)//Identifica��o
			id=linha;
		else if(cont1%7==5)//Senha
			senha=linha;

		else if(cont1%7==6)//passagem dos dados para o objeto
		{
			docente.setNome(nome);
			docente.setCampus(campus);
			docente.setMatricula(id);
			docente.setSenha(senha);
			docente.setDisciplina(disciplina);
			docente.setIdade(idade);
			
			curso->addListaProfessores(docente);
		};
        cont1++;
	}
	arquivo.close();
	
	cont1=0;
	
	arquivo.open("cadeiras",ios::in);
	
	while(getline(arquivo,linha)) //Momento em que o vector aluno recebe txt
	{
		
		if(cont1%4==0)//Nome
			nome=linha;
		else if(cont1%4==1)//Campus	
			perio=linha;
		else if(cont1%4==2)//Identifica��o
			ch=linha;
		else if(cont1%4==3)//passagem dos dados para o objeto
		{
			cadeira.nome=nome;
			cadeira.periodo=perio;
			cadeira.cargaHoraria=ch;			
			curso->AddCadeiraGraduacao(cadeira);
		};
        cont1++;
	}
	arquivo.close();
	
}

void SalvaDados(Coordenacao *curso){//Salva dados no txt
	fstream (arquivo);	
	
	//gravar dados aluno
	arquivo.open("alunos",ios::out);
	
	for(int cont=0 ; cont<curso->getNumAlunos() ; cont++ )
	{
		arquivo <<curso->getAluno(cont).getNome()<<endl;
		arquivo <<curso->getAluno(cont).getCurso()<<endl;
		arquivo <<curso->getAluno(cont).getCampus()<<endl;
		arquivo <<curso->getAluno(cont).getMatricula()<<endl;
		arquivo <<curso->getAluno(cont).getSenha()<<endl;
		arquivo << endl;
	}
	arquivo <<endl;
	arquivo.close();
	
	//gravar dados professor
	arquivo.open("professores",ios::out);
	
	for(int cont=0 ; cont<curso->getNumProfessores() ; cont++ )
	{
		arquivo <<curso->getProfessor(cont).getNome()<<endl;
		arquivo <<curso->getProfessor(cont).getIdade()<<endl;
		arquivo <<curso->getProfessor(cont).getDisciplina()<<endl;
		arquivo <<curso->getProfessor(cont).getCampus()<<endl;
		arquivo <<curso->getProfessor(cont).getMatricula()<<endl;
		arquivo <<curso->getProfessor(cont).getSenha()<<endl;
		arquivo <<endl;
	}
	arquivo <<endl;
	arquivo.close();
	
	//grava dados cadeiras
	arquivo.open("cadeiras",ios::out);
	
	for(int cont=0 ; cont<curso->getNumCadeiras() ; cont++ )
	{
		arquivo <<curso->getCadeira(cont).nome<<endl;
		arquivo <<curso->getCadeira(cont).periodo<<endl;
		arquivo <<curso->getCadeira(cont).cargaHoraria<<endl;

		arquivo <<endl;
	}
	arquivo <<endl;
	arquivo.close();
	
}

void MenuAluno (Coordenacao*curso, int cont1){
	bool sair2=0, aux=0;
	int aux1;
	string senha;
	short opc2;
	do
	{
		system("cls || clear");
		cout <<"Bem vindo, "<<curso->getAluno(cont1).getNome()<<"."<<endl<<endl;
		cout <<"Qual tarefa voc� deseja realizar?"<<endl<<endl;
		cout <<"[0]Fazer Logoff"<<endl;
		cout <<"[1]Consultar cadeiras ofertadas."<<endl;
		cout <<"[2]Realizar matr�cula."<<endl;
		cout <<"[3]Consultar cadeiras matriculadas/notas."<<endl;
		cout <<"[4]Alterar senha."<<endl;
		cout <<"[5]Realizar desv�nculo."<<endl;
		cout <<"[6]Trancar uma cadeira."<<endl<<endl;
		cout <<"Op��o: ";
		cin  >>opc2;
		
		system("cls || clear");
		
		if (opc2==0)//Fazer Logoff FEITO
		{
			sair2=1;
		}
		else if (opc2==1)//Consultar cadeiras ofertadas FEITO
		{
			cout <<"Lista de cadeiras dispon�veis:"<<endl<<endl;
			curso->ImprimeCadeira();
			cout <<endl;
			system("pause");
		}
		else if (opc2==2)//Realizar matr�cula
		{
			cout <<"Lista de cadeiras dispon�veis:"<<endl<<endl;
			curso->ImprimeCadeira();
			cout <<endl;
			cout <<"Insira a cadeira que voc� deseja se matricular."<<endl;
			cout <<"N�mero da cadeira: ";
			cin  >>aux1;
			curso->setAlunoCadeira(cont1,curso->getCadeira(aux1-1));
		}
		else if (opc2==3)//Consultar cadeiras matriculadas
		{
			   cout <<"Lista de cadeiras Matriculadas:"<<endl<<endl;
			   curso->getAluno(cont1).imprimeCadMatriculadas();	
			   cout <<endl;
			   system("pause");
		}
		else if (opc2==4)//Alterar senha FEITO
		{
			cout <<"Insira sua nova senha."<<endl<<endl<<"Senha: ";
			cin  >>senha;
			system("cls || clear");
			cout <<"Tem certeza que deseja alterar a senha para: '";
			cout <<senha<<"' ?"<<endl<<endl;
			cout <<"[0]N�o"<<endl<<"[1]Sim"<<endl<<endl;
			cout <<"Op��o: ";
			cin >> aux;
			if(aux)
				curso->setAlunoSenha(cont1,senha);
			
		}
		else if (opc2==5)//Realizar desv�nculo FEITO
		{
			cout <<"ALERTA!"<<endl;
			cout <<"Tem certeza que deseja realizar desvinculo da ";
			cout <<"institui��o?"<<endl;
			cout <<"Ap�s essa confirma��o, o seu perfil ser� apagado:";
			cout <<" Todas as informa��es ser�o perdidas."<<endl;
			cout <<"...Deseja prosseguir?"<<endl<<endl;
			cout <<"[0]N�o"<<endl<<"[1]Sim"<<endl<<endl;
			cout <<"Op��o: ";
			cin >> aux;
			
			system ("cls || clear");
			if(aux)
			{
				curso->RemoveListaAlunos(cont1);
				cout <<"Matr�cula cancelada com sucesso!";
				sair2=1;
			}
				
			else
			{
				cout <<"Opera��o Cancelada!";
			}
				
			cout <<endl<<endl;
			system("pause");
				
			
		}
		else if (opc2==6)//Trancar uma cadeira
        {
            cout <<"Lista de cadeiras Matriculadas:"<<endl<<endl;
			curso->getAluno(cont1).imprimeCadMatriculadas();
			cout <<"Insira a cadeira que voc� deseja trancar."<<endl;
			cout <<"N�mero da cadeira: ";
			cin  >>aux1;
			curso->setAlunoTrancamento(cont1,aux1-1);
        }
	}
	while (sair2==0);
	
}

void MenuProfessor (Coordenacao*curso, int cont1){
	bool sair2=0, aux=0;
	string senha;
	short opc2;
	do
	{
		
		
		system("cls || clear");//limpeza do terminal
		cout <<"Bem vindo, "<<curso->getProfessor(cont1).getNome();
		cout <<"."<<endl;
		cout <<"Disciplina ministrada: ";
		cout <<curso->getProfessor(cont1).getDisciplina()<<endl<<endl;
		cout <<"Qual tarefa voc� deseja realizar?"<<endl<<endl;
		cout <<"[0]Fazer Logoff"<<endl;
		cout <<"[1]Consultar lista de alunos matriculados/notas."<<endl;
		cout <<"[2]Modificar notas de um aluno."<<endl;
		cout <<"[3]Alterar senha."<<endl;
		cout <<"[4]Realizar desv�nculo da institui��o."<<endl<<endl;
		cout <<"Op��o: ";
		cin  >>opc2;
		
		system("cls || clear");
		if (opc2==0)//Fazer Logoff 
		{
			sair2=1;
		}
		else if (opc2==1)//Consultar lista de alunos matriculados. 
		{
			cout <<"Lista de alunos matriculados:"<<endl<<endl;
			curso->ConsultarNotas(curso->getProfessor(cont1).getDisciplina());
			//cout <<endl;Calculo 1
			cout<<endl<<endl;
			system("pause");
		}
		else if (opc2==2)//Modificar notas de um aluno.
		{
			int alun, pos;
			float nota;
			string discip;
			discip=curso->getProfessor(cont1).getDisciplina();
			cout<<"Lista de alunos matriculados:"<<endl<<endl;
			curso->ConsultarNotas(discip);
			cout<<endl<<endl<<"Insira o n�mero do aluno que voc� deseja atribuir";
			
			cout<<" uma nota."<<endl<<endl;
			cout<<"Aluno: ";
			cin >>alun;
			
			cout<<endl<<"Insira a nota que voc� quer dar."<<endl<<endl;
			cout<<"Nota:";
			cin >>nota;
			
			cout<<endl<<"Em qual posi��o a nota vai ficar?"<<endl<<endl;
			cout<<"Posi��o: ";
			cin >>pos;
			
			curso->AtribuiNota(discip, pos, nota, alun);
			
			system("pause");
		}
		else if (opc2==3)//Alterar senha
		{
			cout <<"Insira sua nova senha."<<endl<<endl<<"Senha: ";
			cin  >>senha;
			system("cls || clear");
			cout <<"Tem certeza que deseja alterar a senha para: '";
			cout <<senha<<"' ?"<<endl<<endl;
			cout <<"[0]N�o"<<endl<<"[1]Sim"<<endl<<endl;
			cout <<"Op��o: ";
			cin >> aux;
			if(aux)
				curso->setProfessorSenha(cont1,senha);
		}
		else if (opc2==4)//Realizar desv�nculo da institui��o
		{
			cout <<"ALERTA!"<<endl;
			cout <<"Tem certeza que deseja realizar desvinculo da ";
			cout <<"institui��o?"<<endl;
			cout <<"Ap�s essa confirma��o, o seu perfil ser� apagado:";
			cout <<" Todas as informa��es ser�o perdidas."<<endl;
			cout <<"...Deseja prosseguir?"<<endl<<endl;
			cout <<"[0]N�o"<<endl<<"[1]Sim"<<endl<<endl;
			cout <<"Op��o: ";
			cin >> aux;
			
			system ("cls || clear");
			if(aux)
			{
				curso->RemoveListaProfessores(cont1);
				cout <<"Matr�cula cancelada com sucesso!";
				sair2=1;
			}
				
			else
			{
				cout <<"Opera��o Cancelada!";
			}
				
			cout <<endl<<endl;
			system("pause");
			
		}
	}
	while (sair2==0);
}

bool ErroUsuario(){
	bool sair;
	system("cls || clear");
	cout <<"ERRO: USU�RIO N�O ENCONTRADO NO SISTEMA!"<<endl<<endl;
	cout <<"Se sua conta ainda n�o foi criada, procure a ";
	cout <<"coordena��o do seu departamento."<<endl;
	cout <<"Caso contr�rio, tente novamente."<<endl<<endl;
	cout <<"[0]Tentar novamente"<<endl<<"[1]Sair"<<endl<<endl;
	cout <<"Op��o: ";
	cin  >>sair;
	return sair;
}

void MenuCoordenacao(Coordenacao*curso, int cont1){
	
	Aluno discente;
	Professor docente;
	cadeira cadeira;
	string id, senha, nome, campus, curso1, disciplina, perio, ch, linha,idade;
	int cont=0;
	
	short   opc2=0;
	bool    sair2=0;
	int apagar;

	
	
    do
	{	
		
		system("cls || clear");
		
		cout <<"Bem vindo, "<<curso->getNome()<<"."<<endl;
		cout <<"Qual tarefa voc� deseja realizar?"<<endl<<endl;
		cout <<"[0]Fazer Logoff"<<endl;
		cout <<"[1]Inserir um aluno."<<endl;
		cout <<"[2]Inserir um professor."<<endl;
		cout <<"[3]Inserir uma cadeira � lista."<<endl;
		cout <<"[4]Consultar lista de alunos."<<endl;
		cout <<"[5]Consultar lista de professores."<<endl;
		cout <<"[6]Consultar lista de cadeiras."<<endl;
		cout <<"[7]Apagar aluno da lista."<<endl;
		cout <<"[8]Apagar professor da lista."<<endl;
		cout <<"[9]Apagar cadeira lista."<<endl<<endl;
		
		cout <<"Op��o: ";
		cin  >>opc2;
		
		system("cls || clear");
		
		if (opc2==0)//Fazer Logoff
		{
			sair2=1;
		}
		else if (opc2==1)//Inserir um aluno
		{
			cout <<"Insira o nome do aluno."<<endl<<"Nome:";
			setbuf(stdin,NULL);
			getline(cin,nome);
			cout <<endl;
			
			cout <<"Insira o campus do aluno."<<endl<<"Campus:";
			setbuf(stdin,NULL);
			getline(cin,campus);
			cout <<endl;
			
			cout <<"Insira a Matr�cula."<<endl<<"Matr�cula:";
			cin  >>id;
			cout <<endl;
			
			cout <<"Insira a senha do aluno."<<endl<<"Senha:";
			cin  >>senha;
			cout <<endl;
			
			discente.setNome(nome); 
			discente.setCampus(campus);
			discente.setMatricula(id);
			discente.setSenha(senha);
		   	
			curso->addListaAlunos(discente);
		}
		else if (opc2==2)//Inserir um professor
		{
			cout <<"Insira o nome do professor."<<endl<<"Nome:";
			setbuf(stdin,NULL);
			getline(cin,nome);
			cout <<endl;
			
			cout <<"Insira o campus do professor."<<endl<<"Campus:";
			setbuf(stdin,NULL);
			getline(cin,campus);
			cout <<endl;
			
			cout <<"Insira a disciplina do professor."<<endl<<"Disciplina:";
			setbuf(stdin,NULL);
			getline(cin,disciplina);
			cout <<endl;
			
			cout <<"Insira a idade do professor."<<endl<<"Idade:";
			cin  >>idade;
			cout <<endl;
			
			cout <<"Insira o ID do professor."<<endl<<"ID:";
			cin  >>id;
			cout <<endl;
			
			cout <<"Insira a senha do professor."<<endl<<"Senha:";
			cin  >>senha;
			cout <<endl;
			
			docente.setNome(nome); 
			docente.setCampus(campus);
			docente.setIdade(idade);
			docente.setMatricula(id);
			docente.setSenha(senha);
			docente.setDisciplina(disciplina);
			
			curso->addListaProfessores(docente);
		}
		else if (opc2==3)//Inserir uma � lista cadeira
		{
			cout <<"Insira o nome da cadeira."<<endl<<"Nome:";
			setbuf(stdin,NULL);
			getline(cin,nome);
			cout <<endl;
			
			cout <<"Insira o per�odo da cadeira."<<endl;
			cout <<"Per�odo:";
			cin  >>perio;
			cout <<endl;
			
			cout <<"Insira a Carga hor�ria da cadeira."<<endl;
			cout <<"Carga Hor�ria:";
			cin  >>ch;
			cout <<endl;
			
			cadeira.nome = nome;
			cadeira.periodo = perio;
			cadeira.cargaHoraria = ch;
			
			curso->AddCadeiraGraduacao(cadeira);
		}
		else if (opc2==4)//Consultar lista de alunos
		{
			cout <<"Lista de Alunos no sistema:"<<endl<<endl;
			curso->ImprimeAlunos();
			cout <<endl<<endl;
			system("pause");
		}
		else if (opc2==5)//Consultar lista de professores
		{
			cout <<"Lista de Professores no sistema:"<<endl<<endl;
			curso->imprimePorfessores();
			cout <<endl<<endl;
			system("pause");
		}
		else if (opc2==6)//Consultar lista de cadeiras
		{
			cout <<"Lista de Cadeiras no sistema:"<<endl<<endl;
			curso->ImprimeCadeira();
			cout <<endl<<endl;
			system("pause");
		}
		else if (opc2==7)//Apagar aluno da lista
		{
			cout <<"Informe o aluno a ser apagado.";
			cout <<"[int]"<<endl<<endl;
			cout <<"N�mero do aluno: ";
			cin  >>apagar;
			
			curso->RemoveListaAlunos(apagar-1);
		}
		else if (opc2==8)//Apagar professor da lista
		{
			cout <<"Informe o professor a ser apagado.";
			cout <<"[int]"<<endl<<endl;
			cout <<"N�mero do professor: ";
			cin  >>apagar;
			
			curso->RemoveListaProfessores(apagar-1);
			
		}
		else if (opc2==9)//Apagar cadeira lista
		{
			cout <<"Informe a cadeira a ser apagado.";
			cout <<"[int]"<<endl<<endl;
			cout <<"N�mero da cadeira: ";
			cin  >>apagar;
			
			curso->RemoveCadeiraGraduacao(apagar-1);
		}
		else
		{
			cout <<"Comando invalido, deseja tentar novamente?"<<endl<<endl;
			cout <<"[0]Sim"<<endl<<"[1]N�o"<<endl<<endl;
			cout <<"Op��o: ";
			cin  >>sair2;
		}
		cont++;
	}
	while(sair2==0);		
}

#endif