//
// Created by henrique on 08/09/16.
//

#include "inc/bibliotecas.h"
#include "inc/structs.h"

extern lista *newLista();
extern grafo *newGrafo();
extern node *newNode(void*);
extern node *newVertice(char*);
extern node *newAresta(char*, vertice*, vertice*);
grafo *newGrafoLocal();

int main(){
    grafo *g = newGrafoLocal();
    g->addVertice(g, newNode(newVertice((char*) "asdfdfsdfsa")));

    g->printVertices(g);
    return 0;
}

grafo *newGrafoLocal(){
    grafo *g = newGrafo();
    g->vertices = newLista();
    return g;
}