//
// Created by izobretatel777 on 04/01/2022.
//

#include "Printer.h"

void printScalar(Printer *self, Scalar *scalar, FILE *file) {
    if (scalar == NULL) {
        return;
    }
    if (scalar->hasSequences) {
        self->printChainList(self, scalar->sequences, file);
    } else {
        if (!scalar->isRoot) {
            fputs(scalar->data->data, file);
            if (scalar->next != NULL && (scalar->next->isValue || scalar->next->hasSequences))
                fputc('=', file);
            else if (!scalar->isValue && !scalar->hasSequences)
                fputc('.', file);
        }
    }

}

void printChain(Printer *self, Chain *chain, FILE *file) {
    if (chain == NULL) {
        return;
    }
    Scalar *scalar = chain->front_tail;
    while (scalar != NULL) {
        self->printScalar(self, scalar, file);
        scalar = scalar->next;
    }
    if (chain->front(chain)->isRoot)
        fputc('\n', file);
}

void printChainList(Printer *self, ChainList *chainList, FILE *file) {
    if (chainList == NULL) {
        return;
    }
    bool isRoot = chainList->data[0]->front(chainList->data[0])->isRoot;
    if (!isRoot) {
        fputc('{', file);
    }
    for (int i = 0; i < chainList->length; i++) {
        if (chainList->data[i] != NULL) {
            printChain(self, chainList->data[i], file);
        }
        if (!isRoot && i != chainList->length - 1)
            fputc(',', file);
    }
    if (!isRoot) {
        fputc('}', file);
    }
}

Printer *printerConstructor() {
    Printer *printer = (Printer *) malloc(sizeof(Printer));
    printer->printScalar = printScalar;
    printer->printChain = printChain;
    printer->printChainList = printChainList;
    return printer;
}

void printerDestructor(Printer *self) {
    free(self);
}