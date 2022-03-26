#include <iostream>

int choose(int slippers[], int N) {
    int min_dist = N+1;
    for (int i = 0; i != N; i++) {
        if (slippers[i] < 0) {
            for (int j = i + 1; j != N; j++) {
                if (slippers[i] == -slippers[j]) {
                    if (j - i < min_dist) {
                        min_dist = j - i;
                    }
                }
                
            }
        }
    }
    if (min_dist == N + 1) {
        min_dist = 0;
    }
    return min_dist;
}

int main() {
    int N = 0;

    std::cin >> N;
    int* slippers = new int[N];
    for (int i = 0; i != N; i++) {
        std::cin >> slippers[i];
    }

    std::cout << choose(slippers, N) << std::endl;

    delete[] slippers;
    return 0;
}