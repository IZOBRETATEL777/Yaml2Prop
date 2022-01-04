//
// Created by izobretatel777 on 01/01/2022.
//
#include <stdio.h>

#ifndef YAML2PROP_YAMLPARSER_H
#define YAML2PROP_YAMLPARSER_H

struct YamlParser {
    FILE *file;

    struct ChainList *(*parse)(struct YamlParser *);
};

typedef struct YamlParser YamlParser;

YamlParser *yamlParserConstructor(FILE *file);

void yamlParserDestructor(YamlParser *yamlParser);

#endif //YAML2PROP_YAMLPARSER_H
