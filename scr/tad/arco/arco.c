//
// Created by henrique on 08/09/16.
//
#include "../../inc/bibliotecas.h"
#include "arco.h"

int arcoEquals(arco *this, arco *another){
    if(this == another){
        return 1;
    }
    if(this == NULL || another == NULL){
        return 0;
    }
    if(this->antecessor == another->antecessor && this->sucessor == another->sucessor){
        return 1;
    }
    return 0;
}