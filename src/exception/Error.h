//
// Created by izobretatel777 on 04/01/2022.
//

#ifndef YAML2PROP_ERROR_H
#define YAML2PROP_ERROR_H

struct Error {
    void (*printError)(char[]);

    void (*printWarning)(char[]);

    void (*printInfo)(char[]);
};

typedef struct Error Error;

Error *errorConstructor();

void errorDestructor(Error *self);

#endif //YAML2PROP_ERROR_H
