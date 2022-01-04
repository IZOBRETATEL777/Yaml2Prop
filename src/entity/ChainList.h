//
// Created by izobretatel777 on 03/01/2022.
//

#ifndef YAML2PROP_CHAINLIST_H
#define YAML2PROP_CHAINLIST_H

#include <stdlib.h>
#include "Chain.h"

struct ChainList {
    size_t length;
    size_t capacity;
    Chain** data;
    void (*add) (struct ChainList*, Chain*);
    void (*debugChainList) (struct ChainList*);
    struct  ChainList* (*getChainListCopy) (struct ChainList*);
};
typedef struct ChainList ChainList;
ChainList* chainListConstructor();
void chainListDestructor(ChainList* self);
#endif //YAML2PROP_CHAINLIST_H
