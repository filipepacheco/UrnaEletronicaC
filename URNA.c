#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define PREF 2
#define VER 5
#define QTD 7

//FILIPE PACHECO DE FRAGA
//ALGORITMOS E PROGRAMA��O
//2016/1
//PROFESSOR FERNANDO ARTMANN
//URNA ELETR�NICA

//Vari�veis globais que servem como contadoras e devem ser acessadas por todas as outras fun��es
int indiceVer=0,indicePref=0,pref=0,ver=0,vagas,totalPref=0,totalVer=0;

//Struct para armazenar dados exclusivamente do partido: como identifica��o e um contador de eleitos
struct partido {
	int numero;
	int cont;
};
//Struct �nica para armazenar dados de candidatos vereadores ou prefeitos
struct candidatos {
	char nome[100];
	int numero;
	int cargo;
	int votos;
	int eleito;
	struct partido part;
}candidatoPref[PREF],candidatoVer[VER];

//Fun��o para deixar o c�digo agrad�vel
void delay(){printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);}

//Fun��o para efetuar o cadastro
void fEfetuarCadastro(){
	
	int num;
	//Fun��o espec�fica para cadastrar o candidato
	void ffCadastrarCand(int num){
		//Cadastrar prefeitos
		
		system("CLS");
		//Pega o n�mero enviado pelo usu�rio por par�metro
		if (num==1){
			//Impede o usu�rio de cadastrar al�m do limite de candidatos
			if(pref>1){
				
				system("CLS");
				
				printf("Voc� j� cadastrou o m�ximo de candidatos a prefeito");
		 		delay();
		 		
				main();
			}else{
				//Cadastro de candidato
				printf("\t\t\tCADASTRO DE PREFEITO\n\nAPENAS PRIMEIRO NOME DO CANDIDATO:");
				scanf("%s",candidatoPref[indicePref].nome);
				fflush(stdin);
				
				printf("N�MERO DO SEU PARTIDO:");
				scanf("%d",&candidatoPref[indicePref].part.numero);
				
				printf("N�MERO DO CANDIDATO:");
				scanf("%d",&candidatoPref[indicePref].numero);
				
				//As vari�veis da struct iniciam zeradas
				candidatoPref[indicePref].cargo=num;
				candidatoPref[indicePref].votos=0;
				candidatoPref[indicePref].part.cont=0;
				//Aumento nas vari�veis globais contadoras
				indicePref+=1;
				pref+=1;
				
				system("CLS");
				//Sucesso
				printf("Prefeito cadastrado com sucesso");
				delay();
				
				main();
			}
		}else{
			//Cadastrar vereadores
			if(ver>4){
				
				system("CLS");
				
				printf("Voc� j� cadastrou o m�ximo de candidatos a vereador");
				delay();
					
				main();
			}else{
				system("CLS");
				
				printf("\t\t\tCADASTRO DE VEREADOR\n\nAPENAS PRIMEIRO NOME DO CANDIDATO:");
				scanf("%s",candidatoVer[indiceVer].nome);
				
				printf("N�MERO DO SEU PARTIDO:");
				scanf("%d",&candidatoVer[indiceVer].part.numero);
					
				printf("N�MERO DO CANDIDATO:");
				scanf("%d",&candidatoVer[indiceVer].numero);
				
				candidatoVer[indiceVer].cargo=num;
				candidatoVer[indiceVer].votos=0;
				candidatoVer[indiceVer].part.cont=0;
				indiceVer+=1;
				ver+=1;
				
				system("CLS");
					
				printf("Vereador cadastrado com sucesso");
				delay();
					
				main();
			}
		}			
	}
	
	//Fun��o menu para direcionar o usu�rio 
	void ffCadastro(){
		scanf("%d",&num);
		
		switch(num){
			case 1: ffCadastrarCand(num); break;
			case 2: ffCadastrarCand(num); break;
			case 3: main(); break;
			default: printf("Digite o n�mero 1 para PREFEITO ou 2 para VEREADOR:"); ffCadastro();}
	}
	
	system("CLS");
	printf("\t\t\tCADASTRO DE CANDIDATOS\n\nSe voc� deseja cadastrar prefeito, digite 1\nSe voc� deseja cadastrar vereador, digite 2.\nSe voc� deseja voltar, digite 3.\n\nOP��O:");
	ffCadastro();
}

//Fun��o para armazenar o n�mero de vagas existentes para vereador
void fDadosEleicao(){
	system("CLS");
	
	int num;

	printf("\t\tCADASTRO DE VAGAS PARA VEREADOR\n\nInforme quantas vagas para vereador ser�o preenchidas.\n\nVAGAS:");
	scanf("%d",&num);
	//No m�nimo 1 e no m�ximo 4 vagas
	if(num<0||num>4){
		system("CLS");
		
		printf("Voc� deve registrar, no m�ximo, 4 vagas para vereador");
		delay();
		
		fDadosEleicao();
	}else{
		system("CLS");
		
		vagas = num;
		
		//Sucesso
		printf("Vagas registradas com sucesso!");
		delay();
		
		main();
	}
}
	
//Fun��o principal para vota��o
void fVotacao(){
	int num, i;
	
	system("CLS");
	
	//Fun��o para cadastrar o voto do usu�rio que recebe por par�metro se vota para Pref OU Ver
	void ffCadastrarVoto(int verOuPref){
		int voto,flag=0;
		
		system("CLS");
		
		//Se usu�rio digitou prefeito...
		if(verOuPref==1){
			printf("\t\t\tVOTAR PARA PREFEITO\nCandidatos dispon�veis para prefeito:\n");
			
			//Lista os candidatos dispon�veis
			for(i=0;i<PREF;i++){
				if (candidatoPref[i].cargo == 1){
					printf("Nome: %s\tPartido: %d\tN�mero: %d\n",candidatoPref[i].nome,candidatoPref[i].part.numero,candidatoPref[i].numero);
				}
			}
			
			printf("Digite o n�mero do seu candidato a prefeito.\nVOTO:");
			scanf("%d",&voto);
			
			//Efetua o voto do candidato. Se sucesso aciona a flag
			for(i=0;i<PREF;i++){
				if (candidatoPref[i].cargo == 1){
					if (voto == candidatoPref[i].numero){
						candidatoPref[i].votos+=1;
						totalPref+=1;
						flag+=1;
						break;	
					}
				}
			}
			//Sucesso
			if (flag==1){
				system("CLS");
				
				printf("Voto registrado com sucesso!");
				flag=0;
				delay();
							
				main();
			//Caso a flag n�o tenha sido acionada, significa que o voto n�o teve sucesso
			}else{
				printf("N�mero n�o encontrado, digite novamente");
				delay();
				
				ffCadastrarVoto(verOuPref);
			}
		}else{
			printf("\t\t\tVOTAR PARA VEREADOR\nCandidatos dispon�veis para vereador:\n");
			
			for(i=0;i<VER;i++){
				if (candidatoVer[i].cargo == 2){
					printf("Nome: %s\tPartido: %d\tN�mero: %d\n",candidatoVer[i].nome,candidatoVer[i].part.numero,candidatoVer[i].numero);
				}
			}
			
			printf("Digite o n�mero do seu candidato a vereador.\nVOTO:");
			scanf("%d",&voto);
			
			for(i=0;i<VER;i++){
				if (candidatoVer[i].cargo == 2){
					if (voto == candidatoVer[i].numero){
						candidatoVer[i].votos+=1;
						totalVer+=1;
						flag+=1;
						break;
					}
				}
			}
			if (flag==1){
				system("CLS");
				printf("Voto registrado com sucesso!");
				flag=0;
				delay();
							
				main();
			}else{
				printf("N�mero n�o encontrado, digite novamente");
				delay();
				
				ffCadastrarVoto(verOuPref);
			}
		}
	}
	
	system("CLS");
	
	//Menu para direcionar o usu�rio
	printf("\t\t\t\tVOTA��O!\n\nSe voc� deseja votar para prefeito, digite 1\nSe voc� deseja votar para vereador, digite 2\nSe voc� deseja voltar, digite 3\n\nOP��O:");
	scanf("%d",&num);
	
	switch(num){
		case 1: ffCadastrarVoto(num); break;
		case 2: ffCadastrarVoto(num); break;
		case 3: main(); break;
		default: printf("Digite 1 para prefeito ou 2 para vereador:"); delay(); fVotacao();}
	
}

//Fun��o principal para fazer os relat�rios
void fRelatorios(){
	
	//Fun��o para listar os candidatos
	void ffListaCandidatos(){
		
		system("CLS");
		
		//Fun��o terce�ria que auxilia a impress�o de candidatos
		void fffAparecerCandidatos(int num){
			
			system("CLS");
			
			int i;
			
			//Recebe por par�metro Pref ou Ver
			if(num==1){
				system("CLS");
						
				printf("\t\t\tCANDIDATOS A PREFEITO:\n");
				
				
				//Imprime um por um
				for (i=0;i<PREF;i++){
					//Se o vetor nao foi registrado, n�o � imprimido
					if(candidatoPref[i].cargo==num){
						printf("Nome: %s\tPartido: %d\tN�mero: %d\n",candidatoPref[i].nome,candidatoPref[i].part.numero,candidatoPref[i].numero);
					}
				}
						
				printf("Digite algo para sair.");
				scanf("%s");
				
				ffListaCandidatos();
			}else{
				system("CLS");
				
				printf("\t\t\tCANDIDATOS A VEREADOR:\n");
				
				for (i=0;i<PREF;i++){
					if(candidatoVer[i].cargo==num){
						printf("Nome: %s\tPartido: %d\tN�mero: %d\n",candidatoVer[i].nome,candidatoVer[i].part.numero,candidatoVer[i].numero);
					}
				}
				
				printf("Digite algo para sair.");
				scanf("%s");
				
				ffListaCandidatos();
			}
		}
		
		int num;
		
		//Menu para direcionar o usu�rio
		printf("\t\t\tLISTAR CANDIDATOS\nDigite 1 para mostrar os candidatos a prefeito\nDigite 2 para candidados a vereador\nDigite 3 para voltar\n\nOP��O:");
		scanf("%d",&num);
		
		switch(num){
			case 1: fffAparecerCandidatos(num); break;
			case 2: fffAparecerCandidatos(num); break;
			case 3: fRelatorios(); break;
			default: ffListaCandidatos();}
	}
	
	//Fun��o secund�ria para apurar os resultados
	void ffTotalVotos(){
		//RESULTADO DA ELEI��O
		//Fun��o terce�ria que recebe por par�metros os Ver ou Pref e suas respectivas constantes, al�m das vagas
		//registradas para vereadores
		void fffOrdenar(struct candidatos *p,int N,int vagas){

			int i, j;
		
			//Algoritmo para ordenar de forma decrescente o vetor de struct
			for (i=N-1;i>0;i--){
				for (j=0;j<i;j++){
					if (p[j].votos<p[j+1].votos){
						struct candidatos aux = p[j];
						p[j] = p[j+1];
						p[j+1] = aux; 
					}
				}
			}
			
			//Sa�da de dados que j� informa se o candidato venceu ou n�o (primeiro colocado = ganhou, ou 
			//at� 'vagas' ganhou
			for(i=0;i<N;i++){
				if((i<vagas)&&(p[i].part.numero>0)){
					printf("Nome: %s\tPartido: %d\tN�mero: %d\tVotos: %d - VENCEDOR!\n",p[i].nome,p[i].part.numero,p[i].numero,p[i].votos);
					p[i].eleito=1;
				}else if (p[i].part.numero>0){
					printf("Nome: %s\tPartido: %d\tN�mero: %d\tVotos: %d\n",p[i].nome,p[i].part.numero,p[i].numero,p[i].votos);
				}
			}
		}
		
		system("CLS");
		
		//Chama as fun��es para apurar os ganhadores
		printf("\t\t\tCANDIDATOS A PREFEITO:\n");
		fffOrdenar(candidatoPref,PREF,1);
		printf("\t\t\tCANDIDATOS A VEREADOR:\n");
		if (vagas>0){
			fffOrdenar(candidatoVer,VER,vagas);
		}else{
			//Se, ainda, o usu�rio n�o informou o n�mero de vagas para vereador, n�o � poss�vel apurar o resultado
			printf("N�o � poss�vel dar o resultado da elei��o de vereadores, pois voc� n�o informou o n�mero de vagas!\n");
		}
		
		printf("Digite algo para sair: ");
		scanf("%s");
		
		fRelatorios();
	}
	
	//Fun��o secund�ria para apurar percentual individual de votos computados
	void ffApuracaoPercentual(){
		system("CLS");
		float percentVotos;
		int i;
		printf("\t\t\tPERCENTUAL DE CADA CANDIDATO:\n");
		//Percentual para prefeitos
		printf("CANDIDATOS A PREFEITO:\n");
		for(i=0;i<PREF;i++){
			if(candidatoPref[i].cargo>0){
				percentVotos = (float)(100*candidatoPref[i].votos)/totalPref;
				printf("Nome: %s\tPercentual de votos: %.2f%% \n", candidatoPref[i].nome, percentVotos);
			}
		}
		//Percentual para vereadores
		printf("CANDIDATOS A VEREADOR:\n");
		for (i=0;i<VER;i++){
			//Apenas imprime caso o vetor struct tenha sido devidamente registrado
			if(candidatoVer[i].cargo>0){ 
				percentVotos = (float)(100*candidatoVer[i].votos)/totalVer;
				printf("Nome: %s\tPercentual de votos: %.2f%% \n", candidatoVer[i].nome, percentVotos);
			}
		}
		
		printf("\nDigite algo para sair.");
		scanf("%s");
		
		fRelatorios();
	}
	
	//Fun��o inacabada para mostrar o total de candidatos eleitos por cada partido registrado
	void ffQuantidadePorPartido(){
		system("CLS");
		
		int i;
		
		printf("\t\tQuantidade de candidatos eleitos por partido pol�tico\n\n");
		for(i=0;i<PREF;i++){
			if(candidatoPref[i].eleito==1){
				candidatoPref[i].part.cont+=1;
				printf("Partido: %d Eleitos: %d\n",candidatoPref[i].part.numero, candidatoPref[i].part.cont);
			}
		}
		for(i=0;i<VER;i++){
			if(candidatoVer[i].eleito==1){
				candidatoVer[i].part.cont+=1;
				printf("Partido: %d Eleitos: %d\n",candidatoVer[i].part.numero, candidatoVer[i].part.cont);
			}
		}
		
		printf("Digite algo para sair: ");
		scanf("%s");
		
		fRelatorios();
	}
		
	system("CLS");
	
	int num;
	
	//Menu para direcionar o usu�rio na emiss�o de relat�rios
	printf("\t\t\tEMISS�O DE RELAT�RIOS\n\nDigite o n�mero correspondente ao relat�rio que voc� deseja emitir:\n\n1 - Lista de candidatos por cargo\n2 - Total de votos por candidato (resultado)\n3 - Apura��o Percentual de Votos\n4 - Quantidade de candidatos eleito por partido\n5 - Voltar\n\nOP��O:");
	scanf("%d",&num);
	
	switch(num){
		case 1: ffListaCandidatos(); break;
		case 2: ffTotalVotos(); break;
		case 3: ffApuracaoPercentual(); break;
		case 4: ffQuantidadePorPartido(); break;
		case 5: main(); break;
		default: fRelatorios();}
		
	return;
}

//Fun��o que serve como navegador para os usu�rios
void fOpcao(){
	int num;
	
	scanf("%d",&num);
	
	switch (num){
	case 1: fEfetuarCadastro(); break;
	case 2: fDadosEleicao(); break;
	case 3: fVotacao(); break;
	case 4: fRelatorios(); break;
	case 5: break;
	default: printf("Digite um n�mero entre 1 e 5:"); fOpcao();}
}

//Fun��o principal.-
int main(){
	int i;
	
	system("CLS");
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\t\tBEM-VINDO � URNA ELETR�NICA!\n\nPor gentileza, digite a op��o desejada:\n1 - Cadastrar candidato\n2 - Dados da elei��o\n3 - Votar\n4 - Emitir relat�rios\n5 - Sair\n\nOP��O:");
	
	fOpcao();

	return 0;
}
