#include <iostream>

int** input_positions(int& black_n, int& w_x, int& w_y) {
    std::cin >> black_n;

    char letters[8] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h' };
    char numbers[8] = { '1', '2', '3', '4', '5', '6', '7', '8' };

    int** black_positions = new int* [2];

    for (int i = 0; i != 2; i++) {
        black_positions[i] = new int[black_n];
    }

    for (int i = 0; i != 2; i++) {
        for (int j = 0; j != black_n; j++) {
            black_positions[i][j] = 0;
        }
    }

    char b_coord[2] = { 0 };

    for (int j = 0; j != black_n; j++) {
        std::cin >> b_coord[0] >> b_coord[1];
        for (int k = 0; k != 8; k++) {
            if (b_coord[0] == letters[k]) {
                black_positions[0][j] = k;
            }
        }
        for (int l = 0; l != 8; l++) {
            if (b_coord[1] == numbers[l]) {
                black_positions[1][j] = 7 - l;
            }
        }
    }

    char w_coord[2] = { 0 };
    std::cin >> w_coord[0] >> w_coord[1];

    for (int k = 0; k != 8; k++) {
        if (w_coord[0] == letters[k]) {
            w_x = k;
        }
    }
    for (int l = 0; l != 8; l++) {
        if (w_coord[1] == numbers[l]) {
            w_y = 7 - l;
        }
    }

    int** square = new int* [8];
    for (int i = 0; i != 8; i++) {
        square[i] = new int[8];
    }

    for (int i = 0; i != 8; i++) {
        for (int j = 0; j != 8; j++) {
            square[i][j] = 0;
        }
    }

    for (int i = 0; i != black_n; i++) {
        square[black_positions[1][i]][black_positions[0][i]] = 1;
    }

    for (int i = 0; i != 2; i++) {
        delete[] black_positions[i];
    }

    delete[] black_positions;

    return square;
}


int find_ways(int w_x, int w_y, int** square) {
    int sum = 0;
    int** ways = new int* [8];

    for (int i = 0; i != 8; i++) {
        ways[i] = new int[8];
    }

    for (int i = 0; i != 8; i++) {
        for (int j = 0; j != 8; j++) {
            ways[i][j] = 0;
        }
    }

    ways[w_y][w_x] = 1;

    for (int i = w_y; i > 0; i--) {
        for (int j = 0; j < 8; j++) {
            if (ways[i][j] != 0) {
                if (square[i - 1][j - 1] != 0 && j != 0 && i != 0) {
                    ways[i - 1][j - 1]++;
                }
                if (square[i - 1][j + 1] != 0 && j != 7 && i != 0) {
                    ways[i - 1][j + 1]++;
                }
                if (square[i - 1][j] == 0 && i != 0) {
                    ways[i - 1][j]++;
                }
            }
        }
    }

    for (int j = 0; j != 8; j++) {
        sum += ways[0][j];
    }

    for (int i = 0; i != 8; i++) {
        delete[] ways[i];
    }

    delete[] ways;

    return sum;
}

void delete_square(int** square) {
    for (int i = 0; i != 8; i++) {
        delete[] square[i];
    }

    delete[] square;
}

int main() {
    int black_n = 0;
    int w_x = 0;
    int w_y = 0;
    int** square = input_positions(black_n, w_x, w_y);
    std::cout << find_ways(w_x, w_y, square) << std::endl;
    delete_square(square);


    return 0;
}