#include <iostream>

void out_num() {
	int a = 0;
	int b = 0;
	std::cin >> a;
	

	if (a == 0) {
		return;
	}
	else {
		std::cout << a << std::endl;
		std::cin >> b;

		if (b == 0) {
			return;
		}
	}

	out_num();
}

int main() {
	out_num();
	return 0;
}