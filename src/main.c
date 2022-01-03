#include "tool/YamlParser.h"
#include "entity/ChainList.h"
#include "tool/PropertiesOutput.h"
#include <stdio.h>

int main() {
    FILE* file = fopen("invoice.yaml", "r");
    YamlParser* yamlParser = yamlParserConstructor(file);
    ChainList* chainList = yamlParser->parse(yamlParser);
    PropertiesOutput* propertiesOutput = propertiesOutputConstructor(stdout, chainList);
    propertiesOutput->printToOutput(propertiesOutput);

    yamlParserDestructor(yamlParser);
    fclose(file);
    return 0;
}
