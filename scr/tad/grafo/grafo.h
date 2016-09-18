//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"

extern lista *newLista();
void    addAresta(grafo*, node*);
void    printArestas(grafo*);
int     existeCaminho(grafo*, aresta*);
int     existeCiclo(grafo*, vertice*);
void    exibeCaminhos(grafo*, aresta*);

grafo *newGrafo(){
    grafo *g = (grafo*)malloc(sizeof(grafo));
    g->arestas = newLista();
    g->addAresta = addAresta;
    g->printArestas = printArestas;
    g->existeCaminho = existeCaminho;
    g->existeCiclo = existeCiclo;
    g->exibeCaminhos = exibeCaminhos;
    return g;
}