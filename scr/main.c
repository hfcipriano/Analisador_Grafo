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

    g->addAresta(g, newNode(newAresta("1", newVertice("a"), newVertice("b"))));
    g->addAresta(g, newNode(newAresta("2", newVertice("b"), newVertice("c"))));
    g->addAresta(g, newNode(newAresta("3", newVertice("c"), newVertice("b"))));
    g->printArestas(g);

    /*aresta *aresta = newAresta("1", newVertice("a"), newVertice("d"));
    if(g->existeCaminho(g, aresta)){
        printf("EXISTE CAMINHO ENTRE %s E %s", aresta->antecessor->valor, aresta->sucessor->valor);
    }*/
    vertice *v = newVertice("b");
    if(g->existeCiclo(g, v)){
        printf("EXISTE PELO MENOS UM CICLO PARTINDO DO VÉRTICE: %s", v->valor);
    }

    return 0;
}

grafo *newGrafoLocal(){
    grafo *g = newGrafo();
    g->arestas = newLista();
    return g;
}