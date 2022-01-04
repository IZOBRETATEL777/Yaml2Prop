#include "tool/YamlParser.h"
#include "entity/ChainList.h"
#include "tool/PropertiesOutput.h"
#include <stdio.h>
#include <string.h>

void interactive() {
    printf("Enter path to the source file:\n");
    char path[500];
    memset(path, 0, sizeof(path));
    scanf (" %[^\n]s", path);
    FILE* in = fopen(path, "r");
    if (in == NULL) {
        printf("Error while opening source file. Try again.\n");
        interactive();
        return;
    }
    YamlParser* yamlParser = yamlParserConstructor(in);
    ChainList* parsed = yamlParser->parse(yamlParser);
    PropertiesOutput* propertiesOutput = NULL;
    FILE* out = NULL;
    fclose(in);
    bool go = true;
    printf("What to do?\n");
    while (go) {
        printf("[1] Convert to properties and print to file\n");
        printf("[2] Convert to properties and display\n");
        printf("[0] Back\n");
        short cmd;
        scanf("%hu", &cmd);
        switch (cmd) {
            case 0:
                go = false;
                break;
            case 1:
                printf("Enter path to the destination file:\n");
                memset(path, 0, sizeof(path));
                scanf (" %[^\n]s", path);
                out = fopen(path, "w");
                if (out == NULL) {
                    printf("Error while opening destination file. Try again.\n");
                    break;
                }
                propertiesOutput = propertiesOutputConstructor(out, parsed);
                propertiesOutput->printToOutput(propertiesOutput);
                propertiesOutputDestructor((propertiesOutput));
                break;
            case 2:
                propertiesOutput = propertiesOutputConstructor(stdout, parsed);
                propertiesOutput->printToOutput(propertiesOutput);
                propertiesOutputDestructor((propertiesOutput));
                break;
            default:
                printf("No command found. Try again.\n");
        }

    }
    yamlParserDestructor(yamlParser);
}

void help() {
    printf("YAML2Prop - tool, to convert your YAML to Java properties file\n");
    printf("Usage:\n\tYaml2Prop [file] [option]\n\n");
    printf("\t%-40s\t-\t%s\n", "Yaml2Prop", "open interactive mode");
    printf("\t%-40s\t-\t%s\n", "Yaml2Prop path_to_file", "parse file and print it to display");
    printf("\t%-40s\t-\t%s\n", "Yaml2Prop path_to_file -o path_to_output", "parse file and save output");
    printf("\t%-40s\t-\t%s\n", "Yaml2Prop -h", "print help");
}

int main(int argNumber, char** args) {
    if (argNumber == 1) {
        printf("Welcome to YAML2Prop!\n");
        bool go = true;
        while (go) {
            printf("Enter a command\n");
            printf("[1] Open file...\n");
            printf("[2] Help\n");
            printf("[0] Exit\n");
            printf("Command: ");
            short cmd;
            scanf("%hu", &cmd);

            switch (cmd) {
                case 0:
                    printf("Bye!\n");
                    go = false;
                    break;

                case 1:
                    interactive();
                    break;

                case 2:
                    help();
                    break;

                default:
                    printf("No command found. Try again.\n");
            }

        }
    }
    else if (argNumber == 2) {
        char* path = args[1];
    }
    return 0;
}
