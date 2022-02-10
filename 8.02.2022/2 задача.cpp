#include <iostream>

int counter;

int check_min(int a1, int min1) {
	if (a1 == min1) {
		counter++;
	}
	if (a1 < min1) {
		min1 = a1;
		counter = 1;
	}

	return min1;
}
int main() {
	int a;
	int N;
	int min;
    counter = 1;

	std::cin >> N;

	if (N <= 0) {
		std::cout << "No numbers" << std::endl;
	}
	else {
		std::cin >> min;
		for (int i = 2; i <= N; i++) {
			std::cin >> a;
			min = check_min(a, min);
		}

		std::cout << min << " " << counter << std::endl;
	}

	return 0;
}
