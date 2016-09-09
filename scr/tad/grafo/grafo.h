//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
void    addVertice(grafo*, node*);
void    addAresta(grafo*, node*);
void    printVertices(grafo*);
void    printArestas(grafo*);
void    printGrafo(grafo*);

grafo *newGrafo(){
    grafo *g = (grafo*)malloc(sizeof(grafo));
    g->addVertice = addVertice;
    g->addAresta = addAresta;
    g->printVertices = printVertices;
    g->printArestas = printArestas;
    g->printGrafo = printGrafo;
    return g;
}