//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
void    addVertice(grafo*, node*);
void    printVertices(grafo*);
void    printGrafo(grafo*);

grafo *newGrafo(){
    grafo *g = (grafo*)malloc(sizeof(grafo));
    g->addVertice = addVertice;
    g->printVertices = printVertices;
    g->printGrafo = printGrafo;
    return g;
}