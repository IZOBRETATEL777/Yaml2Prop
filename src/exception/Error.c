//
// Created by izobretatel777 on 04/01/2022.
//

#include "Error.h"
#include <stdio.h>
#include <stdlib.h>

void printError(char message[]) {
    fprintf(stderr, "[ERROR] %s\n", message);
}

void printWarning(char message[]) {
    fprintf(stderr, "[WARNING] %s\n", message);
}

void printInfo(char message[]) {
    fprintf(stderr, "[INFO] %s\n", message);
}

Error *errorConstructor() {
    Error *error = (Error *) malloc(sizeof(Error));
    error->printError = printError;
    error->printWarning = printWarning;
    error->printInfo = printInfo;
    return error;
}

void errorDestructor(Error *self) {
    fflush(stderr);
    if (self != NULL) {
        free(self);
    }
}
