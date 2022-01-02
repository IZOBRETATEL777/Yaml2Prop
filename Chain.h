//
// Created by izobretatel777 on 01/01/2022.
//

#ifndef YAML2PROP_CHAIN_H
#define YAML2PROP_CHAIN_H

#include "Scalar.h"
#include <stdbool.h>

struct Chain {
    Scalar* front_tail;
    Scalar* back_tail;

    bool (*empty)(struct Chain*);
    Scalar* (*back)(struct Chain*);
    Scalar* (*front)(struct Chain*);
    void (*pop_front)(struct Chain*);
    void (*pop_back)(struct Chain*);
    void (*push_front)(struct Chain*, char*);
    void (*push_back)(struct Chain*, char*);
    struct Chain* (*getCopy)(struct Chain*);
};

typedef struct Chain Chain;

Chain* chainConstructor();
void chainDestructor(Chain*);
void debug(Chain* self);


#endif //YAML2PROP_CHAIN_H
