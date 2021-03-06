//
// Created by izobretatel777 on 04/01/2022.
//

#ifndef YAML2PROP_PROPERTIESOUTPUT_H
#define YAML2PROP_PROPERTIESOUTPUT_H

#include <stdio.h>
#include "../entity/ChainList.h"

struct PropertiesOutput {
    FILE *file;
    ChainList *chainList;

    void (*printToOutput)(struct PropertiesOutput *);
};

typedef struct PropertiesOutput PropertiesOutput;

PropertiesOutput *propertiesOutputConstructor(FILE *file, ChainList *chainList);

void propertiesOutputDestructor(PropertiesOutput *self);

#endif //YAML2PROP_PROPERTIESOUTPUT_H
