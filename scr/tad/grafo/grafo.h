//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"

extern lista *newLista();
void    insArco(grafo*, int, int, int);
void    (*elimArco)(grafo*, int, int);
void    (*custoArco)(grafo*, int, int);
lista   (*sucessores)(grafo*, int);
lista   (*ordemGrafo)(grafo*);
lista   (*destruirGrafo)(grafo*);
lista   (*carregarGrafo)(FILE*);
lista   (*salvarGrafo)(grafo*, FILE*);
lista   (*marcarVertice)(grafo*, int);
lista   (*desmarcarVertice)(grafo*, int);
lista   (*desmarcarGrafo)(grafo*);
lista   (*marcadoVertice)(grafo*, int v);

int     existeCaminho(grafo*, arco*);
int     existeCiclo(grafo*, int);
void    exibeCaminhos(grafo*, arco*);

grafo *inicGrafo(){
    grafo *g = (grafo*)malloc(sizeof(grafo));
    g->arcos = newLista();
    g->insArco = insArco;
    g->existeCaminho = existeCaminho;
    g->existeCiclo = existeCiclo;
    g->exibeCaminhos = exibeCaminhos;
    return g;
}