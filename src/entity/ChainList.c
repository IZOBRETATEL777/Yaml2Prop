//
// Created by izobretatel777 on 03/01/2022.
//

#include "ChainList.h"
#include <string.h>

void debugChainList(ChainList* self) {
    for (int i = 0; i < self->length; i++) {
        if (self->data[i] != NULL) {
            self->data[i]->debugChain(self->data[i]);
        }
    }
    printf("______end_chain_list\n");
}

void add(ChainList* self, Chain* chain) {
    if (self->capacity == self->length) {
        self->capacity *= 2;
        Chain** newData = (Chain**) malloc(sizeof(Chain*) * self->capacity);
        for (int i = 0; i < self->length; i++) {
            newData[i] = self->data[i]->getChainCopy(self->data[i]);
        }
        free(self->data);
        self->data = newData;
    }
    self->data[self->length] = chain->getChainCopy(chain);
    self->length++;
}

ChainList* getChainListCopy(ChainList* self) {
    if (self == NULL) {
        return NULL;
    }
    ChainList* chainList = chainListConstructor();
    chainList->capacity = self->capacity;
    chainList->length = self->length;
    chainList->data = (Chain**) malloc(sizeof(Chain*) * chainList->capacity);
    for (int i = 0; i < self->length; i++) {
        chainList->data[i] = self->data[i]->getChainCopy(self->data[i]);
    }
    chainList->add = add;
    chainList->debugChainList = debugChainList;
    chainList->getChainListCopy = getChainListCopy;

    return chainList;
}

ChainList* chainListConstructor() {
    ChainList* chainList = (ChainList*) malloc(sizeof(ChainList));
    chainList->capacity = 1;
    chainList->length = 0;
    chainList->data = (Chain**) malloc(sizeof(Chain*) * chainList->capacity);
    chainList->add = add;
    chainList->debugChainList = debugChainList;
    chainList->getChainListCopy = getChainListCopy;
    return chainList;
}
void chainListDestructor(ChainList* self) {
    if (self != NULL) {
        for (int i = 0; i < self->length; i++) {
            if(self->data[i] != NULL)
                chainDestructor(self->data[i]);
        }
        free(self->data);
        free(self);
    }
}