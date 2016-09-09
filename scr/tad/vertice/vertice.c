//
// Created by henrique on 08/09/16.
//

#include "../../inc/bibliotecas.h"
#include "vertice.h"
int verticeEquals(vertice *this, vertice *another){
    if(this == another){
        return 1;
    }
    if(this == NULL || another == NULL){
        return 0;
    }
    if(strcmp(this->valor, another->valor) == 0) {
        return 1;
    }
    return 0;
}
