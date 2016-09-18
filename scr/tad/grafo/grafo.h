//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
void    addAresta(grafo*, node*);
void    printArestas(grafo*);
int     existeCaminho(grafo*, aresta*);
int     existeCiclo(grafo*, vertice*);

grafo *newGrafo(){
    grafo *g = (grafo*)malloc(sizeof(grafo));
    g->addAresta = addAresta;
    g->printArestas = printArestas;
    g->existeCaminho = existeCaminho;
    g->existeCiclo = existeCiclo;
    return g;
}