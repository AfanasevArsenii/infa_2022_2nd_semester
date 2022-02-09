#include <iostream>


signed int check(signed int num_1_check, signed int num_2_check, signed int count_check) {
	if (num_2_check > num_1_check)
		count_check++;

	return count_check;
}

int main() {
	signed int num_1, num_2, count;
	count = 0;
	num_2 = 0;
	
	do {
		std::cin >> num_1;
		if (num_1 == 0) {
			break;
		}
		else {
			count = check(num_1, num_2, count);
			num_2 = num_1;
		}
	} while (num_1 != 0);

	std::cout << count << std::endl;

	return 0;
}