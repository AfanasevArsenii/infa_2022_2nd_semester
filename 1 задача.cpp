#include <iostream>

signed int check(signed int a1, signed int max1) {
    if (a1 % 2 == 0 && a1 >= max1 && a1 != 0) {
        max1 = a1;
    }
    return max1;
}

int main() {
    signed int a, max;
    
    max = 0;
    do {
        std::cin >> a;
        max = check(a, max);
    } while (a != 0);

    std::cout << max << std::endl;

    return 0;
}