//
// Created by henrique on 08/09/16.
//
#include "../../inc/bibliotecas.h"
#include "grafo.h"

extern lista* newLista();
extern arco* newArco();
extern node *newNode(void*);

void printCaminho(lista *l);

void insArco(grafo *g, int antecessor, int sucessor, int custo){
    arco *arco = newArco();
    arco->antecessor = antecessor;
    arco->sucessor = sucessor;

    g->arcos->addNodeFinal(g->arcos, newNode(arco));
}

void printArcos(grafo *g){
    node *n = g->arcos->raiz;
    printf("\nArcos = {");
    while(n != NULL){
        arco *arco= n->elemento;
        printf("(%d, %d)", arco->antecessor, arco->sucessor);
        n = n->proximo;
        if(n != NULL) {
            printf(", ");
        }
    }
    printf("}\n");
}

void printCaminhos(lista *list){
    node *n = list->raiz;
    printf("\nCaminhos = {");
    while(n != NULL){
        lista *l= n->elemento;
        printCaminho(l);

        n = n->proximo;
        if(n != NULL) {
            printf(" | ");
        }
    }
    printf("}\n");
}

void printCaminho(lista *l) {
    node *n = l->raiz;
    while(n != NULL){
        arco *arco = n->elemento;
        printf("(%d, %d)", arco->antecessor, arco->sucessor);
        n = n->proximo;
        if(n != NULL) {
            printf(" -> ");
        }
    }
}

lista* obterAntecessores(lista *l, int antecessor) {
    lista *lista = newLista();
    node *n = l->raiz;
    while(n != NULL){
        arco *arco = n->elemento;
        if(arco->antecessor == antecessor) {
            lista->addNodeFinal(lista, newNode(arco));
        }
        n = n->proximo;
    }
    return lista;
}

lista* obterSucessores(lista *l, int sucessor) {
    lista *lista = newLista();
    node *n = l->raiz;
    while(n != NULL){
        arco *arco = n->elemento;
        if(arco->sucessor == sucessor){
            lista->addNodeFinal(lista, newNode(arco));
        }
        n = n->proximo;
    }
    return lista;
}

int buscarRelacao(lista *arestas, lista *antecessores, int sucessor) {
    node *n = antecessores->raiz;
    while(n != NULL){
        arco *arco= n->elemento;
        if(arco->sucessor == sucessor){
            return 1;
        }
        if(buscarRelacao(arestas, obterAntecessores(arestas, arco->sucessor), sucessor)){
            return 1;
        }
        n = n->proximo;
    }
    return 0;
}

lista *buscarRelacaoCompleta(lista *arestas, lista *antecessores, int sucessor, lista *auxiliar) {
    lista *caminhos = newLista();

    node *n = antecessores->raiz;
    while(n != NULL){
        arco *arco= n->elemento;
        auxiliar->addNodeFinal(auxiliar, newNode(arco));
        if(arco->sucessor == sucessor){
            caminhos->addNodeFinal(caminhos, newNode(auxiliar));
        }
        else {
            caminhos->addListaFinal(caminhos, buscarRelacaoCompleta(arestas, obterAntecessores(arestas, arco->sucessor), sucessor, auxiliar));
        }
        n = n->proximo;
    }
    return caminhos;
}

/**
 * Task 1-2: Verificar a existência de pelo menos um caminho entre dois vértices do Grafo
 * @param Grafo
 * @param Aresta contendo o vértice antecessor e o sucessor desejados
 * @return 1 para verdadeiro e 0 para falso
 */
int existeCaminho(grafo *g, arco *a){
    node *n = g->arcos->raiz;
    while(n != NULL){
        arco *arco= n->elemento;
        if(arco->arcoEquals(arco, a)){
            return 1;
        }
        n = n->proximo;
    }
    lista *sucessores = obterSucessores(g->arcos, a->sucessor);
    lista *antecessores = obterAntecessores(g->arcos, a->antecessor);
    if(sucessores->qtd == 0 || antecessores->qtd == 0){
        return 0;
    }
    return buscarRelacao(g->arcos, antecessores, a->sucessor);
}

/**
 * Task 3: Verificar a existência de um ciclo partindo de um vértice
 * @param Grafo
 * @param Vértice a ser utilizado como comparação
 * @return 1 para Verdadeiro e 0 para falso
 */
int existeCiclo(grafo *g, int v){
    lista *antecessores = obterAntecessores(g->arcos, v);
    return buscarRelacao(g->arcos, antecessores, v);
}

/**
 * Task 4: Exibir todos os caminhos entre os vértices V1 e V2 de um grafo que podeterciclos.
 * @param g Grafo
 * @param a Aresta
 */
void exibeCaminhos(grafo *g, arco *a){
    printCaminhos(buscarRelacaoCompleta(g->arcos, obterAntecessores(g->arcos, a->antecessor), a->sucessor, newLista()));
}