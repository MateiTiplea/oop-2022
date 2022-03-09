#include "allocator.h"
#include <cstdlib>
#include <cstring>

void* Allocator::alloc_raw(unsigned size) {
    char* s = buffer + offset;
    offset += size;
    return s;
}

Allocator::Allocator(unsigned max_size) {
    buffer = (char*) malloc(max_size);
    offset = 0;
    this->max_size = max_size;
}

Allocator::~Allocator() {
    free(buffer);
}

#define makefunction(type)                                                                                             \
    type* Allocator::alloc(type x) {                                                                                   \
        type* p = (type*) alloc_raw(sizeof(x));                                                                        \
        *p = x;                                                                                                        \
        return p;                                                                                                      \
    }

makefunction(unsigned);
makefunction(int);
makefunction(float);
makefunction(double);
makefunction(char);

char* Allocator::alloc(const char* string) {
    int l = strlen(string);
    char* p = (char*) alloc_raw(l + 1);
    memcpy(p, string, l + 1);
    return p;
}
