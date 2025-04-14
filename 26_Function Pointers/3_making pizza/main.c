#include <stdio.h>

void thinCrust()
{
    printf("Making thin crust \n");
}
void stuffedCrust()
{
    printf("Making stuffed crust \n");
}
void neapolitan()
{
    printf("Making neapolitan \n");
}

void spicyRedSauce()
{
    printf("Making spicy sauce \n");
}
void tomatoSauce()
{
    printf("Making tomato sauce \n");
}

void cheddarCheese()
{
    printf("Adding cheddar cheese \n");
}
void goatCheese()
{
    printf("Adding goat cheese \n");
}

void createPizza(void (*makeDough)(), void (*makeSauce)(), void (*addCheese)())
{
    makeDough();
    makeSauce();
    addCheese();
}

int main() {

    printf("Pizza1: \n");
    createPizza(thinCrust, tomatoSauce, cheddarCheese);
    printf("\n=============\n\n");
    printf("Pizza2: \n");
    createPizza(stuffedCrust, spicyRedSauce, cheddarCheese);

    return 0;
}
