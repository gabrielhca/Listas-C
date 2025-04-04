#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"

int main(){
    Aluno* cadastro = criarLista();
    int opcao;
    char nome[30];
    int notaPratica, notaTeorica;
    
    do {
        printf("\n\tCadastro de Alunos\t\n");
        printf("\nEscolha a opção desejada:\n\n");
        printf("1 - Inserir aluno.\n");
        printf("2 - Buscar aluno por nome.\n");
        printf("3 - Lista de alunos aprovados.\n");
        printf("4 - Remover aluno.\n");
        printf("5 - Sair do programa.\n");
        scanf("%d", &opcao);
        getchar(); // consome o '\n' deixado pelo scanf

        switch (opcao) {
            case 1:
                printf("\nNome do aluno: ");
                lerNome(nome, 30);

                printf("Nota prática (0 a 50): ");
                scanf("%d", &notaPratica);

                printf("Nota teórica (0 a 50): ");
                scanf("%d", &notaTeorica);

                Aluno info = { "", notaPratica, notaTeorica, NULL };
                strcpy(info.nome, nome);

                cadastro = inserirAluno(cadastro, info);
                printf("\nAluno %s inserido!\n", nome);
                break;

            case 2:
                printf("\nNome do aluno: ");
                lerNome(nome, 30);
                
                Aluno* alunoEncontrado = buscaAluno(cadastro, nome);
                break;

            case 3: {
                Aluno* aprovados = alunoAprov(cadastro);
                break;
            }

            case 4:
                printf("\nNome do aluno: ");
                lerNome(nome, 30);
                
                cadastro = removeAluno(cadastro, nome);
                break;

            case 5:
                printf("\nSaindo...\n");
                break;

            default:
                printf("\nOpção inválida! :(\n");
                break;
        }
    } while (opcao != 5);
    
    liberar(cadastro);
    return 0;
}