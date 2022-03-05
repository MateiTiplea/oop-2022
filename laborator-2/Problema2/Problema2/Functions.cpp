#define _CRT_SECURE_NO_WARNINGS
#include "Functions.h"
#include <cstring>

int CompareName(const Student stud1, const Student stud2) {
    return strcmp(stud1.GetName(), stud2.GetName());
}

int CompareMath(const Student stud1, const Student stud2) {
    if (stud1.GetMath() > stud2.GetMath())
        return 1;
    if (stud1.GetMath() == stud2.GetMath())
        return 0;
    if (stud1.GetMath() < stud2.GetMath())
        return -1;
}

int CompareEnglish(const Student stud1, const Student stud2) {
    if (stud1.GetEnglish() > stud2.GetEnglish())
        return 1;
    if (stud1.GetEnglish() == stud2.GetEnglish())
        return 0;
    if (stud1.GetEnglish() < stud2.GetEnglish())
        return -1;
}

int CompareHistory(const Student stud1, const Student stud2) {
    if (stud1.GetHistory() > stud2.GetHistory())
        return 1;
    if (stud1.GetHistory() == stud2.GetHistory())
        return 0;
    if (stud1.GetHistory() < stud2.GetHistory())
        return -1;
}

int CompareAvg(Student stud1, Student stud2) {
    if (stud1.Avg() > stud2.Avg())
        return 1;
    if (stud1.Avg() == stud2.Avg())
        return 0;
    if (stud1.Avg() < stud2.Avg())
        return 1;
}
