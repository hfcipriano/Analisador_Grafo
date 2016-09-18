//
// Created by henrique on 08/09/16.
//
#include "../../inc/bibliotecas.h"
#include "grafo.h"

extern lista* newLista();
extern node *newNode(void*);

void addAresta(grafo *g, node* aresta){
    g->arestas->addNodeFinal(g->arestas, aresta);
}

void printArestas(grafo *g){
    node *n = g->arestas->raiz;
    printf("\nArestas = {");
    while(n != NULL){
        aresta *aresta= n->elemento;
        //printf("(%s - ", (char*)aresta->valor);
        printf("(%s, %s)", (char*)aresta->antecessor->valor, (char*)aresta->sucessor->valor);
        n = n->proximo;
        if(n != NULL) {
            printf(", ");
        }
    }
    printf("}\n");
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

/**
 * Task 1: Verificar a existência de pelo menos um caminho entre dois vértices do Grafo
 * @param Grafo
 * @param Aresta contendo o vértice antecessor e o sucessor desejados
 * @return 1 para verdadeiro e 0 para falso
 */
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

/**
 * Task 2: Verificar a existência de um ciclo partindo de um vértice
 * @param Grafo
 * @param Vértice a ser utilizado como comparação
 * @return 1 para Verdadeiro e 0 para falso
 */
int existeCiclo(grafo *g, vertice *v){
    lista *antecessores = obterAntecessores(g->arestas, v);
    return buscarRelacao(g->arestas, antecessores, v);
}