//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"

vertice *newVertice(char *valor){
    vertice *v = (vertice*)malloc(sizeof(vertice));
    v->valor = valor;
    return v;
}