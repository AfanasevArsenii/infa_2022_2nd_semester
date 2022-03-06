#include <iostream>

int female_fun(int n_fem);

int male_fun(int n_male) {

	if (n_male == 0) {
		return 0;
	}
	else {
		return n_male - female_fun(male_fun(n_male - 1));
	}
}

int female_fun(int n_fem) {

	if (n_fem == 0) {
		return 1;
	}

	else {
		return n_fem - male_fun(female_fun(n_fem - 1));
	}
}

int main() {
	int n;
	std::cin >> n;
	std::cout << female_fun(n) << std::endl;
	std::cout << male_fun(n) << std::endl;
	
	return 0;
}