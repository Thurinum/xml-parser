#include <malloc.h>
#include "vec.h"

void init_vec(Vec* v, size_t initial_size) {
    v->data = malloc(initial_size * sizeof(void *));
    v->length = 0;
    v->capacity = initial_size;
}

void append_to(Vec *v, void *value) {
    if (v->length == v->capacity) {
        size_t new_capacity = v->capacity * 2;
        void** tmp = realloc(v->data, new_capacity * sizeof(void *));

        if (!v->data)
            v->data = tmp;
        else
            return;

        v->capacity *= new_capacity;
    }

    v->data[v->length++] = value;
}

void clear_vec(Vec *v) {
    v->data = malloc(sizeof(void *));
    v->length = 0;
    v->capacity = 1;
}

void free_vec(Vec *v) {
    free(v->data);
    v->data = NULL;
    v->length = v->capacity = 0;
}
