//
// Created by henrique on 05/10/16.
//

#include "../../inc/structs.h"

int verticeEquals(vertice*, vertice*);

vertice *newVertice(int valor){
    vertice *v = (vertice*)malloc(sizeof(vertice));
    v->valor = valor;
    v->bool_marcardo = bool_FALSE;

    return v;
}