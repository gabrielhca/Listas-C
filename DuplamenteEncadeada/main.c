#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lider.h"

int main() {
    Descritor *lista = criaLista();

    inserirInicio(lista, "Maria");
    inserirInicio(lista, "Fernando");
    inserirInicio(lista, "Livia");
    inserirInicio(lista, "Samuel");
    inserirInicio(lista, "Sonia");
    inserirInicio(lista, "Romeu");
    inserirInicio(lista, "Giovanna");

    srand(time(NULL));
    int K = rand() % (lista->qtd - 1) + 1;

    printf("K sorteado: %d\n", K);
    printf("\n=== Iniciando eleição ===\n");
    No *lider = escolheLider(lista, K);

    liberaLista(lista);
    return 0;
}
