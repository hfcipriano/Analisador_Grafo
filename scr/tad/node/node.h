//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
void printNode(node*);
node *newNode(void *info){
    node *n = (node*)malloc(sizeof(node));
    n->elemento = info;
    n->proximo = NULL;
    n->anterior = NULL;
    return n;
}