#include "../../inc/bibliotecas.h"
#include "lista.h"

void addNodeInicio(lista *l,node *n){
    node *r = l->raiz;
    l->raiz = n;
    l->qtd++;
    if(r == NULL)
        l->folha = n;
    else{
        n->proximo = r;
        r->anterior = n;
    }
}

void desconectaNode(lista *l, node *n){
    node *a = n->anterior, *b = n->proximo;
    if(n == l->raiz){
        l->raiz = b;
    }else{
        a->proximo = b;
    }
    if(n == l->folha){
        l->folha = a;
    }else{
        b->anterior = a;
    }
    n->anterior = NULL;
    n->proximo = NULL;
    l->qtd--;
}

void addNodeFinal(lista *l,node *n){
    node *r = l->raiz, *f = l->folha;
    n->anterior = NULL;
    n->proximo = NULL;
    if(r == NULL){
        l->raiz = n;
        l->folha = n;
    }else{
        f->proximo = n;
        n->anterior = f;
        l->folha = n;
    }
    l->qtd++;
}

node* rmNodeFinal(lista *l){
    node *f = l->folha;
    if(f == NULL){
        return NULL;
    }else{
        desconectaNode(l,f);
        return f;
    }
}

node* swap(lista *l, node *a, node *b){
//entrada: antes->a->b->depois
//saida: antes->b->a->depois

    node *antes, *depois;
    antes = a->anterior;
    depois = b->proximo;

    if(antes != NULL){
        antes->proximo = b;
    }else{
        l->raiz = b;
    }
    b->anterior = antes;

    b->proximo = a;
    a->anterior = b;

    a->proximo = depois;
    if(depois != NULL) depois->anterior = a;

    return b;
}

int verificar(lista *l){
    int verificar;
    node *aux;
    aux = l->raiz;
    if((aux == NULL) || (aux->proximo == NULL))
    {
        printf("A lista deve conter mais de dois elementos!\n\n");
        verificar = 0;
        system("pause");
        system("cls");
    }
    else
    {
        verificar = 1;
    }
    return verificar;
}