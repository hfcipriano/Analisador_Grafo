//
// Created by henrique on 05/10/16.
//

#include "../../inc/bibliotecas.h"
#include "vertice.h"

int verticeEquals(vertice *this, vertice *another){
    if(this == another){
        return bool_TRUE;
    }
    if(this == NULL || another == NULL){
        return bool_FALSE;
    }
    if(this->valor == another->valor){
        return bool_TRUE;
    }
    return bool_FALSE;
}