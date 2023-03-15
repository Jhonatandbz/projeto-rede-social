#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "alce.h"

#define MAX 50
#define MAX2 100

struct usuario{
int idade;
char nome[121]; 
char sexo[21]; 
char endereco[121]; 
char telefone[21]; 
char sms[256]; 
char privacidade[21]; 
char email[121]; 
char senha[121];
char sobre_voce[256]; 
int codigo;
int amigos[MAX];
int sonic[MAX2];
int alceMSG[MAX];
int mensagens[MAX];
struct usuario* prox;
};

char msg1[] = "Temos que conversar!";
char msg2[] = "Bom dia!";
char msg3[] = "Boa tarde!";
char msg4[] = "Boa noite!";
char msg5[] = "Podemos nos ver?";
char msg6[] = "Ok";
char msg7[] = "Melhor não!";

int valor = 1, qqpessoascadastradasnessacaralhadeprograma=0;

int destino, origem, vertices = 0;
int custo, *custos = NULL;

FILE *save, *q_pessoas, *save_amigos, *save_sonic, *save_msg;

Usuario* LISTA;



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu_login (void){
	int escolha;
	Usuario *alce;
	printf("ALCE CORPORATION ");
	printf("social network\n");
	printf("%i Pessoas utilizam ALCE\n\n\n",qqpessoascadastradasnessacaralhadeprograma);
	printf("1 - Log in\n");
	printf("2 - Cadastrar\n");
	printf("0 - Para sair\n");
	scanf("%d",&escolha);
	system("tput reset");
    
    switch (escolha){
    	case 1 : 
    		login(LISTA);
    		system("tput reset");
    		return 1;
    	break;
    	
    	case 2 :
    		insere(LISTA);
    		salvar(LISTA);
    		system("read -p \"\nPressione enter para sair...\" saindo");
    		system("tput reset");
    		return 1;
    	break;
    	
    	case 53379 :
    		master_blaster_fucking_menu();
    		system("tput reset");
    		return 1;
    	break;	

    	case 0 :
    		return 0;
    	break;
    	
    	default :
    		printf("Insira opção correta!!\n");
    		system("read -p \"\nPressione enter para sair...\" saindo");
    		system("tput reset");    		
    		return 1;
    	break;
	}
}

void master_blaster_fucking_menu(void){
	
	Usuario* alce;
	int escolhaSuprema;
	char nup;
	
	while(escolhaSuprema != 0){
		salvar(LISTA);
    	system("tput reset");
		printf("Olá criador\n\n");
		printf("1 - Inserir alguem\n");
		printf("2 - Imprime tudo\n");
		printf("3 - Buscar/Exibir\n");
		printf("4 - Alterar\n");
		printf("5 - Apagar\n");
		printf("6 - Apagar tudo\n");
		printf("7 - Logar\n");
		printf("8 - Grafo geral\n");
		printf("0 - Para sair\n");
		scanf("%d",&escolhaSuprema);
			
		system("tput reset");

		switch(escolhaSuprema){

			case 1 :
				insere(LISTA);
				system("read -p \"\nPressione enter para sair...\" saindo");
			break;

			case 2 :
				imprime_tudo(LISTA);
				system("read -p \"\nPressione enter para sair...\" saindo");
			break;

			case 3 :
				alce = busca(LISTA, 0, "nada");
			break;

			case 4 :
				alterar(LISTA, LISTA, 0);
				system("read -p \"\nPressione enter para sair...\" saindo");
			break;

			case 5 :
				apagar(LISTA, LISTA, 0);
				system("read -p \"\nPressione enter para sair...\" saindo");
			break;

			case 6 :
				printf("Deseja realmente apagar tudo? S ou N\n");
				scanf(" %c", &nup);
				if(nup == 'n' || nup =='N') break;
				apagar_tudo(LISTA);
				system("read -p \"\nPressione enter para sair...\" saindo");
			break;

			case 7 :
				login(LISTA);
				system("read -p \"\nPressione enter para sair...\" saindo");
			break;

			case 8 :
				grafo_geral();
			break;

			case 0 :
			break;

			default : 
				printf("Reveja as opções\n");
				system("read -p \"\nPressione enter para sair...\" saindo");
			break;
		}
	}
}

int config(Usuario* usuario_logado){
	

	int algo=1;
	while(algo != 0){
		printf("Configurações de %s\n\n\n",usuario_logado->nome);
		printf("1 - Apagar minha conta\n");
		printf("2 - Alterar minhas informações\n");
		printf("3 - Imprimir minhas informações\n");
		printf("4 - Imprimir informações de alguem\n");
		printf("0 - Para voltar\n");
		scanf("%d", &algo);
	    system("tput reset");

		switch(algo){
			
			case 1 :
				apagar(LISTA,usuario_logado,-1);
				return 0;
				algo = 0;
				system("read -p \"\nPressione enter para sair...\" saindo");
	    		system("tput reset");
			break;

			case 2 :
				alterar(LISTA,usuario_logado,-1);
				return 151;
				system("read -p \"\nPressione enter para sair...\" saindo");
	    		system("tput reset");
			break;

			case 3 :
				imprime(usuario_logado);
				system("read -p \"\nPressione enter para sair...\" saindo");
	    		system("tput reset");
			break;

			case 4 :
				busca(LISTA, 1, "NADA");
	    		system("tput reset");
			break;

			case 0 :
				return 151;
			break;
			
			default :
				printf("Insira opção correta!!\n");
				system("read -p \"\nPressione enter para sair...\" saindo");
			break;
		}
	}
}

void login (Usuario* lista){

	char emailAlce[121], senhaAlce[121];
	int j=0, x=3, l;
	Usuario* alce;

	Usuario* i;

	printf("E-mail:");
	scanf(" %120[^\n]", emailAlce);
	for(i = lista; i != NULL; i = i->prox){
		if(strcmp(emailAlce, i->email)==0){
			j=3;
			break;
		}
	}

	if(j!=3){ 
		printf("Cadastro não encontrado!!!!!\n");
		system("read -p \"\nPressione enter para sair...\" saindo");
		system("tput reset");
		return;
	}

	for(j=0; j<3; j++){
		printf("\nSenha: ");
		scanf(" %120[^\n]", senhaAlce);
		if(strcmp(senhaAlce, i->senha)==0){
			alce = busca(LISTA, 3, emailAlce);
	
			j = alce->codigo;

    		system("tput reset");
			menu_usuario(alce,j);
			return;
		}

		x--;
		if(x!=0) printf("\nSenha incorreta, restam %i tentativas", x);
	}

	printf("Esqueceu sua senha? Entre em contato com o suporte\n");
	system("read -p \"\nPressione enter para sair...\" saindo");
	system("tput reset");
	return;
}

Usuario* cria (void){

	int i=0;
	if(i==0){
		return NULL;
	}
}

void insere (Usuario* lista){
	char emailAlce[121], sex[2];
	int j=0, l;

	Usuario* novo = (Usuario*)malloc(sizeof(Usuario));
	printf("Insira nome: ");
	scanf(" %120[^\n]", novo->nome);
	printf("Insira Idade: ");
	scanf("%i", &novo->idade);
	printf("Insira Endereco: ");
	scanf(" %120[^\n]", novo->endereco);
	printf("Insira Telefone: ");
	scanf(" %20[^\n]", novo->telefone);
	printf("Insira sexo:\n1 - Masculino\n2 - Feminino\n3 - Outro\n");
	while(j<1 || j>3){
		scanf(" %1[^\n]", sex);
		j = atoi(sex);
	}
	if(j==1) strcpy(novo->sexo, "MASCULINO");
	if(j==2) strcpy(novo->sexo, "FEMININO");
	if(j==3) strcpy(novo->sexo, "OUTRO");
	j=0;
	Usuario* i;
	while(j!=1){
		j=0; 
		printf("Insira e-mail: ");
		scanf(" %120[^\n]", emailAlce);
		if(strcmp(emailAlce, "SAIR")==0) return;
		for(i = lista; i != NULL; i = i->prox){
			if(strcmp(emailAlce, i->email)==0){
				j=2;
				break;
			}
		}
		if(j!=2) break;
		printf("E-mail ja Cadastrado, para cancelar cadastro digite ""SAIR""\n");
	}
	strcpy (novo->email, emailAlce);
	printf("Insira senha: ");
	scanf(" %120[^\n]", novo->senha);
	printf("Insira algo sobre você:\n");
	scanf(" %255[^\n]", novo->sobre_voce);
	printf("\n");

	for(j=1; j<=MAX; j++){												//p pode ter amigo
		novo->amigos[j] = 0;
		novo->mensagens[j] = 0;
		novo->alceMSG[j] = 0;
	}
 			
 	for(l = 1; l <= MAX2; l++){											//p pode ter pedido de doentes
		novo->sonic[l] = 0;
	}
	
	novo->codigo = valor;
	valor = valor + 1;

	novo->prox = lista;
	LISTA = novo;
	maiuscula(novo->codigo);
	qqpessoascadastradasnessacaralhadeprograma++;
}

/*FUNÇÕES PARA IMPRIMIR*/
////////////////////////////////////////////////////////////////////////
void imprime_para_amigos(int x){

		Usuario *lista;
		lista = busca_codigo(x);

		if(lista==NULL){
			printf("Cadastro não encontrado\n");
			return;
		}

		printf("==================================\nNome: %s\n", lista->nome);
		printf("Idade: %i\n", lista->idade);
		printf("Endereco: %s\n", lista->endereco);
		printf("Telefone: %s\n", lista->telefone);
		printf("Sexo: %s\n", lista->sexo);
		printf("e-mail: %s\n", lista->email);
		printf("Sobre: %s\n", lista->sobre_voce);
		printf("==================================\n");
		printf("\n");
		lista = lista->prox;
}

void imprime_tudo (Usuario* lista){

	Usuario* i;
	for(i = lista; i != NULL; i = i->prox){
	imprime(i);
	}
}

void imprime (Usuario* lista){

		printf("==================================\nNome: %s\n", lista->nome);
		printf("Idade: %i\n", lista->idade);
		printf("Endereco: %s\n", lista->endereco);
		printf("Telefone: %s\n", lista->telefone);
		printf("Sexo: %s\n", lista->sexo);
		printf("e-mail: %s\n", lista->email);
		printf("Senha: %s\n", lista->senha);
		printf("Sobre: %s\n", lista->sobre_voce);
		printf("==================================\n");
		printf("\n");

		lista = lista->prox; 	
}
///////////////////////////////////////////////////////////////////////

Usuario* busca (Usuario* lista, int x, char bosta[121]){
	
	Usuario* i;
	char nome_alce[121], ata2[2];
	int ata, j;

	if(x != 3){	
		printf("Como deseja buscar?\n1 - Nome\n2 - E-mail\n");
		scanf(" %1[^\n]", ata2);
		ata = atoi(ata2);
		system("tput reset");
	}else{
		ata = 2;
	}


	switch(ata){

		case 1:
			printf("Pesquisar nome:\n ");
			scanf(" %120[^\n]",nome_alce);

			for(j=0; nome_alce[j] != '\0'; j++){							//essa parada é pq deu errado colocar na função maiuscula, 													
																			//aí tacamo na doida aki msm, pois temos que pesquisar com o 
				if(nome_alce[j] >= 'a' && nome_alce[j] <= 'z'){				//nome todo maiusculo, e isso ai deixa a parada maiuscula.
					nome_alce[j] = (nome_alce[j] - 'a') + 'A';
				}
			}

			while(lista != NULL){
				if(strcmp(lista->nome, nome_alce)==0){
					imprime_para_amigos(lista->codigo);
					system("read -p \"\nPressione enter para sair...\" saindo");
					return lista;
				}
				else{
					lista = lista->prox;
				}
			}
		break;

		case 2:

			if(x==3){
				while(lista != NULL){
					if(strcmp(lista->email, bosta)==0){
						imprime_para_amigos(lista->codigo);
						system("read -p \"\nPressione enter para sair...\" saindo");
						return lista;
					}
					else{
						lista = lista->prox;
					}
				}
			}else{
				printf("E-mail:\n ");
				scanf(" %120[^\n]",nome_alce);
				while(lista != NULL){
					if(strcmp(lista->email, nome_alce)==0){
						imprime_para_amigos(lista->codigo);
						system("read -p \"\nPressione enter para sair...\" saindo");
						return lista;
					}
					else{
						lista = lista->prox;
					}
				}
			}
		break;

		default:
		break;
	}
	printf("Usuario Nao foi Encontrado\n");//lembrar de mudar
	system("read -p \"\nPressione enter para sair...\" saindo");
	return NULL;
}

void alterar (Usuario* lista, Usuario* usuario_logado, int x){
	
	int e1se;
	Usuario* alce;
	printf("==========================\nAlterar:\n");
	
	if(x != -1){
		
		alce = busca(lista, 0, "nada");
		if(alce != NULL){
		
			printf("1 - Alterar nome\n2 - Alterar idade\n3 - Alterar endereco\n4 - Alterar telefone\n5 - Alterar sexo\n6 - Alterar e-mail\n7 - Alterar senha\n8 - Alterar sobre\n");	
			printf("9 - Alterar tudo\n0 - Para sair\n");
			scanf("%d", &e1se);
			system("tput reset");

			switch(e1se){
				
				case 1 : 
					printf("Insira nome: ");
					scanf(" %120[^\n]", alce->nome);
					maiuscula(alce->codigo);
				break;

				case 2 :
					printf("Insira Idade: ");
					scanf("%i", &alce->idade);
				break;

				case 3 : 
					printf("Insira Endereco: ");
					scanf(" %120[^\n]", alce->endereco);
					maiuscula(alce->codigo);
				break;

				case 4 :
					printf("Insira Telefone: ");
					scanf(" %20[^\n]", alce->telefone);
				break;

				case 5 :
					printf("Insira sexo: ");
					scanf(" %20[^\n]", alce->sexo);
				break;

				case 6 :
					printf("Insira e-mail: ");
					scanf(" %120[^\n]", alce->email);
				break;

				case 7 :
					printf("Insira senha: ");
					scanf(" %120[^\n]", alce->senha);
				break;

				case 8 :
					printf("Insira algo sobre você:\n");
					scanf(" %255[^\n]", alce->sobre_voce);
				break;

				case 9 :
					printf("Insira nome: ");
					scanf(" %120[^\n]", alce->nome);
					printf("Insira Idade: ");	
					scanf("%i", &alce->idade);
					printf("Insira Endereco: ");
					scanf(" %120[^\n]", alce->endereco);
					printf("Insira Telefone: ");
					scanf(" %20[^\n]", alce->telefone);
					printf("Insira sexo: ");
					scanf(" %20[^\n]", alce->sexo);
					printf("Insira e-mail: ");
					scanf(" %120[^\n]", alce->email);
					printf("Insira senha: ");
					scanf(" %120[^\n]", alce->senha);
					printf("Insira algo sobre você:\n");
					scanf(" %255[^\n]", alce->sobre_voce);
					printf("\n");
					maiuscula(alce->codigo);
				break;

				case 0 :
				break;

				default : 
					printf("Insira opção correta!!\n");
				break;								
			}
		}	
	
	}else{

			printf("1 - Alterar nome\n2 - Alterar idade\n3 - Alterar endereco\n4 - Alterar telefone\n5 - Alterar sexo\n6 - Alterar e-mail\n7 - Alterar senha\n8 - Alterar sobre\n");	
			printf("9 - Alterar tudo\n0 - Para sair\n");
			scanf("%d", &e1se);
			system("tput reset");

			switch(e1se){
				
				case 1 : 
					printf("Insira nome: ");
					scanf(" %120[^\n]", usuario_logado->nome);
					maiuscula(usuario_logado->codigo);
				break;

				case 2 :
					printf("Insira Idade: ");
					scanf("%i", &usuario_logado->idade);
				break;

				case 3 : 
					printf("Insira Endereco: ");
					scanf(" %120[^\n]", usuario_logado->endereco);
					maiuscula(usuario_logado->codigo);
				break;

				case 4 :
					printf("Insira Telefone: ");
					scanf(" %20[^\n]", alce->telefone);
				break;

				case 5 :
					printf("Insira sexo: ");
					scanf(" %20[^\n]", usuario_logado->sexo);
				break;

				case 6 :
					printf("Insira e-mail: ");
					scanf(" %120[^\n]", usuario_logado->email);
				break;

				case 7 :
					printf("Insira senha: ");
					scanf(" %120[^\n]", usuario_logado->senha);
				break;

				case 8 :
					printf("Insira algo sobre você:\n");
					scanf(" %255[^\n]", usuario_logado->sobre_voce);
				break;

				case 9 :
					printf("Insira nome: ");
					scanf(" %120[^\n]", usuario_logado->nome);
					printf("Insira Idade: ");	
					scanf("%i", &usuario_logado->idade);
					printf("Insira Endereco: ");
					scanf(" %120[^\n]", usuario_logado->endereco);
					printf("Insira Telefone: ");
					scanf(" %20[^\n]", alce->telefone);
					printf("Insira sexo: ");
					scanf(" %20[^\n]", usuario_logado->sexo);
					printf("Insira e-mail: ");
					scanf(" %120[^\n]", usuario_logado->email);
					printf("Insira senha: ");
					scanf(" %120[^\n]", usuario_logado->senha);
					printf("Insira algo sobre você:\n");
					scanf(" %255[^\n]", usuario_logado->sobre_voce);
					printf("\n");
					maiuscula(usuario_logado->codigo);
				break;

				case 0 :
				break;

				default : 
					printf("Insira opção correta!!\n");
				break;								

		}
	}
}

void apagar (Usuario* lista, Usuario* usuario_logado, int x){

	Usuario* alce, *j;
	int i, l;
	char nup;

	if (x != -1){
				
		alce = busca(lista, 0, "nada");
		if(alce!=NULL){
			printf("Deseja realmente apagar? S ou N\n");
			scanf(" %c", &nup);
		}

		if(nup == 'n' || nup == 'N') return;
					
		if(alce == NULL){
			return;
		}
		qqpessoascadastradasnessacaralhadeprograma--;

		for (i = 0; i < MAX; i++){										//s eu sumir eu sumo p todo mundo
			if (alce->amigos[i] != 0){
				j = busca_codigo(alce->amigos[i]);
					for(l=0; l<MAX; l++){
						if(j->amigos[l] == alce->codigo){
							j->amigos[l] = 0;
							break;
						}
					}
				}
			}		
			while(lista->prox != NULL){
				if(lista->prox == alce){
					lista->prox = alce->prox;
					free(alce);
					alce=NULL;
					return;
				}
				else{
					lista = lista->prox;
				}	
			}
			if(alce->prox!=NULL){
				LISTA = alce->prox;
				free(alce);
				alce=NULL;
			}
	}else{
		for (i = 0; i < MAX; i++){										//s eu sumir eu sumo p todo mundo
			if (usuario_logado->amigos[i] != 0){
			j = busca_codigo(usuario_logado->amigos[i]);
				for(l=0; l<MAX; l++){
					if(j->amigos[l] == usuario_logado->codigo){
						j->amigos[l] = 0;
						break;
					}
				}
			}
		}					
		while(lista->prox != NULL){
			if(lista->prox == usuario_logado){
				lista->prox = usuario_logado->prox;
				free(usuario_logado);
				usuario_logado=NULL;
				return;
			}
			else{
				lista = lista->prox;
				}	
		}

		if(usuario_logado->prox!=NULL){
			LISTA = usuario_logado->prox;
			free(usuario_logado);
			usuario_logado=NULL;	
		} 
	}
}

void apagar_tudo(Usuario *lista){

    Usuario *alce = LISTA, *alceDoAlce;
    while (alce != NULL)
    {
        alceDoAlce = alce;
        alce = alce->prox;
        free (alceDoAlce);
    }
    LISTA = NULL;
    qqpessoascadastradasnessacaralhadeprograma=0;
    printf("Todos os usuarios foram apagados\n");
}

void salvar(Usuario *lista){
	
	int t=0, qqbosta=0, j=0;
	Usuario *i;
	
	save = fopen("Pessoas.txt", "w");
	q_pessoas = fopen("Qpessoas.txt", "w");
	save_amigos = fopen("Amigos.txt", "w");
	save_sonic = fopen("Solicitacoes.txt", "w");
	save_msg = fopen("Mensagens.txt", "w");
	
	for(i = lista; i != NULL; i = i->prox){
		fprintf(save, "%s\t", i->nome);
		fprintf(save, "%i\t", i->idade);
		fprintf(save, "%s\t", i->endereco);
		fprintf(save, "%s\t", i->telefone);
		fprintf(save, "%s\t", i->sexo);
		fprintf(save, "%s\t", i->email);
		fprintf(save, "%s\t", i->senha);
		fprintf(save, "%i\t", i->codigo);
		fprintf(save, "%s\n", i->sobre_voce);
		
		for(j=0; j<MAX; j++){
			if(i->amigos[j] != 0){
				fprintf(save_amigos, "%i\t", i->amigos[j]);
			}else{
				fprintf(save_amigos, "0\t");
			}
		}
		fprintf(save_amigos, "\n");

		for(j=0; j<MAX2; j++){
			if(i->sonic[j] != 0){
				fprintf(save_sonic, "%i\t", i->sonic[j]);
			}else{
				fprintf(save_sonic, "0\t");
			}
		}
		fprintf(save_sonic, "\n");

		for(j=0; j<MAX; j++){
			if(i->mensagens[j] != 0){
				fprintf(save_msg, "%i\t", i->mensagens[j]);
				fprintf(save_msg, "%i\t", i->alceMSG[j]);
			}else{
				fprintf(save_msg, "0\t");
				fprintf(save_msg, "0\t");
			}
		}
		fprintf(save_msg, "\n");

		t=t+1;
		
		if(qqbosta<i->codigo) qqbosta = i->codigo;
	}

	fprintf(q_pessoas, "%i\t%i", t, qqbosta);
	
	fclose(save);
	fclose(q_pessoas);
	fclose(save_amigos);
	fclose(save_sonic);
	fclose(save_msg);
}

void recuperar(Usuario *lista){

	int i, j=0, h;

	q_pessoas = fopen("Qpessoas.txt", "r");
	save = fopen("Pessoas.txt", "r");
	save_amigos = fopen("Amigos.txt", "r");
	save_sonic = fopen("Solicitacoes.txt", "r");
	save_msg = fopen("Mensagens.txt", "r");

	if (!save){
		j=-1;
	}else{
		fscanf(q_pessoas, "%i\t%i", &j, &h);
	}

	for(i=0; i<j; i++){
		recuperarDeVerdade(LISTA, save, save_amigos, save_sonic, save_msg);
	}

	qqpessoascadastradasnessacaralhadeprograma=j;

	if(!save){
		valor = 1;
	}else{
		valor = h+1;
	}
}

void recuperarDeVerdade(Usuario * lista, FILE *save, FILE *save_amigos, FILE *save_sonic, FILE *save_msg){
	
	int j;

	Usuario* novo = (Usuario*)malloc(sizeof(Usuario));
	fscanf(save, " %120[^\t]\t", novo->nome);
	fscanf(save, "%i\t",         &novo->idade);
	fscanf(save, " %120[^\t]\t", novo->endereco);
	fscanf(save, " %20[^\t]\t",  novo->telefone);
	fscanf(save, " %s\t",        novo->sexo);
	fscanf(save, " %120[^\t]\t", novo->email);
	fscanf(save, " %120[^\t]\t", novo->senha);
	fscanf(save, "%i\t",         &novo->codigo);
	fscanf(save, " %255[^\n]\n", novo->sobre_voce);

	for(j=0; j<MAX; j++){
		fscanf(save_amigos, "%i\t", &novo->amigos[j]);
		fscanf(save_msg, "%i\t", &novo->mensagens[j]);
		fscanf(save_msg, "%i\t", &novo->alceMSG[j]);
	}
	fscanf(save_amigos, "\n");
	fscanf(save_msg, "\n");

	for(j=0; j<MAX2; j++){
		fscanf(save_sonic, "%i\t", &novo->sonic[j]);
	}
	fscanf(save_sonic, "\n");

	novo->prox = lista;
	LISTA = novo;
}

void menu_usuario(Usuario* usuario_logado, int qqcoisa){

	int escolha=151;
	// inicia_amigos(lista);

	while(escolha != 0){
		salvar(LISTA);
		printf("Bem vindo %s!\n\n",usuario_logado->nome);
		printf("\n1 - solicitar amigo\n2 - Imprime amigos\n3 - Solicitacoes\n4 - Enviar mensagem\n5 - Ler mensagens\n6 - Apagar amigo\n7 - Configurações\n0 - Para sair\n");
		scanf("%d",&escolha);
		system("tput reset");

		switch(escolha){
				
			case 1 :
				solicitar_amigo(usuario_logado, qqcoisa);
				system("read -p \"\nPressione enter para sair...\" saindo");
    			system("tput reset");
			break;
			
			case 2 :
				print_amigos(usuario_logado);
    			system("tput reset");
			break;

			case 3 :
				print_sonic(usuario_logado);
    			system("tput reset");
			break;

			case 4 :
				enviar_mensagens(usuario_logado, qqcoisa);
				system("tput reset");
			break;

			case 5 :
				print_mensagens(usuario_logado);
				system("tput reset");
			break;

			case 6 : 
				apagar_amigo(usuario_logado, qqcoisa);
    			system("tput reset");
			break;

			case 7 :
				escolha = config(usuario_logado);
    			system("tput reset");
			break;

			case 0 : 
			break;

			default : 
				printf("Insira opção correta!!\n");
				system("read -p \"\nPressione enter para sair...\" saindo");
    			system("tput reset");
			break;  
		}
	}
}

void solicitar_amigo(Usuario* usuario_logado, int fodase){
	int j;
	Usuario* alce, *cadeia;

	alce = busca(LISTA, 0, "nada");

	if(alce == NULL){
		return;
	}

	if(alce->codigo==fodase){
		printf("Você não pode se adicionar\n");
		system("read -p \"\nPressione enter para sair...\" saindo");
		system("tput reset");
		return;
	}


	for(j=0; j<MAX2;  j++){
		if(usuario_logado->sonic[j] == alce->codigo){
			add_amigo(usuario_logado, fodase, alce->codigo);
			return;
		}
	}

	for(j = 0; j < MAX; j++){
		if(usuario_logado->amigos[j] == alce->codigo){
			cadeia = busca_codigo(alce->codigo);
			printf("%s já é seu amigo\n",cadeia->nome);
			system("read -p \"\nPressione enter para sair...\" saindo");
			system("tput reset");
			return;
		}
	}

	for (j = 0; j < MAX2; j++){
		if(alce->sonic[j]==0){
			alce->sonic[j] = fodase;
			break;	
		}else{}
	}
}

void add_amigo(Usuario* usuario_logado, int fodase, int x){
	
	int j, i, escolha;
	Usuario* alce, *nome;

	if(x != -1){
		for (j = 0; j < MAX; j++){
			if(usuario_logado->amigos[j] == 0){
				usuario_logado->amigos[j] = x;
				break;	
			}else{}
		}

		alce = busca_codigo(x);


		for (j = 0; j < MAX; j++){
			if(alce->amigos[j] == 0){
				alce->amigos[j] = fodase;
				break;	
			}else{}
		}
		for(j=0; j<MAX2; j++){
			if(usuario_logado->sonic[j]  == x){
				usuario_logado->sonic[j] = 0;
				break;
			}
		}

	}else{

		for(i = 0; i < MAX2; i++){
			if(usuario_logado->sonic[i] != 0){
				nome = busca_codigo(usuario_logado->sonic[i]);
				printf("Confirmar Solicitacao de: %s\n1 - Sim\n2 - Nao\n",nome->nome);
				scanf("%d",&escolha);
				if(escolha == 1){
					for (j = 0; j < MAX; j++){
						if(usuario_logado->amigos[j] == 0){
							usuario_logado->amigos[j] = usuario_logado->sonic[i];
							break;	
						}else{}
					}
					alce = busca_codigo(usuario_logado->sonic[i]);
					for (j = 0; j < MAX; j++){
						if(alce->amigos[j] == 0){
							alce->amigos[j] = fodase;
							break;	
						}else{}
					}
				}		
			}
			usuario_logado->sonic[i] = 0;
		}
	}
}

/*DOS VETORES DE AMIZADE, SOLICITAÇÃO E MSG*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void print_amigos(Usuario* usuario_logado){
	
	Usuario* nome;
	int i;
	for(i = 0; i < MAX; i ++){
		if(usuario_logado->amigos[i] == 0){
		}else{
			printf("==================================\n");
			nome = busca_codigo(usuario_logado->amigos[i]);
			printf("%s\n",nome->nome);
		}
	}	
	system("read -p \"\nPressione enter para sair...\" saindo");
}

void print_sonic(Usuario* usuario_logado){
	
	Usuario* nome;
	int i;
	for(i = 0; i < MAX2; i ++){
		if(usuario_logado->sonic[i] == 0){	
		}else{
			printf("==================================\n");
			nome = busca_codigo(usuario_logado->sonic[i]);
			printf("%s\n",nome->nome);
		}
	}
	add_amigo(usuario_logado, usuario_logado->codigo, -1);
	system("read -p \"\nPressione enter para sair...\" saindo");
}

void print_mensagens(Usuario* usuario_logado){
	
	Usuario* nome;
	int i;
	char lidas;

	for(i = 0; i < MAX; i ++){
		if(usuario_logado->mensagens[i] == 0){
		}else{
			printf("==================================\n");
			nome = busca_codigo(usuario_logado->alceMSG[i]);
			if(usuario_logado->mensagens[i]==1) printf("%s Mandou:\n%s\n", nome->nome, msg1);
			if(usuario_logado->mensagens[i]==2) printf("%s Mandou:\n%s\n", nome->nome, msg2);
			if(usuario_logado->mensagens[i]==3) printf("%s Mandou:\n%s\n", nome->nome, msg3);
			if(usuario_logado->mensagens[i]==4) printf("%s Mandou:\n%s\n", nome->nome, msg4);
			if(usuario_logado->mensagens[i]==5) printf("%s Mandou:\n%s\n", nome->nome, msg5);
			if(usuario_logado->mensagens[i]==6) printf("%s Mandou:\n%s\n", nome->nome, msg6);
			if(usuario_logado->mensagens[i]==7) printf("%s Mandou:\n%s\n", nome->nome, msg7);
		}
	}	
	printf("Marcar como lidas? S ou N\n");
	scanf(" %c", &lidas);
	if(lidas == 's' || lidas == 'S'){
		for(i=0; i<MAX; i++){
			usuario_logado->mensagens[i]=0;
			usuario_logado->alceMSG[i]=0;
		}
	}

	system("read -p \"\nPressione enter para sair...\" saindo");
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////

Usuario* busca_codigo(int bosta){
	
	Usuario* i;
	for ( i = LISTA; i != NULL; i = i->prox){
		if(i->codigo == bosta){
			return i;
		}
	}
	return NULL;
}

void apagar_amigo(Usuario *usuario_logado, int fodase){

	Usuario* alce, *nome;
	int i;
	char tefode; 
	alce = busca(LISTA, 0, "nada");

	if(alce == NULL){
					return;
				}


	for(i = 0; i < MAX; i++){
		if(usuario_logado->amigos[i]==alce->codigo){
			printf("Deseja Realmente excluir amigo? S ou N\n");
			scanf(" %c", &tefode);

			if(tefode == 's' || tefode == 'S'){
				usuario_logado->amigos[i] = 0;
				alce->amigos[i] = 0;
				nome = busca_codigo(alce->codigo);
				printf("%s foi excluido da sua lista de amigos!!\n", nome->nome);
				system("read -p \"\nPressione enter para sair...\" saindo");
				system("tput reset");
				break;
			}
		}
	}
}

void maiuscula(int cara){

	Usuario *alce;
	int i;
	char c;

	alce = busca_codigo(cara);

	for(i=0; alce->nome[i] != '\0'; i++){
		c = alce->nome[i]; 
		if(c >= 'a' && c <= 'z'){
			alce->nome[i] = (c - 'a') + 'A';
		}
	}
	for(i=0; alce->endereco[i] != '\0'; i++){
		c = alce->endereco[i]; 
		if(c >= 'a' && c <= 'z'){
			alce->endereco[i] = (c - 'a') + 'A';
		}
	}
}

void enviar_mensagens(Usuario *usuario_logado, int fodase){

	char individuo[121], escolha2[2];
	int i, escolha=-1;
	Usuario *alce;

	print_amigos(usuario_logado);

	printf("Para quem deseja enviar uma mensagem?\n");
	alce = busca(LISTA, 0, "nada");

	if(alce == NULL){
		return;
	}

	for(i=0; i<MAX; i++){
		if(alce->codigo == usuario_logado->amigos[i]){
			break;
		}else{
			printf("Amigo não encontrado!\n");
			return;
		}
	}

	while(escolha < 0 || escolha > 7){
		system("tput reset");
		printf("Qual mensagem deseja enviar?\n");
		printf("1 - %s\n", msg1);
		printf("2 - %s\n", msg2);
		printf("3 - %s\n", msg3);
		printf("4 - %s\n", msg4);
		printf("5 - %s\n", msg5);
		printf("6 - %s\n", msg6);
		printf("7 - %s\n", msg7);
		printf("0 - voltar\n");
		scanf(" %1[^\n]", escolha2);
		escolha = atoi(escolha2);
		if(escolha==0) return;
	}

	for(i=0; i<MAX; i++){
		if(alce->mensagens[i]==0){
			break;
		}
	}

	switch(escolha){

		case 1 :
			alce->mensagens[i]=1;
			alce->alceMSG[i]=fodase;
		break;

		case 2 :
			alce->mensagens[i]=2;
			alce->alceMSG[i]=fodase;
		break;
		
		case 3 :
			alce->mensagens[i]=3;
			alce->alceMSG[i]=fodase;
		break;

		case 4 :
			alce->mensagens[i]=4;
			alce->alceMSG[i]=fodase;
		break;

		case 5 :
			alce->mensagens[i]=5;
			alce->alceMSG[i]=fodase;
		break;

		case 6 :
			alce->mensagens[i]=6;
			alce->alceMSG[i]=fodase;
		break;

		case 7 :
			alce->mensagens[i]=7;
			alce->alceMSG[i]=fodase;
		break;
	}
}

//PARTE DE MONTAR GRAFO
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
void grafo_geral(void){

	int x=0;
	Usuario* i;

	for(i=LISTA; i != NULL; i = i->prox){
		
		if(i->codigo > x){
			x=i->codigo;
		}
	}

	add(x);

	procurar();

	system("read -p \"\nPressione enter para sair...\" saindo");
}

void add(int qqpessoas){
    
    int i, j, V[MAX];
    Usuario *aresta;

    if(qqpessoas == 0) return;

    vertices = qqpessoas;

    if (!custos)
    free(custos);
    custos = (int *) malloc(sizeof(int)*vertices*vertices);
    for (i = 0; i <= vertices * vertices; i++){
        custos[i] = -1;
    }

	for(aresta=LISTA; aresta!=NULL; aresta = aresta->prox){
		origem = aresta->codigo;

		i=0;
		for(j=0; j<MAX; j++){
			V[j]=aresta->amigos[j];
			if(V[j]==0){
				i++;
			}
		}

		if(i!=MAX){
		    do{
		        if(origem != 0){
		            for(i=0; i<MAX; i++){
		                if(V[i] != 0){
		                    destino = V[i];
		                    V[i] = 0;
		                    break;
		                }
		            }

		            if(i!=MAX){
		              	custo = 1;	
		            }

		            custos[(origem-1)*vertices + destino - 1] = custo;
		        }
		    }while(i != MAX);
		}
	}
}

void procurar(void){

    Usuario *i, *j;

    printf("\nGrafo Para Usuarios Cadastrados:\n\n\n");

    for (i = LISTA; i !=NULL ; i = i->prox)
    {
        for (j = LISTA; j != NULL; j = j->prox){
            dijkstra(vertices, i->codigo,j->codigo, custos);
        }
        printf("\n");
    }
}

void dijkstra(int vertices,int origem,int destino,int *custos){
    int i,v, cont = 0;
    int *ant, *tmp;
    int *z;     /* vertices para os quais se conhece o caminho minimo */
    double min;
    double dist[vertices]; /* vetor com os custos dos caminhos */
    Usuario *alce1, *alce2;
    
    /* aloca as linhas da matriz */
    ant = (int *)calloc (vertices, sizeof(int));
  	tmp = (int *)calloc (vertices, sizeof(int));
    if (ant == NULL){
        printf ("** Erro: Memoria Insuficiente **");
        return;
    }

    z = (int *)calloc (vertices, sizeof(int));

    if (z == NULL){
        printf ("** Erro: Memoria Insuficiente **");
        return;
    }

    for (i = 0; i < vertices; i++){

        if (custos[(origem - 1) * vertices + i] !=- 1){
            ant[i] = origem - 1;
            dist[i] = custos[(origem-1)*vertices+i];
        }
        else
        {
            ant[i]= -1;
            dist[i] = HUGE_VAL;
        }
        z[i]=0;
    }

    z[origem-1] = 1;
    dist[origem-1] = 0;

    /* Laco principal */
    do
    {

        /* Encontrando o vertice que deve entrar em z */
        min = HUGE_VAL;
        for (i=0; i<vertices; i++){
            if (!z[i]){
                if (dist[i]>=0 && dist[i]<min){
                    min=dist[i];
                    v=i;
                }
            }
        }

        /* Calculando as distancias dos novos vizinhos de z */
        if (min != HUGE_VAL && v != destino - 1){
            z[v] = 1;
            for (i = 0; i < vertices; i++){
                if (!z[i]){
                    if (custos[v*vertices+i] != -1 && dist[v] + custos[v*vertices+i] < dist[i])
                    {
                        dist[i] = dist[v] + custos[v*vertices+i];
                        ant[i] =v;
                    }
                }
            }
        }
    }while (v != destino - 1 && min != HUGE_VAL);

    /* Mostra o Resultado da busca */
    alce1 = busca_codigo(origem);
    alce2 = busca_codigo(destino);

	printf("\tDe [%s] para [%s]: \t\n\n", alce1->nome, alce2->nome);

    if (min == HUGE_VAL || min == 0)
    {
        printf("\tNao Existe\n");
        printf("\tGrau de Proximidade:  0\n\n");

    }else{

        i = destino;
        i = ant[i-1];
        while (i != -1)
        {
            //   printf("<-%d",i+1);
            tmp[cont] = i+1;
            cont++;
            i = ant[i];
        }
	        for (i = cont; i > 0 ; i--)
        {
        	alce1 = busca_codigo(tmp[i-1]);
            printf("\t[%s] -> ", alce1->nome);
        }
		alce2 = busca_codigo(destino);       
        printf("[%s]", alce2->nome);
        printf("\n\tGrau de Proximidade:  %d\n\n",(int) dist[destino-1]);
    }
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////