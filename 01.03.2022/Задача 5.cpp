#include <iostream>

void out_num(int &n, int &last, int &num) {

	if (n < 10) {
		last = n;
		num = num * 10 + last;
		std::cout << num << std::endl;
		return;
	}

	last = n % 10;
	n = (n - last ) / 10;
	num = num * 10 + last;

	out_num(n, last, num);
}

int main() {
	int last = 0;
	int num = 0;
	int n;
	std::cin >> n;

	out_num(n, last, num);
	return 0;
}