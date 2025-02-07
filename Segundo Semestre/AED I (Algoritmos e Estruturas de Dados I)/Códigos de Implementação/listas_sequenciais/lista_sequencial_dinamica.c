#include <stdio.h>
#include <stdlib.h>

#include "lista_sequencial_dinamica.h"

ListaSequencial * cria_lista(int capacidade){

	ListaSequencial * lista =  (ListaSequencial *) malloc (sizeof(ListaSequencial));
	lista->a = (Elemento *) malloc ((capacidade + 1) * sizeof(Elemento));
	lista->capacidade = capacidade;
	lista->livre = 0;

	return lista;
}

void destroi_lista(ListaSequencial * lista){

	free(lista->a);
	free(lista);
}

int tamanho(ListaSequencial * lista){

	return lista->livre;
}

void imprime(ListaSequencial * lista){

	int i;

	printf("Lista:");

	for(i = 0; i < lista->livre; i++){

		printf(" %ld", lista->a[i]);
	}

	printf("\n");
}

int busca(ListaSequencial * lista, Elemento e){

	int i;

	lista->a[lista->livre] = e;

	for(i = 0; lista->a[i] != e; i++);

	return (i < lista->livre) ? i : -1;
}

Boolean insere(ListaSequencial * lista, Elemento e, int indice){

	int i;

	if(lista->livre < lista->capacidade && indice >= 0 && indice <= lista->livre){

		for(i = lista->livre; i > indice; i--){

			lista->a[i] = lista->a[i - 1];
		}

		lista->a[indice] = e;
		lista->livre++;

		return TRUE;
	}

	return FALSE;
}

Boolean remove_elemento(ListaSequencial * lista, Elemento e){

	int i;
	int indice = busca(lista, e);

	if(indice >= 0) {

		lista->livre--;

		for(i = indice; i < lista->livre; i++){

			lista->a[i] = lista->a[i + 1];
		}

		return TRUE;
	}

	return FALSE;
}

