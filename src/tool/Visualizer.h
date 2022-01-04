//
// Created by izobretatel777 on 05/01/2022.
//

#ifndef YAML2PROP_VISUALIZER_H
#define YAML2PROP_VISUALIZER_H

#include <stdio.h>

struct Visualizer {
    char *file;

    int (*visualize)(struct Visualizer *);
};

typedef struct Visualizer Visualizer;

Visualizer *visualizerConstructor(char *);

void visualizerDestructor(Visualizer *self);

#endif //YAML2PROP_VISUALIZER_H
