#ifndef XML_PARSER_VEC_H
#define XML_PARSER_VEC_H

#include <corecrt.h>

typedef struct {
    void **data;
    size_t length;
    size_t capacity;
} Vec;

void new_vec(Vec* a, size_t initialSize);
void append_to_vec(Vec* a, void* value);
void free_vec(Vec* a);

#endif //XML_PARSER_VEC_H
