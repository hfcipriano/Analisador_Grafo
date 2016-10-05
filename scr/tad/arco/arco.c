//
// Created by henrique on 08/09/16.
//
#include "../../inc/bibliotecas.h"
#include "arco.h"

int arcoEquals(arco *this, arco *another){
    if(this == another){
        return bool_TRUE;
    }
    if(this == NULL || another == NULL){
        return bool_FALSE;
    }
    if(this->antecessor->valor == another->antecessor->valor && this->sucessor->valor == another->sucessor->valor){
        return bool_TRUE;
    }
    return bool_FALSE;
}