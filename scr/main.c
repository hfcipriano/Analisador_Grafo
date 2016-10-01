//
// Created by henrique on 08/09/16.
//
#include "inc/bibliotecas.h"
#include "inc/structs.h"

extern lista *newLista();
extern grafo *newGrafo();
extern node *newNode(void*);
extern vertice *newVertice(char*);
extern aresta *newAresta(vertice*, vertice*);

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
    grafo *g = newGrafo();

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
    g->exibeCaminhos(g, aresta);
}

void exemploGrafoCiclico(){
    printf("Grafo Ciclico\n");
    grafo *g = newGrafo();

    g->addAresta(g, newNode(newAresta(newVertice("1"), newVertice("2"))));
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
    g->exibeCaminhos(g, aresta);
}