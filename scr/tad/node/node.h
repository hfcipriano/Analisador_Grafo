//
// Created by henrique on 08/09/16.
//

#include "../../inc/structs.h"
void printNode(node*);
node *newNode(int v){
    node *n = (node*)malloc(sizeof(node));
    n->valor = v;
    n->proximo = NULL;
    n->anterior = NULL;
    n->printNode = printNode;
    return n;
}
