#include <iostream>

void out_num(int &num_max, int &counter) {
	int a;
	std::cin >> a;

	if (a == 0) {
		std::cout << counter << std::endl;
		return;
	}

	if (a == num_max) {
		counter++;
	}

	if (a > num_max) {
		num_max = a;
		counter = 1;
	}

	out_num(num_max, counter);
}

int main() {
	int num_max = 0;
	int counter = 0;

	out_num(num_max, counter);
	return 0;
}