#include <malloc.h>
#include "vec.h"

void new_vec(Vec *a, size_t initialSize) {
    a->data = malloc(initialSize * sizeof(void *));
    a->length = 0;
    a->capacity = initialSize;
}

void append_to_vec(Vec *a, void *value) {
    if (a->length == a->capacity) {
        a->capacity *= 2;
        a->data = realloc(a->data, a->capacity * sizeof(void *));
    }

    a->data[a->length++] = value;
}

void free_vec(Vec *a) {

}
