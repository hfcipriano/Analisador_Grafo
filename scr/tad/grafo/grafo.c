//
// Created by henrique on 08/09/16.
//
#include "../../inc/bibliotecas.h"
#include "grafo.h"

void addVertice(grafo *g, node* vertice){
    g->vertices->addNodeFinal(g->vertices, vertice);
}

void printVertices(grafo *g){
    node *n = g->vertices->raiz;
    printf("Vertices = (");
    while(n != NULL){
        vertice *vertice = n->elemento;
        printf("%s", (char*)vertice->valor);
        n = n->proximo;
        printf(", ");
    }
    printf(")");
    printf("\n");
}

void printGrafo(grafo *g){

}