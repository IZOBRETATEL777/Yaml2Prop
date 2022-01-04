#include "tool/YamlParser.h"
#include "entity/ChainList.h"
#include "tool/PropertiesOutput.h"
#include "tool/Visualizer.h"
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
    Visualizer* visualizer = NULL;
    FILE* out = NULL;
    fclose(in);
    bool go = true;
    printf("What to do?\n");
    while (go) {
        printf("[1] Convert to properties and print to file\n");
        printf("[2] Convert to properties and display\n");
        printf("[3] Create visualization\n");
        printf("[0] Back\n");
        short cmd;
        scanf("%hu", &cmd);
        switch (cmd) {
            case 0:
                go = false;
                break;
            case 1:
                printf("Enter path to the destination file:\n");
                char dest[500];
                memset(dest, 0, sizeof(dest));
                scanf (" %[^\n]s", dest);
                out = fopen(dest, "w");
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
            case 3:
                visualizer = visualizerConstructor(path);
                if (visualizer->visualize(visualizer) != 0)
                    printf("Error while visualizing. Please, be sure that PlantUML is available.\n");
                else
                    printf("Ready.\n");
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
    printf("\t%-40s\t-\t%s\n", "Yaml2Prop path_to_file -v", "create a visualization image. Plantuml.jar in the same directory with this program and JRE are required.");
    printf("\t%-40s\t-\t%s\n", "Yaml2Prop path_to_file -o path_to_output", "parse file and save output");
    printf("\t%-40s\t-\t%s\n", "Yaml2Prop -h", "print help");
}

void cli(int argNumber, char** args) {
    FILE* in = NULL;
    FILE* out = NULL;
    YamlParser* yamlParser = NULL;
    ChainList* parsed = NULL;
    PropertiesOutput* propertiesOutput = NULL;
    if (argNumber == 2 || argNumber == 4) {
        if (strcmp(args[1], "-h") == 0 && argNumber == 2) {
            help();
            return;
        }
        char* arg = args[1];
        in = fopen(args[1], "r");
        if (in == NULL) {
            printf("Error while opening source file. Try again.\n");
            return;
        }
        yamlParser = yamlParserConstructor(in);
        parsed = yamlParser->parse(yamlParser);
        fclose(in);
        if(argNumber == 4 && strcmp(args[2], "-o") == 0) {
            out = fopen(args[3], "w");
            propertiesOutput = propertiesOutputConstructor(out, parsed);
            propertiesOutput->printToOutput(propertiesOutput);
            fclose(out);
            yamlParserDestructor(yamlParser);
            chainListDestructor(parsed);
            propertiesOutputDestructor(propertiesOutput);
            return;
        }
        else if (argNumber == 2) {
            propertiesOutput = propertiesOutputConstructor(stdout, parsed);
            propertiesOutput->printToOutput(propertiesOutput);
            yamlParserDestructor(yamlParser);
            chainListDestructor(parsed);
            propertiesOutputDestructor(propertiesOutput);
            return;
        }
        else {
            printf("Error!\nRun with -h to get help.\n");
            return;
        }
    }
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
    else{
        cli(argNumber, args);
    }
    return 0;
}
