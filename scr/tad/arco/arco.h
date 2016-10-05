//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"

extern vertice *newVertice(int);

int arcoEquals(arco*, arco*);

arco *newArco(int antecessor, int sucessor){
    arco *a = (arco*)malloc(sizeof(arco));
    a->antecessor = newVertice(antecessor);
    a->sucessor = newVertice(sucessor);
    a->arcoEquals = arcoEquals;
    return a;
}