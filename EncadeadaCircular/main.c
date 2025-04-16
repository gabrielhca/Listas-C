#include <stdio.h>
#include <stdlib.h>
#include "fuel.h"

int main() {
    Descriptor *starships;

    createList(&starships);
    capacityFuel(starships, 75);
    capacityFuel(starships, 100);
    capacityFuel(starships, 90);
    capacityFuel(starships, 120);
    capacityFuel(starships, 100);
    initialAmountFuel(starships);
    fuelSupply(starships);
}