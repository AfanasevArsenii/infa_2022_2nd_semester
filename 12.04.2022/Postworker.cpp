#include <iostream>

int** input_dist(int& num, int& start) {
    std::cout << "Enter the number of cities: ";
    std::cin >> num;

    int j = 0;

    int** dist = new int* [num];
    for (int i = 0; i < num; i++) {
        dist[i] = new int[num];
    }

    for (int i = 0; i < num; i++) {
        j = i;
        while (j < num) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else {
                std::cin >> dist[i][j];
            }
            j++;
        }
    }

    for (int i = num - 1; i >= 0; i--) {
        j = i - 1;
        while (j >= 0) {
            dist[i][j] = dist[j][i];
            j--;
        }
    }

    std::cout << "Enter the number of start city: ";
    std::cin >> start;

    return dist;
}

int* input_was(int num) {
    int* was = new int[num];
    for (int i = 0; i != num; i++) {
        was[i] = 1;
    }
    return was;
}

void find_column(int num, int** dist, int current, int& min, int was[]) {
    for (int k = 0; k < num; k++) {
        min = k;
        if (dist[current][k] != 0) {
            break;
        }
    }

    for (int j = min; j != num; j++) {
        if (dist[current][min] >= dist[current][j] && dist[current][j] != 0) {
            min = j;
        }
    }
}

void find_row(int num, int** dist, int current, int& min, int was[]) {

    for (int k = 0; k < num; k++) {
        min = k;
        if (dist[k][current] != 0) {
            break;
        }
    }

    for (int i = min; i != num; i++) {
        if (dist[min][current] >= dist[i][current] && dist[i][current] != 0) {
            min = i;
        }
    }
}

void output_dist(int num, int** dist) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            std::cout << dist[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int summary(int num, int was[]) {
    int sum = 0;
    for (int i = 0; i != num; i++) {
        sum += was[i];
    }
    return sum;
}
int* choose_way(int start, int num, int** dist, int was[]) {
    int current = start;
    int* way = new int[num];
    int k = 0;
    int min = 0;
    int sum = summary(num, was);
    int position = 1;


    do {
        if (position == -1) {
            find_column(num, dist, current, min, was);
            for (int i = 0; i != num; i++) {
                dist[i][current] = 0;
            }
            for (int j = 0; j != num; j++) {
                dist[current][j] = 0;
            }
        }
        if (position == 1) {
            find_row(num, dist, current, min, was);
            for (int i = 0; i != num; i++) {
                dist[i][current] = 0;
            }
            for (int j = 0; j != num; j++) {
                dist[current][j] = 0;
            }
        }

        way[k] = current;
        was[current] = 0;

        sum = summary(num, was);

        if (sum != 1) {
            current = min;
        }

        position = position * (-1);
        k++;

    } while (sum != 1);

    way[k] = min;

    return way;
}

void output_way(int num, int* way) {
    for (int i = 0; i != num; i++) {
        std::cout << way[i] << " ";
    }
    std::cout << std::endl;
}

void delete_dist(int num, int** dist) {
    for (int i = 0; i < num; i++) {
        delete[] dist[i];
    }
    delete[] dist;
}

int main() {
    int num = 0;
    int start = 0;
    int** dist = input_dist(num, start);
    int* was = input_was(num);

    int* way = choose_way(start, num, dist, was);

    output_way(num, way);

    delete_dist(num, dist);


    return 0;
}