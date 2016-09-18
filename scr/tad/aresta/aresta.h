//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
int arestaEquals(aresta*, aresta*);
aresta *newAresta(vertice *vertice1, vertice *vertice2){
    aresta *a = (aresta*)malloc(sizeof(aresta));
    a->antecessor = vertice1;
    a->sucessor = vertice2;
    a->arestaEquals = arestaEquals;
    return a;
}