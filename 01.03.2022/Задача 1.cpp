#include <iostream>

void out_num() {
	int a;
	std::cin >> a;

	if (a == 0) {
		return;
	}

	if (a % 2 != 0) {
		std::cout << a << std::endl;	
	}

	out_num();
}

int main() {
	out_num();
	return 0;
}