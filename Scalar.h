//
// Created by izobretatel777 on 01/01/2022.
//
#ifndef YAML2PROP_SCALAR_H
#define YAML2PROP_SCALAR_H
struct Scalar {
    char* data;
    struct Scalar* prev;
    struct Scalar* next;
};
typedef struct Scalar Scalar;
Scalar* scalarConstructor(char*);
void scalarDestructor(Scalar*);
#endif //YAML2PROP_SCALAR_H
