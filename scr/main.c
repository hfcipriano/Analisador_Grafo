//
// Created by henrique on 08/09/16.
//
#include "inc/bibliotecas.h"
#include "inc/structs.h"

extern lista    *newLista();
extern grafo    *inicGrafo();
extern node     *newNode(void*);
extern arco     *newArco(int, int);
extern void     *insArco(grafo*, int, int, int);

void exemploGrafoAciclico();
void exemploGrafoCiclico();

int main(){
    printf("1 equivale à VERDADEIRO; 0 equivale à FALSO\n\n");

    exemploGrafoAciclico();
    exemploGrafoCiclico();

    return 0;
}

void exemploGrafoAciclico(){
    printf("Grafo Aciclico\n");

    grafo *g = inicGrafo();

    g->insArco(g, 3, 6, 0);
    g->insArco(g, 6, 8, 0);
    g->insArco(g, 1, 2, 0);
    g->insArco(g, 1, 5, 0);
    g->insArco(g, 1, 4, 0);
    g->insArco(g, 4, 6, 0);
    g->insArco(g, 4, 7, 0);
    g->insArco(g, 2, 5, 0);
    g->insArco(g, 5, 7, 0);
    g->insArco(g, 7, 8, 0);


    arco *arco = newArco(3, 8);

    //Task 1-2
    printf("Existe caminho: %d", g->existeCaminho(g, arco));

    //Task 4
    g->exibeCaminhos(g, arco);
}

void exemploGrafoCiclico(){
    printf("\nGrafo Ciclico\n");

    grafo *g = inicGrafo();
    g->insArco(g, 1, 2, 3);
    g->insArco(g, 2, 1, 3);
    g->insArco(g, 2, 3, 0);
    g->insArco(g, 2, 5, 0);
    g->insArco(g, 3, 4, 0);
    g->insArco(g, 4, 2, 0);
    g->insArco(g, 4, 5, 0);
    g->insArco(g, 4, 6, 0);

    arco *arco = newArco(3, 5);

    //Task 1-2
    printf("Existe caminho: %d", g->existeCaminho(g, arco));

    //Task 3
    printf("\nExiste ciclo: %d", g->existeCiclo(g, 4));

    //Task 4
    g->exibeCaminhos(g, arco);
}