#include <iostream>
#include <string>

std::string check_in(int x_check, int y_check, int a_check, int b_check, signed int r_check) {
	std::string flag;
	
	if ((x_check - a_check) * (x_check - a_check) + (y_check - b_check) * (y_check - b_check) <= r_check * r_check)
		flag = "YES";
	else
		flag = "NO";

	return flag;
}

int main() {
	int x, y, a, b;
	signed int r;
	
	std::cin >> x;
	std::cin >> y;
	std::cin >> a;
	std::cin >> b;
	std::cin >> r;

	std::cout << check_in(x, y, a, b, r) << std::endl;

	return 0;
}
