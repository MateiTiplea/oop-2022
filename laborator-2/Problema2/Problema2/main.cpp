#include "Student.h"
#include "Functions.h"
#include <iostream>

int main() {
    Student stud1;
    stud1.SetName("Gigi");
    if (!stud1.SetMath(4.56))
        std::cout << "Nota nu este corecta !!!\n";
    if (!stud1.SetEnglish(8.95))
        std::cout << "Nota nu este corecta !!!\n";
    if (!stud1.SetHistory(9.76))
        std::cout << "Nota nu este corecta !!!\n";
    Student stud2;
    stud2.SetName("Marcel");
    if (!stud2.SetMath(6.1))
        std::cout << "Nota nu este corecta !!!\n";
    if (!stud2.SetEnglish(8.95))
        std::cout << "Nota nu este corecta !!!\n";
    if (!stud2.SetHistory(4.3))
        std::cout << "Nota nu este corecta !!!\n";
    std::cout << CompareName(stud1, stud2) << " " << CompareMath(stud1, stud2) << " " << CompareEnglish(stud1, stud2)
              << " " << CompareHistory(stud1, stud2) << " " << CompareAvg(stud1, stud2);
    return 0;
}