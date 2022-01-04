//
// Created by izobretatel777 on 05/01/2022.
//

#include "Visualizer.h"
#include <string.h>
#include <stdlib.h>

int fileCopy(char source[], char destination[]) {
    int c;
    FILE *fileRead;
    FILE *fileWrite;
    fileRead = fopen(source, "r");
    if (fileRead == NULL)
        return -1;
    fileWrite = fopen(destination, "w");
    if (fileWrite == NULL) {
        fclose(fileRead);
        return -2;
    }
    fprintf(fileWrite, "@startyaml\n");
    while ((c = fgetc(fileRead)) != EOF)
        fputc(c, fileWrite);
    fprintf(fileWrite, "@endyamll\n");
    fclose(fileRead);
    fclose(fileWrite);
    return 0;
}

int visualize(Visualizer* self) {
    char suf[500];
    strcpy(suf, self->file);
    char pref[512];
    strcpy(pref, "visualized-");
    strcat(pref, suf);
    int res = fileCopy(self->file, pref);
    if (res != 0) {
        return res;
    }
    char command[550];
    strcpy(command, "java -jar plantuml.jar ");
    strcat(command, pref);
    res = system(command);
    remove(pref);
    return res;
}

Visualizer *visualizerConstructor(char* file) {
    Visualizer* visualizer = (Visualizer*) malloc(sizeof(Visualizer));
    visualizer->file = file;
    visualizer->visualize = visualize;
    return visualizer;
}

void visualizerDestructor(Visualizer *self) {
    if(self != NULL) {
        free(self);
    }
}