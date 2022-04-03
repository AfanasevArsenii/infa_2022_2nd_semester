#include <iostream>
#include <string>

struct STUDENT {
    std::string NAME;
    std::string SURNAME;
    int GROUP;
    int SES[5] = { 0 };
};

void student_input(STUDENT STUD1[], int const student_quant) {
    for (int i = 0; i != student_quant; i++) {
        std::cin >> STUD1[i].SURNAME;
        std::cin >> STUD1[i].NAME;
        std::cin >> STUD1[i].GROUP;
        for (int j = 0; j != 5; j++) {
            std::cin >> STUD1[i].SES[j];
        }
    }
}

void student_sort(STUDENT STUD1[], int const student_quant) {
    for (int i = 0; i != student_quant; i++) {
        for (int j = 0; j != student_quant - 1; j++) {
            if (STUD1[j].SURNAME.compare(STUD1[j + 1].SURNAME) == 1) {
                STUDENT tmp = STUD1[j];
                STUD1[j] = STUD1[j + 1];
                STUD1[j + 1] = tmp;
            }
        }
    }
}

void student_output(STUDENT STUD1[], int num) {
    std::cout << STUD1[num].SURNAME << " " << STUD1[num].NAME << " " << STUD1[num].GROUP << std::endl;
}

void none_message_output() {
    std::cout << "There is no student with mark 2" << std::endl;
}

void student_2_mark(STUDENT STUD1[], int const student_quant) {
    int bad_marks = 0;
    for (int i = 0; i != student_quant; i++) {
        for (int j = 0; j != 5; j++) {
            if (STUD1[i].SES[j] == 2) {
                student_output(STUD1, i);
                bad_marks++;
                break;
            }
        }
    }
    if (bad_marks == 0) {
        none_message_output();
    }
}

int main()
{
    int const student_quant = 10;
    STUDENT STUD1[student_quant];

    student_input(STUD1, student_quant);

    student_sort(STUD1, student_quant);

    student_2_mark(STUD1, student_quant);

    return 0;
}