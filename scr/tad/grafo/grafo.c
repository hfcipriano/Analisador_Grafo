//
// Created by henrique on 08/09/16.
//
#include "../../inc/bibliotecas.h"
#include "grafo.h"

extern lista* newLista();
extern arco* newArco();
extern node *newNode(void*);

void printCaminho(lista *l);

/**
 * Insere Arco no Grafo
 * @param g Grafo
 * @param vertice antecessor
 * @param vertice sucessor
 * @param custo Custo do Arco
 */
void insArco(grafo *g, int antecessor, int sucessor, int custo){
    arco *arco = newArco();
    arco->antecessor = antecessor;
    arco->sucessor = sucessor;
    arco->custo = custo;

    g->arcos->addNodeFinal(g->arcos, newNode(arco));
}

/**
 * Remove o arco do Grafo caso ele exista
 * @param g Grafo
 * @param antecessor Vértice do arco a ser removido
 * @param sucessor Vértice do arco a ser removido
 */
void elimArco(grafo *g, int antecessor, int sucessor){
    node *n = g->arcos->raiz;
    while(n != NULL){
        arco *arco= n->elemento;
        if(arco->antecessor == antecessor && arco->sucessor == sucessor){
            g->arcos->desconectaNode(g->arcos, n);
            return;
        }
        n = n->proximo;
    }
}

/**
 * Retorna o custo do arco caso exista. Caso contrário retorna -1
 * @param g Grafo
 * @param antecessor
 * @param sucessor
 * @return Custo do arco ou -1 quando não existir
 */
int custoArco(grafo *g, int antecessor, int sucessor){
    node *n = g->arcos->raiz;
    while(n != NULL){
        arco *arco= n->elemento;
        if(arco->antecessor == antecessor && arco->sucessor == sucessor){
            return arco->custo;
        }
        n = n->proximo;
    }
    return -1;
};

int ordemGrafo(grafo *g){
    return g->arcos->qtd * 2;
};

void destruirGrafo(grafo *g){
    free(g);
};

grafo *carregarGrafo(FILE *arquivo){
    //TODO: Implementar
    return NULL;
};

void salvarGrafo(grafo *g, FILE *arquivo){
    //TODO: Implementar
}

void marcarVertice(grafo* g, int vertice){
    //TODO: Implementar
};

void desmarcarVertice(grafo* g, int vertice){
    //TODO: Implementar
};

void desmarcarGrafo(grafo* g){
    //TODO: Implementar
};

void marcadoVertice(grafo* g, int vertice){
    //TODO: Implementar
};

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