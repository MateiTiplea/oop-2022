#define _CRT_SECURE_NO_WARNINGS
#include "MyLibrary.h"
#include <cstring>
#include <cstdarg>
#include <cstdlib>
#include <time.h>
#include <cstdio>

MyLibrary::MyLibrary(std::ostream& output_stream) : output_stream(output_stream) {
    books_count = -1;
    books = new int;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int* books) : output_stream(output_stream) {
    this->books = new int[books_count];
    this->books_count = books_count;
    for (int i = 0; i < books_count; i++) {
        this->books[i] = books[i];
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, int min, int max)
    : output_stream(output_stream) {
    this->books_count = books_count;
    this->books = new int[books_count];
    srand(time(NULL));
    for (int i = 0; i < books_count; i++) {
        this->books[i] = min + rand() % (max - min + 1);
    }
}

MyLibrary::MyLibrary(std::ostream& output_stream, const char* books_values) : output_stream(output_stream) {
    char* p;
    char* sir;
    sir = new char[strlen(books_values) + 1];
    strcpy(sir, books_values);
    int contor = 0;
    for (int i = 0; i < strlen(sir); i++)
        if (sir[i] == ';')
            contor++;
    contor++;
    this->books = new int[contor];
    books_count = contor;
    int contor2 = 0;
    p = strtok(sir, ";");
    while (p != NULL) {
        this->books[contor2++] = atoi(p);
        p = strtok(NULL, ";");
    }
    delete[] sir;
}

MyLibrary::MyLibrary(std::ostream& output_stream, unsigned books_count, ...) : output_stream(output_stream) {
    va_list args;
    va_start(args, books_count);
    this->books_count = books_count;
    this->books = new int[books_count];
    for (int i = 0; i < books_count; i++) {
        this->books[i] = va_arg(args, int);
    }
    va_end(args);
}

MyLibrary::MyLibrary(const MyLibrary& other) : output_stream(other.output_stream) {
    this->books_count = other.books_count;
    this->books = new int[this->books_count];
    for (int i = 0; i < this->books_count; i++)
        this->books[i] = other.books[i];
}

MyLibrary::~MyLibrary() {
    delete[] books;
}

void MyLibrary::print_books() const {
    if (this->books_count == -1)
        output_stream << -1 << "\n";
    else {
        for (int i = 0; i < books_count; i++)
            output_stream << books[i] << " ";
        output_stream << "\n";
    }
}

void MyLibrary::update_book_id_by_index(unsigned book_index, int book_id) {
    if (book_index < books_count) {
        books[book_index] = book_id;
    }
}

int MyLibrary::get_books_count() const {
    return this->books_count;
}

int MyLibrary::get_book_id_by_index(int index) const {
    if (index<books_count)
        return this->books[index];
    return -1;
}
