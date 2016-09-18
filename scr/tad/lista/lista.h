//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
void    addNodeInicio(lista*,node*);
void    addNodeFinal(lista*,node*);
void    desconectaNode(lista*,node*);
node*   rmNodeFinal(lista*);
node*   swap(lista*l,node*a,node*);
void    addListaFinal(lista*, lista*);

lista *newLista(){
    lista *l = (lista*)malloc(sizeof(lista));
    l->raiz = NULL;
    l->folha = NULL;
    l->qtd = 0;
    l->addNodeInicio = addNodeInicio;
    l->addNodeFinal = addNodeFinal;
    l->desconectaNode = desconectaNode;
    l->rmNodeFinal = rmNodeFinal;
    l->swap = swap;
    l->addListaFinal = addListaFinal;
    return l;
}