#include <iostream>
#include <string>

struct STUDENT {
    std::string NAME;
    std::string SURNAME;
    unsigned int AGE = 0;
    int FORM = 0;
    int MARKS_QUANT = 0;
    unsigned int* MARKS = { 0 };
};

void student_input(STUDENT STUD1[], int const student_quant) {
    for (int i = 0; i != student_quant; i++) {
        std::cin >> STUD1[i].NAME;
        std::cin >> STUD1[i].SURNAME;
        std::cin >> STUD1[i].AGE;
        std::cin >> STUD1[i].FORM;
        std::cin >> STUD1[i].MARKS_QUANT;
        STUD1[i].MARKS = new unsigned int[STUD1[i].MARKS_QUANT];
        for (int j = 0; j != STUD1[i].MARKS_QUANT; j++) {
            std::cin >> STUD1[i].MARKS[j];
        }
    }
}

int count_marks(STUDENT& s, int mark) {
    int sum = 0;
    int add_marks_quant = 0;
    for (int i = 0; i != s.MARKS_QUANT; i++) {
        sum += s.MARKS[i];
    }
    float average = 1.f * sum / s.MARKS_QUANT;

    while (average < 4.5) {
        sum += mark;
        add_marks_quant++;
        average = 1.f * sum / (s.MARKS_QUANT + add_marks_quant);
    }
    return add_marks_quant;
}

void add_mark(STUDENT& s, int mark) {
    int add_marks_quant = count_marks(s, mark);
    
    unsigned int* new_marks = new unsigned int[s.MARKS_QUANT + add_marks_quant];
    
    for (int i = 0; i != (s.MARKS_QUANT); i++) {
        new_marks[i] = s.MARKS[i];
    }

    for (int i = s.MARKS_QUANT; i != s.MARKS_QUANT + add_marks_quant; i++) {
        new_marks[i] = mark;
    }

    delete[] s.MARKS;

    s.MARKS_QUANT += add_marks_quant;

    s.MARKS = new_marks;
} 

void student_rise_mark(STUDENT STUD1[], int const student_quant) {
    for (int i = 0; i != student_quant; i++) {
        add_mark(STUD1[i], 5);
    }
}

void student_output(STUDENT STUD1[], int const student_quant) {
    for (int i = 0; i != student_quant; i++) {
        std::cout << STUD1[i].NAME << " " << STUD1[i].SURNAME << " " << STUD1[i].AGE << " " << STUD1[i].FORM << " " << STUD1[i].MARKS_QUANT << std::endl;
        for (int j = 0; j != STUD1[i].MARKS_QUANT; j++) {
            std::cout << STUD1[i].MARKS[j] << " ";
        }
        std::cout << std::endl;
    }   
}

int main()
{
    int const student_quant = 5;
    STUDENT STUD1[student_quant];

    student_input(STUD1, student_quant);
    student_rise_mark(STUD1, student_quant);
    student_output(STUD1, student_quant);

    return 0;
}
