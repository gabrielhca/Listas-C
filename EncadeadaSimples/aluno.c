#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

Aluno* criarLista() {
    return NULL;
}

int listaVazia(Aluno* cadastro){
    if(cadastro == NULL){
        return 1;
    }
    return 0;
}

int somaNota(int a, int b){
    int nota = a + b;
    return nota;
}

//Aluno info não tem ponteiro pq apenas carrega informações e não modifica diretamente as informações dentro da estrutura original
Aluno* inserirAluno(Aluno* cadastro, Aluno info){
    Aluno* novo;
    novo = (Aluno*) malloc(sizeof(Aluno));
    if (novo == NULL) return NULL;
    *novo = info; //passa todos os valores;
    novo->prox = cadastro;
    return novo;
}

Aluno* buscaAluno(Aluno* cadastro, char* nome){
    if(listaVazia(cadastro)){
        return NULL;
    }
    Aluno* atual = cadastro;
    while(atual != NULL){
        if(strcmp(atual->nome, nome) == 0){
            int nota = somaNota(atual->notaPratica, atual->notaTeorica);
            printf("Aluno: %s\nNota: %d\n", atual->nome, nota);
            return atual;
        }
        atual = atual->prox;
    }
    
    printf("Aluno não cadastrado!\n");
    return NULL;
}

Aluno* alunoAprov(Aluno* cadastro) {
    if (listaVazia(cadastro)) {
        printf("Nenhum aluno na lista.\n");
        return NULL;
    }

    Aluno* atual = cadastro;
    int contAprovados = 0;

    printf("Alunos aprovados:\n");
    while (atual != NULL) {
        int notaTotal = somaNota(atual->notaPratica, atual->notaTeorica);
        if (notaTotal >= 70) {
            printf("- %s (Nota: %d)\n", atual->nome, notaTotal);
            contAprovados++;
        }
        atual = atual->prox;
    }

    if (contAprovados == 0) {
        printf("Nenhum aluno aprovado.\n");
    }

    return cadastro;
}

Aluno* removeAluno(Aluno* cadastro, char* nome){
    if(listaVazia(cadastro)){
        return NULL;
    }
    
    Aluno* atual = cadastro;
    Aluno* anterior = NULL;
    
    while(atual != NULL){
        if(strcmp(atual->nome, nome) == 0){
            if(anterior == NULL){
                cadastro = atual->prox;
            } else {
                anterior->prox = atual->prox;
            }
            free(atual);
            printf("Aluno '%s' removido com sucesso!\n", nome);
            return cadastro;
        }
        anterior = atual;
        atual = atual->prox;
    }
    printf("Aluno não cadastrado!\n");
    return cadastro;
}

void lerNome(char* nome, int tam) {
    fgets(nome, tam, stdin);
    nome[strcspn(nome, "\n")] = '\0'; // remove o '\n' do final
}

void liberar(Aluno *cadastro){
    Aluno* atual = cadastro;
    while (atual != NULL) {
        Aluno* aux = atual;
        atual = atual->prox;
        free(aux);
    }
}





