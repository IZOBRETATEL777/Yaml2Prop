//
// Created by izobretatel777 on 04/01/2022.
//

#ifndef YAML2PROP_PRINTER_H
#define YAML2PROP_PRINTER_H

#include "../entity/Scalar.h"
#include "../entity/Chain.h"
#include "../entity/ChainList.h"

struct Printer {
    void (*printScalar)(struct Printer *, Scalar *, FILE *);

    void (*printChain)(struct Printer *, Chain *, FILE *);

    void (*printChainList)(struct Printer *, ChainList *, FILE *);
};

typedef struct Printer Printer;

Printer *printerConstructor();

void printerDestructor(Printer *self);

#endif //YAML2PROP_PRINTER_H
