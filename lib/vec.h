#ifndef XML_PARSER_VEC_H
#define XML_PARSER_VEC_H

#include <corecrt.h>

typedef struct {
    void **data;
    size_t length;
    size_t capacity;
} Vec;

void init_vec(Vec* v, size_t initial_size);
void append_to(Vec* v, void* value);
void clear_vec(Vec* v);
void free_vec(Vec* v);

#endif //XML_PARSER_VEC_H
