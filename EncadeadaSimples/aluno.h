#ifndef _ALUNO_H
#define _ALUNO_H

typedef struct aluno {
    char nome[30];
    int notaPratica, notaTeorica;
    struct aluno* prox;
} Aluno;

Aluno* criarLista();
int listaVazia(Aluno* cadastro);
int somaNota(int a, int b);
Aluno* inserirAluno(Aluno* lista, Aluno info);
Aluno* buscaAluno(Aluno* cadastro, char* nome);
Aluno* alunoAprov(Aluno* cadastro);
Aluno* removeAluno(Aluno* cadastro, char* nome);
void lerNome(char* nome, int tam);
void liberar(Aluno *cadastro);

#endif