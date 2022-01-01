#include "YamlParser.h"
#include <stdio.h>

int main() {
    FILE* file = fopen("/home/izobretatel777/GitHub/ambiglyph-server/src/main/resources/application.yml", "r");
    YamlParser* yamlParser = yamlParserConstructor(file);
    yamlParser->parse(yamlParser);
    yamlParserDestructor(yamlParser);
    return 0;
}
