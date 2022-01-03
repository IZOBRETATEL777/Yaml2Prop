#include "tool/YamlParser.h"
#include <stdio.h>

int main() {
    FILE* file = fopen("invoice.yaml", "r");
    YamlParser* yamlParser = yamlParserConstructor(file);
    yamlParser->parse(yamlParser);
    yamlParserDestructor(yamlParser);
    fclose(file);
    return 0;
}
