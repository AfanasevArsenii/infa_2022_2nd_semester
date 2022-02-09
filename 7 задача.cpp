#include <iostream>

int count_1, count_2, count_3, count_4, num_max;

void count_fun(int x1, int y1) {
	if (x1 > 0 && y1 > 0)
		count_1++;
	if (x1 < 0 && y1 > 0)
		count_2++;
	if (x1 < 0 && y1 < 0)
		count_3++;
	if (x1 > 0 && y1 < 0)
		count_4++;
}

int find_fun() {
	int max1 = 0;

	if (count_1 > max1) {
		max1 = count_1;
		num_max = 1;
	}
	if (count_2 > max1) {
		max1 = count_2;
		num_max = 2;
	}
	if (count_3 > max1) {
		max1 = count_3;
		num_max = 3;
	}
	if (count_4 > max1) {
		max1 = count_4;
		num_max = 4;
	}

	return max1;
}

int main() {
	int x, y, N, max;

	count_1 = 0;
	count_2 = 0;
	count_3 = 0;
	count_4 = 0;
	num_max = 0;

	std::cin >> N;
	for (int i = 1; i <= N; i++) {
		std::cin >> x >> y;
		count_fun(x, y);
	}
	max = find_fun();

	std::cout << "Square: " << num_max << " Number of points: " << max << std::endl;

	return 0;
}
