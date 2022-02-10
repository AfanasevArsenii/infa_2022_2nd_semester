#include <iostream>

int main() {
	double a1, b1, c1, a2, b2, c2;
	int x, y;
	std::cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;

	if (a1 == a2 && b1 == b2 && c1 == c2) {
		std::cout << "The same" << std::endl;
	}
	if (a1 * b2 == b1 * a2) {
		std::cout << "No" << std::endl;
	}
	else {
		x = ((b1 / b2) * c2 - c1) / (a1 - (b1 / b2) * a2);
		y = (- c1 * (a1 - b1 / b2 * a2) - a1 * b1 / b2 * c2 + c1 * a1) / (b1 * (a1 - (b1 / b2) * a2));
		std::cout << "(" << x << ";" << y << ")" << std::endl;
	}
	return 0;
}
