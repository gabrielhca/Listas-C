#include <stdio.h>
#include <stdlib.h>
#include "fuel.h"

Descriptor* createList(Descriptor **list){
    *list = (Descriptor*) malloc (sizeof(Descriptor));
    (*list)->tail = NULL;
    (*list)->size = 0;
    return *list;
}

void capacityFuel(Descriptor *list, int item){
    Fuel *starship = (Fuel*) malloc (sizeof(Fuel));
    if(starship == NULL) return;
    starship->capacityFuel = item;

    //para o primeiro item
    if(list->tail == NULL){
        //o primeiro item aponta para si proprio, circularidade
        starship->next = starship;
        //a cauda recebe o primeiro item
        list->tail = starship;
    }else{
        //o novo item aponta para onde a cauda apontava (primeiro item)
        starship->next = list->tail->next;
        // o antigo ultimo apontava para o primeiro
        // e agora passa a apontar para o novo ultimo
        list->tail->next = starship;
        //o ultimo item é atualizado com o novo item
        list->tail = starship;
    }

    list->size++;
}

void initialAmountFuel(Descriptor *list){
    Fuel *current = list->tail->next;
    for(int i=0; i<list->size; i++){
        printf("Informe a quantidade inicial de combustivel da %d° nave (Capacidade maxima: %d.):\n", i+1, current->capacityFuel);
        scanf("%d", &(current->amountFuel));
        current = current->next;
    }
    printf("Registrado completo!\n\n");
}

void fuelSupply(Descriptor *list) {
    printf("Iniciando abastecimento...\n\n");
    Fuel *current = list->tail->next;
    int load, fullTank = 0;
    printf("Quantidade de combustível por ciclo?: \n");
    scanf("%d", &load);

    do {
        if (current->amountFuel < current->capacityFuel) {
            current->amountFuel += load;
            if (current->amountFuel >= current->capacityFuel) {
                //evita overflow
                current->amountFuel = current->capacityFuel;
                fullTank++;
            }
        }
        current = current->next;
    } while (fullTank < list->size);

    printf("\nTodas as naves estão com o tanque cheio!\n");
}