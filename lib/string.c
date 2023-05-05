#include <malloc.h>
#include <memory.h>
#include "string.h"

void init_str(String* s, size_t initial_size) {
    s->data = malloc(initial_size * sizeof(char*));
    s->length = 0;
    s->capacity = initial_size;
}

void append_to(String *v, char value) {
    if (v->length == v->capacity) {
        size_t new_capacity = v->capacity * 2;
        char* tmp = realloc(v->data, new_capacity * sizeof(char*));

        if (!tmp)
            return;

        v->data = tmp;
        v->capacity *= new_capacity;
    }

    v->data[v->length++] = value;
}

void clear_str(String *s) {
    s->data = malloc(sizeof(char*));
    s->length = 0;
    s->capacity = 1;
}

void free_str(String *s) {
    free(s->data);
    s->data = NULL;
    s->length = s->capacity = 0;
}

char* str(String *s) {
    char* tmp = malloc((s->length + 1) * sizeof(char*));

    memcpy(tmp, s->data, s->length);
    tmp[s->length] = '\0';

    return tmp;
}
