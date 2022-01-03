//
// Created by izobretatel777 on 01/01/2022.
//

#include "YamlParser.h"
#include "../entity/Scalar.h"
#include "../entity/Chain.h"
#include "../entity/ChainList.h"
#include <stdlib.h>
#include <yaml.h>

void parsing(yaml_parser_t* parser, yaml_token_t* token, Chain* chain, bool isSequence, bool isValue, ChainList* chainList, bool inRec) {
    if (token->type == YAML_STREAM_END_TOKEN)
        return;
    if (!inRec) {
        yaml_parser_scan(parser, token);
    }
    switch (token->type) {

        /* Stream start/end */
        case YAML_STREAM_START_TOKEN:
//            puts("STREAM START");
            break;

        case YAML_STREAM_END_TOKEN:
//            puts("STREAM END");
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
//            puts("<b>Start Block (Sequence)</b>");
            isSequence = true;
            break;

        case YAML_BLOCK_ENTRY_TOKEN:
//            puts("<b>Start Block (Entry)</b>");
            break;

        case YAML_BLOCK_END_TOKEN:
//            puts("End block");
//            chain->debugChain(chain);


            if (isSequence)
                isSequence = false;
            chain->pop_back(chain);
//            puts("POP!");
            if (chain->empty(chain)) {
                return;
            }
//            chain->debugChain(chain);
            break;

            /* Data */
        case YAML_BLOCK_MAPPING_START_TOKEN:
//            puts("[Block mapping]");
            break;

        case YAML_SCALAR_TOKEN:
//            printf("%s is value? %d\n",token->data.scalar.value, isValue);
            if (!isSequence) {
                chain->push_back(chain, token->data.scalar.value);
                chain->back(chain)->isValue = isValue;
                if (isValue) {
                    chainList->add(chainList, chain);
//                    puts("POP!");
                    chain->pop_back(chain);
//                    puts("POP!");
                    chain->pop_back(chain);
                }
            }
            else {
                chain->push_back(chain, "SEQ");

                Chain* subChain = chainConstructor();
                ChainList* subChainList = chainListConstructor();
                do {
                    parsing(parser, token, subChain, false, isValue, subChainList, true);
                } while (token->type != YAML_BLOCK_END_TOKEN);
                chain->back(chain)->hasSequences = true;
                chain->back(chain)->sequences = subChainList;
                chainList->add(chainList, chain);
                chain->pop_back(chain);
            }

            break;

            /* Others */
        default:
            printf("Got token of type %d\n", token->type);
    }
    if (token->type != YAML_STREAM_END_TOKEN) {
        yaml_token_delete(token);
    }
    parsing(parser, token, chain, isSequence, isValue, chainList, false);
}

void parse(YamlParser *self) {

    ChainList* chainList = chainListConstructor();
    Chain* chain = chainConstructor();
    chain->push_back(chain, "START");

    yaml_parser_t parser;
    yaml_token_t token;

    yaml_parser_initialize(&parser);
    yaml_parser_set_input_file(&parser, self->file);

    parsing(&parser, &token, chain, 0, 0, chainList, false);
    puts("Finished");
    chainList->debugChainList(chainList);
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
