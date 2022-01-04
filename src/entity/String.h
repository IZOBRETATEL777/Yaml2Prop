//
// Created by izobretatel777 on 31/12/2021.
//

#ifndef YAML2PROP_STRING_H
#define YAML2PROP_STRING_H

#include <stdbool.h>
#include <stdio.h>

struct String {
    char *data;
    size_t length;
    size_t capacity;

    void (*setData)(struct String *, char[]);

    void (*clear)(struct String *);

    void (*print)(struct String *, FILE *, char[], char[]);

    void (*append)(struct String *, char);

    void (*shrinkToFit)(struct String *);

    bool (*equals)(struct String *, struct String *);

    bool (*equalsCharArray)(struct String *, char[]);

    size_t (*size)(struct String *);
};

typedef struct String String;

String *stringConstructor();

void stringDestructor(String *self);

int stringComparator(const void *a, const void *b);

#endif //YAML2PROP_STRING_H