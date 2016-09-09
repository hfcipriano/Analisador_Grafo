//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
int verticeEquals(vertice*, vertice*);
vertice *newVertice(char *valor){
    vertice *v = (vertice*)malloc(sizeof(vertice));
    v->valor = valor;
    v->verticeEquals = verticeEquals;
    return v;
}