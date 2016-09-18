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

int main(){
    grafo *g = newGrafo();

    g->addAresta(g, newNode(newAresta(newVertice("a"), newVertice("b"))));
    g->addAresta(g, newNode(newAresta(newVertice("b"), newVertice("c"))));
    g->addAresta(g, newNode(newAresta(newVertice("c"), newVertice("d"))));
    g->addAresta(g, newNode(newAresta(newVertice("d"), newVertice("a"))));

    aresta *aresta = newAresta(newVertice("a"), newVertice("d"));

    //Task 1-2
    printf("%d", g->existeCaminho(g, aresta));

    //Task 3
    printf("\n%d", g->existeCiclo(g, newVertice("a")));

    //Task 4
    g->exibeCaminhos(g, aresta);

    return 0;
}