//
// Created by henrique on 08/09/16.
//

#include "inc/bibliotecas.h"
#include "inc/structs.h"

extern lista *newLista();
extern grafo *newGrafo();
extern node *newNode(void*);
extern vertice *newVertice(char*);
extern aresta *newAresta(char*, vertice*, vertice*);
grafo *newGrafoLocal();

int main(){
    grafo *g = newGrafoLocal();
    g->addVertice(g, newNode(newVertice((char*) "a")));
    g->addVertice(g, newNode(newVertice((char*) "b")));
    g->printVertices(g);

    g->addAresta(g, newNode(newAresta((char*) "1", newVertice((char*) "a"), newVertice((char*) "b"))));
    g->printArestas(g);
    return 0;
}

grafo *newGrafoLocal(){
    grafo *g = newGrafo();
    g->vertices = newLista();
    g->arestas = newLista();
    return g;
}