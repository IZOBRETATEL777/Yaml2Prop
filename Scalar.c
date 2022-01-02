//
// Created by izobretatel777 on 01/01/2022.
//

#include "Scalar.h"
#include <stdlib.h>

Scalar* scalarConstructor(char* data) {
    Scalar *scalar = (Scalar* )malloc(sizeof(Scalar));
    scalar->next = NULL;
    scalar->prev = NULL;
    scalar->data = stringConstructor();
    scalar->data->setData(scalar->data, data);
    return scalar;
}

void scalarDestructor(Scalar* self) {
    if (self != NULL) {
        free(self);
    }
}
