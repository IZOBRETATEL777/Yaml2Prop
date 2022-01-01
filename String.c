//
// Created by izobretatel777 on 31/12/2021.
//

#include <stdlib.h>
#include <string.h>
#include "String.h"

void setData(String* self, char data[]) {
    self->capacity = self->length = strlen(data);
    char* newData = (char* ) malloc(sizeof(char) * self->length);
    strcpy(newData, data);
    self->data = newData;
}

size_t size(String* self) {
    return self->length;
}

void clear(String* self) {
    free(self->data);
    self->data = NULL;
}

void print(String* self, FILE* out, char sep[], char end[]) {
    if (out == NULL || self == NULL) {
        return;
    }
    for (size_t i = 0; i < self->length; i++) {
        fputc(self->data[i], out);
        if(sep != NULL && i != self->length - 1) {
            fputs(sep, out);
        }
    }
    if (end != NULL) {
        fputs(end, out);
    }

}

void append(String* self, char c) {
    if (self->length >= self->capacity) {
        char* newData = (char* ) malloc(sizeof(char) * self->capacity * 2);
        strcpy(newData, self->data);
        free(self->data);
        self->data = newData;
        self->capacity *= 2;
    }

    self->data[self->length] = c;
    self->length++;
}

void shrinkToFit(String* self) {
    if (self->capacity == self->length) {
        return;
    }
    char* newData = (char* ) malloc(sizeof(char) * self->length);
    strcpy(newData, self->data);
    free(self->data);
    self->data = newData;
    self->capacity = self->length;
}

int stringComparator(const void *a, const void *b) {
    const String* strA = *(const String** ) a;
    const String* strB = *(const String** ) b;
    return strcmp(strA->data, strB->data);
}

String* stringConstructor() {
    String* string = (String*) malloc(sizeof (String));
    string->data = (char*) malloc(sizeof(char));
    string->length = 0;
    string->capacity = 1;
    string->setData = setData;
    string->clear = clear;
    string->print = print;
    string->append = append;
    string->size = size;
    string->shrinkToFit = shrinkToFit;
    return string;
}

void stringDestructor(String* self) {
    if (self->data != NULL) {
        free(self->data);
    }
    free(self);
}