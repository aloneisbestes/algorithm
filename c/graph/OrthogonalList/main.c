#include <stdio.h>
#include "OrthList.h"


int main() {
    GraphOrth g;

    CreateOrthList(&g);
    PrintOrthList(&g);

    DestroyRothList(&g);
    return 0;
}