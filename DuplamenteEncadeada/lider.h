#ifndef _LIDER_H
#define _LIDER_H

typedef struct no {
    char nome[30];
    struct no* prox;
    struct no* ant;
} No;

typedef struct descritor {
    No *cauda;
    int qtd;
} Descritor;

Descritor* criaLista();
void inserirInicio(Descritor *lista, char *nome);
void removePonteiro(Descritor *lista, No *node);
No* percorreFrente(Descritor *lista, int k);
No* percorreTras(Descritor *lista, int k);
No* escolheLider(Descritor *lista, int k);
void liberaLista(Descritor *lista);

#endif