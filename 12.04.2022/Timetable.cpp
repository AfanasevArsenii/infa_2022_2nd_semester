#include <iostream>


int** time_input(int& num) {
    std::cout << "Enter the numper of applications: ";
    std::cin >> num;

    std::cout << "Enter START and END time: ";
    int** timetable = new int* [3];
    for (int i = 0; i < 3; i++) {
        timetable[i] = new int[num];
    }

    for (int j = 0; j < num; j++) {
        timetable[0][j] = j+1;
        for (int i = 1; i < 3; i++) {
            std::cin >> timetable[i][j];
        }
    }
    return timetable;
}

void sort_time_end(int num, int** timetable) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - 1; j++) {
            if (timetable[2][j] > timetable[2][j + 1]) {
                int b = timetable[1][j];
                int e = timetable[2][j];
                int n = timetable[0][j];
                timetable[1][j] = timetable[1][j + 1];
                timetable[1][j + 1] = b;
                timetable[2][j] = timetable[2][j + 1];
                timetable[2][j + 1] = e;
                timetable[0][j] = timetable[0][j + 1];
                timetable[0][j + 1] = n;
            }
        }
    }
}

int find_best(int num, int** timetable) {
    int queue = 1;
    int last_best = 0;
    for (int i = 1; i != num; i++) {
        if (timetable[1][i] >= timetable[2][last_best]) {
            queue++;
            last_best = i;
        }
    }

    return queue;
}

int** choose_best(int num, int queue, int** timetable) {
    int last_best = 0;
    int k = 1;
    int** best_timetable = new int* [3];
    for (int i = 0; i < 3; i++) {
        best_timetable[i] = new int[queue];
    }

    for (int j = 0; j != 3; j++) {
        best_timetable[j][0] = timetable[j][0];
    }

    for (int i = 1; i != num; i++) {
        if (timetable[1][i] >= timetable[2][last_best] && k < queue) {
            for (int j = 0; j != 3; j++) {
                best_timetable[j][k] = timetable[j][i];
            }
            k++;
            last_best = i;

        }
    }

    return best_timetable;
}

void outbut_best(int queue, int** best_timetable) {
    for (int i = 0; i != queue; i++) {
        std::cout << best_timetable[0][i] << ": " << best_timetable[1][i] << " - " << best_timetable[2][i] << std::endl;
    }
}

void delete_timetable(int num, int** timetable) {
    for (int i = 0; i < 3; i++) {
        delete[] timetable[i];
    }
    delete[] timetable;
}

int main(){
    int num = 0;
    int queue;
    int** timetable = time_input(num);
    sort_time_end(num, timetable);
    queue = find_best(num, timetable);
    int** best_timetable = choose_best(num, queue, timetable);
    outbut_best(queue, best_timetable);
    delete_timetable(num, timetable);

    return 0;
}