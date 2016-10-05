//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
int arcoEquals(arco*, arco*);

arco *newArco(int antecessor, int sucessor, int custo){
    arco *a = (arco*)malloc(sizeof(arco));
    a->antecessor = antecessor;
    a->sucessor = sucessor;
    a->custo = custo;
    a->arcoEquals = arcoEquals;
    return a;
}