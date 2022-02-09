#include <iostream>

using namespace std;

int max_1, max_2, min_1, min_2;

void check_max(int num_1_check) {
	if (num_1_check >= max_1 && num_1_check <= max_2) {
		max_1 = num_1_check;
	}
	else{
		if (num_1_check >= max_2) {
			max_1 = max_2;
			max_2 = num_1_check;
		}
	}
}

void check_min(int num_1_check) {
	if (num_1_check <= min_1 && num_1_check >= min_2) {
		min_1 = num_1_check;
	}
	else {
		if (num_1_check <= min_2) {
			min_1 = min_2;
			min_2 = num_1_check;
		}
	}
}

void first_check(int num_1_check, int num_2_check) {
	if (num_1_check > num_2_check) {
		max_1 = num_2_check;
		max_2 = num_1_check;
	}
	else {
		max_1 = num_1_check;
		max_2 = num_2_check;
	}
	min_1 = max_2;
	min_2 = max_1;
}


int main() {
	int num_1, num_2, N;
	max_2 = 0;
	min_1 = 0;
	min_2 = 0;

	cin >> N;

	if (N == 0) {
		max_1 = 0;
	}
	else {
		if (N == 1) {
			cin >> min_1;
			max_1 = min_1;
		}
		else {
			cin >> num_1;
			cin >> num_2;
			first_check(num_1, num_2);

			for (int i = 3; i <= N; i++) {
				cin >> num_1;
				check_max(num_1);
				check_min(num_1);
			}
		}
	}


	cout << "SUMMAX:" << max_1 + max_2 << endl;
	cout << "SUMMIN:" << min_1 + min_2 << endl;
	return 0;
}