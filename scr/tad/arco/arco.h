//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
int arcoEquals(arco*, arco*);

arco *newArco(int antecessor, int sucessor){
    arco *a = (arco*)malloc(sizeof(arco));
    a->antecessor = antecessor;
    a->sucessor = sucessor;
    a->arcoEquals = arcoEquals;
    return a;
}