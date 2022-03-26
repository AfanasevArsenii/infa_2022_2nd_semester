#include <iostream>

int* my_slightly_dumb_reallocation(int* source, unsigned int n_old, unsigned int n_new) {
	int* new_arr = new int[n_new];
	if (source != NULL) {
		for (unsigned int i = 0; i != n_new; i++) {
			if (i < n_old) {
				new_arr[i] = *(source + i);
			}
			else {
				new_arr[i] = 0;
			}
		}
		delete[] source;
	}
	return new_arr;
}


int main() {
	unsigned int n, i;
	std::cin >> n;

	int* a = my_slightly_dumb_reallocation(NULL, 0, n / 2);
	for (i = 0; i < n / 2; i++)
		std::cin >> a[i];
	a = my_slightly_dumb_reallocation(a, n / 2, n);
	for (; i < n; i++)
		std::cin >> a[i];
	int sum = 0;
	for (i = 0; i < n; i++)
		sum += a[i];
	std::cout << sum << std::endl;
	a = my_slightly_dumb_reallocation(a, n, n / 2);
	a = my_slightly_dumb_reallocation(a, n / 2, 0);
	a = my_slightly_dumb_reallocation(a, 0, 0);

	return 0;
}