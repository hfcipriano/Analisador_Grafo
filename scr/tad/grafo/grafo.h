//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"

extern lista *newLista();
void    insArco(grafo*, int, int, int);
void    elimArco(grafo*, int, int);
int     custoArco(grafo*, int, int);
lista   *obterSucessores(lista*, vertice*);
lista   *obterAntecessores(lista*, vertice*);
int     ordemGrafo(grafo*);
void    destruirGrafo(grafo*);
grafo   *carregarGrafo(FILE*);
void    salvarGrafo(grafo*, FILE*);
void    marcarVertice(grafo*, int);
void    desmarcarVertice(grafo*, int);
void    desmarcarGrafo(grafo*);
int     marcadoVertice(grafo*, int);

int     existeCaminho(grafo*, arco*);
int     existeCiclo(grafo*, int);
void    exibeCaminhos(grafo*, arco*);

grafo *inicGrafo(){
    grafo *g = (grafo*)malloc(sizeof(grafo));
    g->arcos = newLista();
    g->insArco = insArco;
    g->elimArco = elimArco;
    g->custoArco = custoArco;
    g->obterSucessores = obterSucessores;
    g->obterAntecessores = obterAntecessores;
    g->ordemGrafo = ordemGrafo;
    g->destruirGrafo = destruirGrafo;
    g->carregarGrafo = carregarGrafo;
    g->salvarGrafo = salvarGrafo;
    g->marcarVertice = marcarVertice;
    g->desmarcarVertice = desmarcarVertice;
    g->desmarcarGrafo = desmarcarGrafo;
    g->marcadoVertice = marcadoVertice;

    g->existeCaminho = existeCaminho;
    g->existeCiclo = existeCiclo;
    g->exibeCaminhos = exibeCaminhos;
    return g;
}