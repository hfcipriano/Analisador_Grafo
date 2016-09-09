//
// Created by henrique on 08/09/16.
//
#include "../../inc/bibliotecas.h"
#include "grafo.h"

extern lista* newLista();
extern node *newNode(void*);

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

lista* obterAntecessores(lista *l, vertice *antecessor) {
    lista *lista = newLista();
    node *n = l->raiz;
    while(n != NULL){
        aresta *aresta = n->elemento;
        if(aresta->antecessor->verticeEquals(aresta->antecessor, antecessor)){
            lista->addNodeFinal(lista, newNode(aresta));
        }
        n = n->proximo;
    }
    return lista;
}

lista* obterSucessores(lista *l, vertice *sucessor) {
    lista *lista = newLista();
    node *n = l->raiz;
    while(n != NULL){
        aresta *aresta = n->elemento;
        if(aresta->sucessor->verticeEquals(aresta->sucessor, sucessor)){
            lista->addNodeFinal(lista, newNode(aresta));
        }
        n = n->proximo;
    }
    return lista;
}

int buscarRelacao(lista *arestas, lista *antecessores, vertice *sucessor) {
    node *n = antecessores->raiz;
    while(n != NULL){
        aresta *aresta= n->elemento;
        if(aresta->sucessor->verticeEquals(aresta->sucessor, sucessor)){
            return 1;
        }
        if(buscarRelacao(arestas, obterAntecessores(arestas, aresta->sucessor), sucessor)){
            return 1;
        }
        n = n->proximo;
    }
    return 0;
}

int existeCaminho(grafo *g, aresta *a){
    node *n = g->arestas->raiz;
    while(n != NULL){
        aresta *aresta= n->elemento;
        if(aresta->arestaEquals(aresta, a)){
            return 1;
        }
        n = n->proximo;
    }
    lista *sucessores = obterSucessores(g->arestas, a->sucessor);
    lista *antecessores = obterAntecessores(g->arestas, a->antecessor);
    if(sucessores->qtd == 0 || antecessores->qtd == 0){
        return 0;
    }
    return buscarRelacao(g->arestas, antecessores, a->sucessor);
}

