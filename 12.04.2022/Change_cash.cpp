#include <iostream>

int* input_set(int & num) {
    std::cout << "Enter the number of different coins: ";
    std::cin >> num;
    int* coins_set = new int[num];
    std::cout << "Enter the value of coins: ";
    for (int i = 0; i != num; i++) {
        std::cin >> coins_set[i];
    }

    return coins_set;
}

int* input_num(int& num) {
    int* coins_num = new int[num];
    for (int i = 0; i != num; i++) {
        coins_num[i] = 0;
    }
    return coins_num;
}

void input_cash(int & cash) {
    std::cout << "Enter cash: ";
    std::cin >> cash;
}


void change_cash(int & cash, int & num, int* coins_set, int* coins_num) {
    if (cash == 0) {
        return;
    }
    if (cash < coins_set[num - 1]) {
        num--;
    }
    if (cash >= coins_set[num - 1]) {
        cash -= coins_set[num - 1];
        coins_num[num - 1]++;
    }
    change_cash(cash, num, coins_set, coins_num);
}

void output_change(int num, int* coins_set, int* coins_num) {
    for (int i = 0; i != num; i++) {
        std::cout << coins_set[i] << " " << coins_num[i] << std::endl;
    }
}


int main() {
    int num;
    int cash;
    int* coins_set = input_set(num);
    int* coins_num = input_num(num);
    input_cash(cash);
    int num1 = num;
    change_cash(cash, num, coins_set, coins_num);
    output_change(num1, coins_set, coins_num);

    return 0;
}