//
// Created by izobretatel777 on 04/01/2022.
//

#include "PropertiesOutput.h"
#include "Printer.h"

void printToOutput (PropertiesOutput* self) {
    Printer* printer = printerConstructor();
    printer->printChainList(printer, self->chainList, self->file);
    printerDestructor(printer);
}

PropertiesOutput* propertiesOutputConstructor(FILE* file, ChainList* chainList) {
    PropertiesOutput* propertiesOutput = (PropertiesOutput* ) malloc(sizeof(PropertiesOutput));
    propertiesOutput->chainList = chainList;
    propertiesOutput->file = file;
    propertiesOutput->printToOutput = printToOutput;
    return propertiesOutput;
}
void propertiesOutputDestructor(PropertiesOutput* self) {
    free(self);
};