//
// Created by izobretatel777 on 01/01/2022.
//

#include "Chain.h"
#include <stdio.h>s
#include <stdlib.h>

void debug(Chain* self) {
    if (self == NULL) {
        return;
    }
    Scalar *scalar = self->front_tail;
    while (scalar != NULL) {
        printf("%s->", scalar->data);
        scalar = scalar->next;
    }
    printf("_______\n");
}

bool empty(Chain* self) {
    return (self->front_tail == NULL || self->back_tail == NULL);
}

void push_front(Chain* self, char* data) {
//	debug(self);
    Scalar* scalar = scalarConstructor(data);
    if (empty(self)) {
        self->front_tail = scalar;
        self->back_tail = scalar;
    }
    else {
        scalar->next = self->front_tail;
        self->front_tail->prev = scalar;
        self->front_tail = scalar;
    }
//	debug(self);
}

void push_back(Chain* self, char* data) {
//	debug(self);
    Scalar* scalar = scalarConstructor(data);
    if (empty(self)) {
        self->front_tail = scalar;
        self->back_tail = scalar;
    }
    else {
        scalar->prev = self->back_tail;
        self->back_tail->next = scalar;
        self->back_tail = scalar;
    }
//	debug(self);
}

Scalar* front(Chain* self) {
    return self->front_tail;
}

Scalar* back(Chain* self) {
    return self->back_tail;
}

void pop_front(Chain* self) {
//	debug(self);
    if (empty(self)) {
        return;
    }
    Scalar* scalar = self->front_tail;
    self->front_tail = scalar->next;
    if (self->front_tail == NULL)
        self->back_tail = NULL;
    else
        self->front_tail->prev = NULL;
    free(scalar);
//    debug(self);
}

void pop_back(Chain* self) {
    if (empty(self)) {
        return;
    }
//	debug(self);
    Scalar* scalar = self->back_tail;
    self->back_tail = scalar->prev;
    if (self->back_tail == NULL)
        self->front_tail = NULL;
    else
        self->back_tail->next = NULL;
    free(scalar);
//	debug(self);
}

Chain* chainConstructor() {
    Chain* self = (Chain*)malloc(sizeof(Chain));
    self->back_tail = NULL;
    self->front_tail = NULL;
    self->pop_back = pop_back;
    self->pop_front = pop_front;
    self->back = back;
    self->front = front;
    self->push_back = push_back;
    self->push_front = push_front;
    self->empty = empty;
    return self;
}

void chainDestructor(Chain* self) {
    if (self == NULL)
        return;

    Scalar *cur = self->front_tail;
    while (cur != NULL) {
        Scalar *next = cur->next;
        scalarDestructor(cur);
        cur = next;
    }
    free(self);
}
