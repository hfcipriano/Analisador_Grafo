//
// Created by henrique on 08/09/16.
//
#include "inc/bibliotecas.h"
#include "inc/structs.h"

extern lista    *newLista();
extern grafo    *inicGrafo();
extern node     *newNode(void*);
extern void     *insArco(grafo*, int, int, int);

void exemploGrafoAciclico();
void exemploGrafoCiclico();

int main(){
    printf("1 equivale à VERDADEIRO; 2 equivale à FALSO\n\n");

    exemploGrafoAciclico();
    exemploGrafoCiclico();

    return 0;
}

void exemploGrafoAciclico(){
    printf("Grafo Aciclico\n");

    //TODO: Refactoring
    /*grafo *g = inicGrafo();
    g->addAresta(g, newNode(newAresta(newVertice("1"), newVertice("2"))));
    g->addAresta(g, newNode(newAresta(newVertice("1"), newVertice("5"))));
    g->addAresta(g, newNode(newAresta(newVertice("1"), newVertice("4"))));
    g->addAresta(g, newNode(newAresta(newVertice("2"), newVertice("5"))));
    g->addAresta(g, newNode(newAresta(newVertice("3"), newVertice("6"))));
    g->addAresta(g, newNode(newAresta(newVertice("4"), newVertice("6"))));
    g->addAresta(g, newNode(newAresta(newVertice("4"), newVertice("7"))));
    g->addAresta(g, newNode(newAresta(newVertice("5"), newVertice("7"))));
    g->addAresta(g, newNode(newAresta(newVertice("6"), newVertice("8"))));
    g->addAresta(g, newNode(newAresta(newVertice("7"), newVertice("8"))));

    aresta *aresta = newAresta(newVertice("1"), newVertice("8"));

    //Task 1-2
    printf("%d", g->existeCaminho(g, aresta));

    //Task 3
    printf("\n%d", g->existeCiclo(g, newVertice("1")));

    //Task 4
    g->exibeCaminhos(g, aresta);*/
}

void exemploGrafoCiclico(){
    printf("Grafo Ciclico\n");

    //TODO: Refactoring
    /*grafo *g = inicGrafo();
    g->insArco(g, 1, 2, 3);
    g->insArco(g, 2, 1, 3);
    g->insArco(g, 2, 3, x);
    g->insArco(g, 2, 5, x);
    g->insArco(g, 3, 4, x);
    g->insArco(g, 4, 2, x);
    g->insArco(g, 4, 5, x);
    g->insArco(g, 4, 6, x);
    g->addAresta(g, newNode(newAresta(newVertice("2"), newVertice("1"))));
    g->addAresta(g, newNode(newAresta(newVertice("2"), newVertice("3"))));
    g->addAresta(g, newNode(newAresta(newVertice("2"), newVertice("5"))));
    g->addAresta(g, newNode(newAresta(newVertice("3"), newVertice("4"))));
    g->addAresta(g, newNode(newAresta(newVertice("4"), newVertice("2"))));
    g->addAresta(g, newNode(newAresta(newVertice("4"), newVertice("5"))));
    g->addAresta(g, newNode(newAresta(newVertice("4"), newVertice("6"))));

    aresta *aresta = newAresta(newVertice("1"), newVertice("2"));

    //Task 1-2
    printf("%d", g->existeCaminho(g, aresta));

    //Task 3
    printf("\n%d", g->existeCiclo(g, newVertice("5")));

    //Task 4
    g->exibeCaminhos(g, aresta);*/
}