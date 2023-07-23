#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArvoreBinariaBusca.h"

struct arvore{
	int chave;
	void* item;
	struct arvore* esq;
	struct arvore* dir;
};

Arvore inicializar(){
	Arvore a = (Arvore)malloc(sizeof(Arvore));
	a = NULL;
	return a;
}

Arvore destruir(Arvore a){
	if(a!=NULL){
		destruir(a->esq);
		destruir(a->dir);
		free(a->item);
		free(a);
	}
	return NULL;
}

Arvore inserirAbb(Arvore a, int chave, void* item, int sizeItem){
	if(a==NULL){
		Arvore novo = (Arvore)malloc(sizeof(struct arvore));
		novo->chave = chave;
		novo->dir = NULL;
		novo->esq = NULL;
		novo->item = malloc(sizeItem);
        memcpy(novo->item, item, sizeItem);
		return novo;
	} else{
		if(chave<=a->chave){
			a->esq=inserirAbb(a->esq, chave, item, sizeItem);
		} else{
			a->dir=inserirAbb(a->dir, chave, item, sizeItem);
		}
		return a;
	}
}

Arvore removerAbb(Arvore a, int chave, int sizeItem){
	if(a!=NULL){
		if(a->chave==chave){
			if(a->esq == NULL && a->dir == NULL){ //se os dois filhos forem nulos
				a=destruir(a);
			} else if(a->esq == NULL || a->dir == NULL){ //se um dos filhos forem nulos
				Arvore aux;
				aux = a;
				if(a->dir == NULL){ //filho direita
					a = a->esq;
					free(aux);
				} else{ //filho esquerda
					a = a->dir;
					free(aux);
				}
			} else{
				Arvore aux;
				aux = a->esq;
				while(aux->dir != NULL){
					aux = aux->dir;
				}
				memcpy(a->item, aux->item, sizeItem);
				a->chave = aux->chave;
				a->esq = removerAbb(a->esq, aux->chave, sizeItem);
			}
		} else if(chave < a->chave){ //aproveitando ordenação
			a->esq = removerAbb(a->esq, chave, sizeItem);
		} else{
			a->dir = removerAbb(a->dir, chave, sizeItem);
		}
	}
	return a;
}

int existe(Arvore a, int chave){
	if(a!=NULL){
		if(a->chave == chave){
			return 1;

		} else if(chave < a->chave){
			return existe(a->esq, chave);
		} else{
			return existe(a->dir, chave);
		}
	} else{
		return 0;
	}
}

int buscar(Arvore a, int chave, void* item, int sizeItem){
	if(existe(a, chave)){
		if(chave == a->chave){
			memcpy(item, a->item, sizeItem);
			return 1;
		} else if(chave < a->chave){
			 return buscar(a->esq, chave, item, sizeItem);
		} else{
			return buscar(a->dir, chave, item, sizeItem);
		}
	} else{
		return 0;
	}
}

int altura(Arvore a){
	if(a != NULL){
		int he = altura(a->esq);
		int hd = altura(a->dir);
		if(he>hd){
			return he+1;
		} else{
			return hd+1;
		}
	} else{
		return 0;
	}
}

void imprimirAux(Arvore a, int nivel){
	if(a==NULL){
		return;
	} else if(nivel==1){
		printf("%d\n", a->chave);
	} else{
		imprimirAux(a->esq, nivel-1);
		imprimirAux(a->dir, nivel-1);
	}
}

void imprimirLargura(Arvore a){
	if(a!=NULL){
		int i;
		for(i=1; i<=altura(a); i++){
			imprimirAux(a, i);
		}
	}	
}
