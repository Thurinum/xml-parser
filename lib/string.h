#ifndef XML_PARSER_STRING_H
#define XML_PARSER_STRING_H

#include <corecrt.h>

typedef struct {
    char* data;
    size_t length;
    size_t capacity;
} String;

void init_str(String* s, size_t initial_size);
char* str(String *s);
void append_to(String* s, char value);
void clear_str(String* s);
void free_str(String* s);

#endif //XML_PARSER_STRING_H
