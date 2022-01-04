//
// Created by izobretatel777 on 01/01/2022.
//
#ifndef YAML2PROP_SCALAR_H
#define YAML2PROP_SCALAR_H

#include "String.h"

struct Scalar {
    String* data;
    bool isValue;
    bool hasSequences;
    struct Scalar* prev;
    struct Scalar* next;
    struct ChainList* sequences;
    void (*debugScalar) (struct Scalar*);
    struct Scalar* (*getScalarCopy) (struct Scalar*);
};
typedef struct Scalar Scalar;
Scalar* scalarConstructor(char* data);
void scalarDestructor(Scalar* self);
#endif //YAML2PROP_SCALAR_H
