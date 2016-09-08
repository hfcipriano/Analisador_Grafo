//
// Created by henrique on 08/09/16.
//

#include "inc/bibliotecas.h"
#include "inc/structs.h"

extern lista *newLista();
extern node *newNode(int);

int main(){
    lista *l = newLista();
    l->addNodeInicio(l, newNode(1));
    l->addNodeInicio(l, newNode(2));
    l->printListaTexto(l);

    return 0;
}