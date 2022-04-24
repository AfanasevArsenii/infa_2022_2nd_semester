#include <iostream>

int* input_seq(int& n) {
    std::cin >> n;

    int* seq = new int[n];

    for (int i = 0; i != n; i++) {
        std::cin >> seq[i];
    }

    return seq;
}

int find_subseq(int n, int* seq) {
    int* counters = new int[n];
    int lenth = 1;

    for (int i = 0; i != n; i++) {
        counters[i] = 1;
    }

    for (int i = 1; i != n; i++) {
        for (int j = 0; j != i; j++) {
            if (seq[i] > seq[j]) {
                if (counters[j] >= counters[i]) {
                    counters[i] = counters[j] + 1;
                }
            }
        }
    }

    for (int i = 0; i != n; i++) {
        lenth = std::max(counters[i], lenth);
    }

    delete[] counters;

    return lenth;
}

int main() {
    int n = 0;

    int* seq = input_seq(n);
    int lenth = find_subseq(n, seq);
    std::cout << lenth << std::endl;

    delete[] seq;

    return 0;
}