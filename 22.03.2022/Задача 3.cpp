
#include <iostream>

void my_personal_swap(int* ip_1, int* ip_2) {
	if (ip_1 == nullptr || ip_2 == nullptr) {
		return;
	}
	else {
		int tmp = *ip_1;
		* ip_1 = * ip_2;
		* ip_2 = tmp;
	}
}

int main() {
	int num_1;
	int num_2;

	std::cin >> num_1 >> num_2;

	my_personal_swap(&num_1, &num_2);
	std::cout << num_1 << " " << num_2 << std::endl;
	my_personal_swap(&num_1, nullptr);

	my_personal_swap(nullptr, &num_2);
	my_personal_swap(nullptr, nullptr);

	return 0;
}