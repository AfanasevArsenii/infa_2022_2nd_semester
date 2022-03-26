#include <iostream>

void change(int N, int numbers[]) {
    int comp1 = 0;
    int comp2 = 0;
    
    if (N % 2 == 0) {
        comp1 = 1;
        comp2 = 0;
    }
    else {
        comp1 = 0;
        comp2 = 1;
    }

    for (int i = N - 1; i >= 0; i--) {
        if (i % 2 == comp1) {
            std::cout << numbers[i] << " ";
        }
    }
    for (int i = N - 1; i >= 0; i--) {
        if (i % 2 == comp2) {
            std::cout << numbers[i] << " ";
        }
    }
}

int main(){
    int N = 0;

    std::cin >> N;
    int* numbers = new int[N];
    for (int i = 0; i != N; i++) {
        std::cin >> numbers[i];
    }

    change(N, numbers);

    delete[] numbers;

    return 0;
}