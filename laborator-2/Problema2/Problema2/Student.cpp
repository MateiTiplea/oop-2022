#define _CRT_SECURE_NO_WARNINGS
#include "Student.h"
#include <cstring>
Student::Student() {
    name[0] = '\n';
    Math = 0.0;
    English = 0.0;
    History = 0.0;
    Average = 0.0;
}
void Student::SetName(const char* name) {
    strcpy(this->name, name);
}

const char* Student::GetName() const {
    return name;
}

bool Student::SetMath(const float Math) {
    if (Math > 10 || Math < 1)
        return false;
    this->Math = Math;
    return true;
}

const float Student::GetMath() const {
    return this->Math;
}

bool Student::SetEnglish(const float English) {
    if (English > 10 || English < 1)
        return false;
    this->English = English;
    return true;
}

const float Student::GetEnglish() const {
    return this->English;
}

bool Student::SetHistory(const float History) {
    if (History > 10 || History < 1)
        return false;
    this->History = History;
    return true;
}

const float Student::GetHistory() const {
    return this->History;
}

const float Student::Avg() {
    Average = (Math + English + History) / 3;
    return Average;
}
