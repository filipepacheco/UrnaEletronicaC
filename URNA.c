#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define PREF 2
#define VER 5
#define QTD 7

//FILIPE PACHECO DE FRAGA
//ALGORITMOS E PROGRAMAÇÃO
//2016/1
//PROFESSOR FERNANDO ARTMANN
//URNA ELETRÔNICA

//Variáveis globais que servem como contadoras e devem ser acessadas por todas as outras funções
int indiceVer=0,indicePref=0,pref=0,ver=0,vagas,totalPref=0,totalVer=0;

//Struct para armazenar dados exclusivamente do partido: como identificação e um contador de eleitos
struct partido {
	int numero;
	int cont;
};
//Struct única para armazenar dados de candidatos vereadores ou prefeitos
struct candidatos {
	char nome[100];
	int numero;
	int cargo;
	int votos;
	int eleito;
	struct partido part;
}candidatoPref[PREF],candidatoVer[VER];

//Função para deixar o código agradável
void delay(){printf(".");sleep(1);printf(".");sleep(1);printf(".");sleep(1);}

//Função para efetuar o cadastro
void fEfetuarCadastro(){
	
	int num;
	//Função específica para cadastrar o candidato
	void ffCadastrarCand(int num){
		//Cadastrar prefeitos
		
		system("CLS");
		//Pega o número enviado pelo usuário por parâmetro
		if (num==1){
			//Impede o usuário de cadastrar além do limite de candidatos
			if(pref>1){
				
				system("CLS");
				
				printf("Você já cadastrou o máximo de candidatos a prefeito");
		 		delay();
		 		
				main();
			}else{
				//Cadastro de candidato
				printf("\t\t\tCADASTRO DE PREFEITO\n\nAPENAS PRIMEIRO NOME DO CANDIDATO:");
				scanf("%s",candidatoPref[indicePref].nome);
				fflush(stdin);
				
				printf("NÚMERO DO SEU PARTIDO:");
				scanf("%d",&candidatoPref[indicePref].part.numero);
				
				printf("NÚMERO DO CANDIDATO:");
				scanf("%d",&candidatoPref[indicePref].numero);
				
				//As variáveis da struct iniciam zeradas
				candidatoPref[indicePref].cargo=num;
				candidatoPref[indicePref].votos=0;
				candidatoPref[indicePref].part.cont=0;
				//Aumento nas variáveis globais contadoras
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
				
				printf("Você já cadastrou o máximo de candidatos a vereador");
				delay();
					
				main();
			}else{
				system("CLS");
				
				printf("\t\t\tCADASTRO DE VEREADOR\n\nAPENAS PRIMEIRO NOME DO CANDIDATO:");
				scanf("%s",candidatoVer[indiceVer].nome);
				
				printf("NÚMERO DO SEU PARTIDO:");
				scanf("%d",&candidatoVer[indiceVer].part.numero);
					
				printf("NÚMERO DO CANDIDATO:");
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
	
	//Função menu para direcionar o usuário 
	void ffCadastro(){
		scanf("%d",&num);
		
		switch(num){
			case 1: ffCadastrarCand(num); break;
			case 2: ffCadastrarCand(num); break;
			case 3: main(); break;
			default: printf("Digite o número 1 para PREFEITO ou 2 para VEREADOR:"); ffCadastro();}
	}
	
	system("CLS");
	printf("\t\t\tCADASTRO DE CANDIDATOS\n\nSe você deseja cadastrar prefeito, digite 1\nSe você deseja cadastrar vereador, digite 2.\nSe você deseja voltar, digite 3.\n\nOPÇÃO:");
	ffCadastro();
}

//Função para armazenar o número de vagas existentes para vereador
void fDadosEleicao(){
	system("CLS");
	
	int num;

	printf("\t\tCADASTRO DE VAGAS PARA VEREADOR\n\nInforme quantas vagas para vereador serão preenchidas.\n\nVAGAS:");
	scanf("%d",&num);
	//No mínimo 1 e no máximo 4 vagas
	if(num<0||num>4){
		system("CLS");
		
		printf("Você deve registrar, no máximo, 4 vagas para vereador");
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
	
//Função principal para votação
void fVotacao(){
	int num, i;
	
	system("CLS");
	
	//Função para cadastrar o voto do usuário que recebe por parâmetro se vota para Pref OU Ver
	void ffCadastrarVoto(int verOuPref){
		int voto,flag=0;
		
		system("CLS");
		
		//Se usuário digitou prefeito...
		if(verOuPref==1){
			printf("\t\t\tVOTAR PARA PREFEITO\nCandidatos disponíveis para prefeito:\n");
			
			//Lista os candidatos disponíveis
			for(i=0;i<PREF;i++){
				if (candidatoPref[i].cargo == 1){
					printf("Nome: %s\tPartido: %d\tNúmero: %d\n",candidatoPref[i].nome,candidatoPref[i].part.numero,candidatoPref[i].numero);
				}
			}
			
			printf("Digite o número do seu candidato a prefeito.\nVOTO:");
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
			//Caso a flag não tenha sido acionada, significa que o voto não teve sucesso
			}else{
				printf("Número não encontrado, digite novamente");
				delay();
				
				ffCadastrarVoto(verOuPref);
			}
		}else{
			printf("\t\t\tVOTAR PARA VEREADOR\nCandidatos disponíveis para vereador:\n");
			
			for(i=0;i<VER;i++){
				if (candidatoVer[i].cargo == 2){
					printf("Nome: %s\tPartido: %d\tNúmero: %d\n",candidatoVer[i].nome,candidatoVer[i].part.numero,candidatoVer[i].numero);
				}
			}
			
			printf("Digite o número do seu candidato a vereador.\nVOTO:");
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
				printf("Número não encontrado, digite novamente");
				delay();
				
				ffCadastrarVoto(verOuPref);
			}
		}
	}
	
	system("CLS");
	
	//Menu para direcionar o usuário
	printf("\t\t\t\tVOTAÇÃO!\n\nSe você deseja votar para prefeito, digite 1\nSe você deseja votar para vereador, digite 2\nSe você deseja voltar, digite 3\n\nOPÇÃO:");
	scanf("%d",&num);
	
	switch(num){
		case 1: ffCadastrarVoto(num); break;
		case 2: ffCadastrarVoto(num); break;
		case 3: main(); break;
		default: printf("Digite 1 para prefeito ou 2 para vereador:"); delay(); fVotacao();}
	
}

//Função principal para fazer os relatórios
void fRelatorios(){
	
	//Função para listar os candidatos
	void ffListaCandidatos(){
		
		system("CLS");
		
		//Função terceária que auxilia a impressão de candidatos
		void fffAparecerCandidatos(int num){
			
			system("CLS");
			
			int i;
			
			//Recebe por parâmetro Pref ou Ver
			if(num==1){
				system("CLS");
						
				printf("\t\t\tCANDIDATOS A PREFEITO:\n");
				
				
				//Imprime um por um
				for (i=0;i<PREF;i++){
					//Se o vetor nao foi registrado, não é imprimido
					if(candidatoPref[i].cargo==num){
						printf("Nome: %s\tPartido: %d\tNúmero: %d\n",candidatoPref[i].nome,candidatoPref[i].part.numero,candidatoPref[i].numero);
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
						printf("Nome: %s\tPartido: %d\tNúmero: %d\n",candidatoVer[i].nome,candidatoVer[i].part.numero,candidatoVer[i].numero);
					}
				}
				
				printf("Digite algo para sair.");
				scanf("%s");
				
				ffListaCandidatos();
			}
		}
		
		int num;
		
		//Menu para direcionar o usuário
		printf("\t\t\tLISTAR CANDIDATOS\nDigite 1 para mostrar os candidatos a prefeito\nDigite 2 para candidados a vereador\nDigite 3 para voltar\n\nOPÇÃO:");
		scanf("%d",&num);
		
		switch(num){
			case 1: fffAparecerCandidatos(num); break;
			case 2: fffAparecerCandidatos(num); break;
			case 3: fRelatorios(); break;
			default: ffListaCandidatos();}
	}
	
	//Função secundária para apurar os resultados
	void ffTotalVotos(){
		//RESULTADO DA ELEIÇÃO
		//Função terceária que recebe por parâmetros os Ver ou Pref e suas respectivas constantes, além das vagas
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
			
			//Saída de dados que já informa se o candidato venceu ou não (primeiro colocado = ganhou, ou 
			//até 'vagas' ganhou
			for(i=0;i<N;i++){
				if((i<vagas)&&(p[i].part.numero>0)){
					printf("Nome: %s\tPartido: %d\tNúmero: %d\tVotos: %d - VENCEDOR!\n",p[i].nome,p[i].part.numero,p[i].numero,p[i].votos);
					p[i].eleito=1;
				}else if (p[i].part.numero>0){
					printf("Nome: %s\tPartido: %d\tNúmero: %d\tVotos: %d\n",p[i].nome,p[i].part.numero,p[i].numero,p[i].votos);
				}
			}
		}
		
		system("CLS");
		
		//Chama as funções para apurar os ganhadores
		printf("\t\t\tCANDIDATOS A PREFEITO:\n");
		fffOrdenar(candidatoPref,PREF,1);
		printf("\t\t\tCANDIDATOS A VEREADOR:\n");
		if (vagas>0){
			fffOrdenar(candidatoVer,VER,vagas);
		}else{
			//Se, ainda, o usuário não informou o número de vagas para vereador, não é possível apurar o resultado
			printf("Não é possível dar o resultado da eleição de vereadores, pois você não informou o número de vagas!\n");
		}
		
		printf("Digite algo para sair: ");
		scanf("%s");
		
		fRelatorios();
	}
	
	//Função secundária para apurar percentual individual de votos computados
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
	
	//Função inacabada para mostrar o total de candidatos eleitos por cada partido registrado
	void ffQuantidadePorPartido(){
		system("CLS");
		
		int i;
		
		printf("\t\tQuantidade de candidatos eleitos por partido político\n\n");
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
	
	//Menu para direcionar o usuário na emissão de relatórios
	printf("\t\t\tEMISSÃO DE RELATÓRIOS\n\nDigite o número correspondente ao relatório que você deseja emitir:\n\n1 - Lista de candidatos por cargo\n2 - Total de votos por candidato (resultado)\n3 - Apuração Percentual de Votos\n4 - Quantidade de candidatos eleito por partido\n5 - Voltar\n\nOPÇÃO:");
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

//Função que serve como navegador para os usuários
void fOpcao(){
	int num;
	
	scanf("%d",&num);
	
	switch (num){
	case 1: fEfetuarCadastro(); break;
	case 2: fDadosEleicao(); break;
	case 3: fVotacao(); break;
	case 4: fRelatorios(); break;
	case 5: break;
	default: printf("Digite um número entre 1 e 5:"); fOpcao();}
}

//Função principal.-
int main(){
	int i;
	
	system("CLS");
	
	setlocale(LC_ALL, "Portuguese");
	
	printf("\t\t\tBEM-VINDO À URNA ELETRÔNICA!\n\nPor gentileza, digite a opção desejada:\n1 - Cadastrar candidato\n2 - Dados da eleição\n3 - Votar\n4 - Emitir relatórios\n5 - Sair\n\nOPÇÃO:");
	
	fOpcao();

	return 0;
}
