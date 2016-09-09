//
// Created by henrique on 08/09/16.
//
#include "../../inc/bibliotecas.h"
#include "aresta.h"

int equals(aresta *this, aresta *another){
    if(this == another){
        return 1;
    }
    if(this == NULL || another == NULL){
        return 0;
    }
    if(strcmp(this->antecessor->valor, another->antecessor->valor) == 0 && strcmp(this->sucessor->valor, another->sucessor->valor) == 0){
        return 1;
    }
    return 0;
}