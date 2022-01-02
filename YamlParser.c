//
// Created by izobretatel777 on 01/01/2022.
//

#include "YamlParser.h"
#include "Chain.h"
#include <stdlib.h>
#include <yaml.h>

void parse(YamlParser *self) {

    Chain* document[100];
    int curIdx = 0;
    Chain* chain = chainConstructor();
    bool isValue = false;

    yaml_parser_t parser;
    yaml_token_t token;

    yaml_parser_initialize(&parser);
    yaml_parser_set_input_file(&parser, self->file);
    do {
        yaml_parser_scan(&parser, &token);
        switch (token.type) {

                /* Stream start/end */
            case YAML_STREAM_START_TOKEN:
                puts("STREAM START");
                break;

            case YAML_STREAM_END_TOKEN:
                puts("STREAM END");
                break;

                /* Token types (read before actual token) */
            case YAML_KEY_TOKEN:
                isValue = false;
                break;

            case YAML_VALUE_TOKEN:
                isValue = true;
                break;

                /* Block delimeters */
            case YAML_BLOCK_SEQUENCE_START_TOKEN:
                puts("<b>Start Block (Sequence)</b>");
                break;

            case YAML_BLOCK_ENTRY_TOKEN:
                puts("<b>Start Block (Entry)</b>");
                break;

            case YAML_BLOCK_END_TOKEN:
                puts("End block");
                chain->pop_back(chain);
                break;

                /* Data */
            case YAML_BLOCK_MAPPING_START_TOKEN:
                puts("[Block mapping]");
                break;

            case YAML_SCALAR_TOKEN:
                chain->push_back(chain, token.data.scalar.value);
                if (isValue) {
                    document[curIdx] = chainConstructor();
                    debug(chain);
                    document[curIdx] = chain->getCopy(chain);
                    curIdx++;
                    chain->pop_back(chain);
                    chain->pop_back(chain);
                }
                break;

                /* Others */
            default:
                printf("Got token of type %d\n", token.type);
        }
        if (token.type != YAML_STREAM_END_TOKEN)
            yaml_token_delete(&token);
    } while (token.type != YAML_STREAM_END_TOKEN);
    for (int i = 0; i < curIdx; i++) {
        debug(document[i]);
    }
    yaml_token_delete(&token);
    yaml_parser_delete(&parser);
}

YamlParser *yamlParserConstructor(FILE *file) {
    YamlParser *yamlParser = (YamlParser *) malloc(sizeof(YamlParser));
    yamlParser->file = file;
    yamlParser->parse = parse;
    return yamlParser;
}

void yamlParserDestructor(YamlParser *yamlParser) {
    free(yamlParser);
}
