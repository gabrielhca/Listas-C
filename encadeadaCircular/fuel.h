#ifndef _FUEL_H 
#define _FUEL_H

typedef struct fuel{
    int capacityFuel;
    int amountFuel;
    struct fuel *next;
} Fuel;

typedef struct descriptor {
    Fuel *tail;
    int size;
} Descriptor;

Descriptor* createList(Descriptor **list);
void capacityFuel(Descriptor *list, int item);
void initialAmountFuel(Descriptor *list);
void fuelSupply(Descriptor *list);

#endif