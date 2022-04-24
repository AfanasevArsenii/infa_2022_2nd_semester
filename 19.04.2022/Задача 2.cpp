#include <iostream>

int* input_platforms(int& n) {
    std::cin >> n;

    int* platforms = new int[n];

    for (int i = 0; i != n; i++) {
        std::cin >> platforms[i];
    }

    return platforms;
}

int find_energy(int n, int* platforms) {
    int* counters = new int[n];
    int energy = 0;

    if (n == 1) {
        return 0;
    }

    counters[0] = 0;
    counters[1] = abs(platforms[1] - platforms[0]);

    for (int i = 2; i != n; i++) {
        int h21 = abs(platforms[i] - platforms[i - 1]);
        int h31 = 3 * abs(platforms[i] - platforms[i - 2]);
        int possible21 = counters[i - 1] + h21;
        int possible31 = counters[i - 2] + h31;
        if (possible21 <= possible31) {
            counters[i] = possible21;
        }
        else {
            counters[i] = possible31;
        }
    }

    energy = counters[n - 1];

    delete[] counters;

    return energy;
}

int main() {
    int n = 0;

    int* platforms = input_platforms(n);
    int energy = find_energy(n, platforms);
    std::cout << energy << std::endl;

    delete[] platforms;

    return 0;
}