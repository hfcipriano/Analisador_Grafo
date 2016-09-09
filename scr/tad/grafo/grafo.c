//
// Created by henrique on 08/09/16.
//
#include "../../inc/bibliotecas.h"
#include "grafo.h"

void addVertice(grafo *g, node* vertice){
    g->vertices->addNodeFinal(g->vertices, vertice);
}

void addAresta(grafo *g, node* aresta){
    g->arestas->addNodeFinal(g->arestas, aresta);
}

void printVertices(grafo *g){
    node *n = g->vertices->raiz;
    printf("Vertices = {");
    while(n != NULL){
        vertice *vertice = n->elemento;
        printf("%s", (char*)vertice->valor);
        n = n->proximo;
        if(n != NULL) {
            printf(", ");
        }
    }
    printf("}");
    printf("\n");
}

void printArestas(grafo *g){
    node *n = g->arestas->raiz;
    printf("Arestas = {");
    while(n != NULL){
        aresta *aresta= n->elemento;
        //printf("(%s - ", (char*)aresta->valor);
        printf("(%s, %s)", (char*)aresta->antecessor->valor, (char*)aresta->sucessor->valor);
        n = n->proximo;
        if(n != NULL) {
            printf(", ");
        }
    }
    printf("}");
    printf("\n");
}

void printGrafo(grafo *g){
    //:TODO Implementar
}