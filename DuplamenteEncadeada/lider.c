#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lider.h"

Descritor* criaLista(){ 
    Descritor *lista = (Descritor*)malloc(sizeof(Descritor));
    if (lista == NULL) return NULL;
    lista->cauda = NULL;
    lista->qtd = 0;
    return lista;
}

void inserirInicio(Descritor *lista, char *nome) {
    if (lista == NULL) return;

    No *novo = (No*)malloc(sizeof(No));
    if (novo == NULL) return;

    strcpy(novo->nome, nome);

    if (lista->qtd == 0) {
        novo->prox = novo;
        novo->ant = novo;
        lista->cauda = novo;
    } else {
        No *cabeca = lista->cauda->prox;
        novo->prox = cabeca;
        novo->ant = lista->cauda;
        cabeca->ant = novo;
        lista->cauda->prox = novo;
    }
    lista->qtd++;
}


void removePonteiro(Descritor *lista, No *p){
    if(lista == NULL) return;
    
    if(lista->qtd == 1){
        lista->cauda = NULL;
    } else {
        p->ant->prox = p->prox;
        p->prox->ant = p->ant;
        if (p == lista->cauda) {
            lista->cauda = p->ant;
        }
    }
    free(p);
    lista->qtd--;
}

No* percorreFrente(Descritor *lista, int k){
    if(lista == NULL) return NULL;
    No *atual = lista->cauda->prox;

    for(int i=0; i < k-1; i++) {
        atual = atual->prox;
    }
    printf("%s - Eliminado!\n", atual->nome);
    No *proximo = atual->prox;
    removePonteiro(lista, atual);
    return proximo;
}

No* percorreTras(Descritor *lista, int k){
    if(lista == NULL) return;
    No *atual = lista->cauda->prox; 

    for(int i=0; i < k-1; i++) {
        atual = atual->ant;
    }
    printf("%s - Eliminado!\n", atual->nome);
    No *proximo = atual->prox;
    removePonteiro(lista, atual);
    return proximo;
}

No* escolheLider(Descritor *lista, int k) {
    if (lista == NULL) return NULL;

    int cont = 0;
    No *atual = lista->cauda->prox;

    while (lista->qtd > 1) {
        if (cont % 2 == 0) {
            atual = percorreFrente(lista, k);
        } else {
            atual = percorreTras(lista, k);
        }
        cont++;
    }

    printf("O líder é: %s\n", lista->cauda->nome);
    return lista->cauda;
}

void liberaLista(Descritor *lista) {
    if (lista == NULL) return;

    while (lista->qtd > 0) {
        No *tmp = lista->cauda->prox;
        removePonteiro(lista, tmp);
    }

    free(lista);
}