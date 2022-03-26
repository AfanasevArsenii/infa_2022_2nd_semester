#include <iostream>

int one_sign(int coloumn_num) {
    if (coloumn_num % 2 == 0) {
        return 1;
    }
    else {
        return -1;
    }
}

int det_count(int n, int matrix[]) {
    int d = 0;
    if (n == 1) {
        return matrix[0];
    }
    int* minor = new int[(n - 1) * (n - 1)];
    for (int row_num = 0; row_num != n; row_num++) {
        for (int k = 0; k != row_num * (n - 1); k++) {
            int i = k / (n - 1);
            int j = k % (n - 1);
            minor[k] = matrix[i * n + j + 1];
        }
        for (int k = row_num * (n - 1); k != (n - 1) * (n - 1); k++) {
            int i = k / (n - 1);
            int j = k % (n - 1);
            minor[k] = matrix[(i + 1) * n + 1 + j];
        }
        d += one_sign(row_num + 1 + 1) * det_count(n - 1, minor) * matrix[row_num * n];
    }
    delete[] minor;
    return d;
}


int main() {
	int n;
	std::cin >> n;
	int* matrix = new int[n * n];
    
    for (int i = 0; i < n * n; i++) {
        std::cin >> matrix[i];
    }
    
    std::cout << det_count(n, matrix) << std::endl;

	delete[] matrix;
	return 0;
}