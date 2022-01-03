//
// Created by izobretatel777 on 01/01/2022.
//

#include "Scalar.h"
#include "ChainList.h"
#include <stdlib.h>

void debugScalar(Scalar* self) {
    if (self == NULL) {
        return;
    }
    printf("%s-->", self->data->data);
    if (self->hasSequences) {
        printf("\n");
        self->sequences->debugChainList(self->sequences);
    }
}

Scalar* getScalarCopy(Scalar* self) {
    if (self == NULL) {
        return NULL;
    }
    Scalar *scalar = (Scalar* )malloc(sizeof(Scalar));
    scalar->next = self->next;
    scalar->prev = self->prev;
    scalar->data = stringConstructor();
    scalar->data->setData(scalar->data, self->data);
    scalar->sequences = chainListConstructor();
    scalar->isValue = false;
    scalar->hasSequences = false;

    scalar->debugScalar = debugScalar;
    scalar->getScalarCopy = getScalarCopy;

    return scalar;
}

Scalar* scalarConstructor(char* data) {
    Scalar *scalar = (Scalar* )malloc(sizeof(Scalar));
    scalar->next = NULL;
    scalar->prev = NULL;
    scalar->data = stringConstructor();
    scalar->data->setData(scalar->data, data);
    scalar->sequences = chainListConstructor();
    scalar->isValue = false;
    scalar->hasSequences = false;
    scalar->debugScalar = debugScalar;
    scalar->getScalarCopy = getScalarCopy;
    return scalar;
}

void scalarDestructor(Scalar* self) {
    if (self != NULL) {
        free(self);
    }
}
