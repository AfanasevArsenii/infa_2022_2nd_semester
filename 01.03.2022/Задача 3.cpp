#include <iostream>

void out_num(int &sum, int &n) {
	int a;
	std::cin >> a;

	if (a == 0) {
		std::cout << double(sum) / n << std::endl;
		return;
	}

	sum += a;
	n++;

	out_num(sum, n);
}

int main() {
	int sum = 0;
	int n = 0;

	out_num(sum, n);

	return 0;
}