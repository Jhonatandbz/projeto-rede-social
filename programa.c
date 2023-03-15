#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "alce.h"

Usuario* LISTA;

int main (void){
	
	system("tput reset");
	int x, i;
	LISTA = cria();
	// inicia_amigos(LISTA);
	printf("\tBEM VINDO AO ALCE...\n");

		for(i = 0; i<1000000000; i++){
			x = 0;
		}

    recuperar(LISTA);

	system("tput reset");

	for (i = 0 ; ; i++){
		
		system("tput reset");

		x = menu_login();

		if(x==0){
			break;
		}
	}

	printf("\tFECHANDO REDE...\n");

	for(i = 0; i<1000000000; i++){
			x = 0;
	}
	
	salvar(LISTA);
	system("tput reset");
}