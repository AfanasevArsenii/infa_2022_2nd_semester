#include <iostream>
#include <ctime>
#include <cstdlib>

void array_generate(int arr[], int lenth) {
    
    srand(static_cast<unsigned int> (time(0)));
    
    for (int i = 0; i < lenth; i++) {
        arr[i] = rand() % (100);
    }
}

void change_pos(int arr[], int num_1, int num_2) {
    int tmp = arr[num_1];
    arr[num_1] = arr[num_2];
    arr[num_2] = tmp;
}

void sort_triangle(int arr[], int quant, int num){
    
    int parent = num;
    int son_left = 2 * num + 1;
    int son_right = 2 * num + 2;

    if (son_left < quant && arr[son_left] < arr[parent]) {
        parent = son_left;
    }

    if (son_right < quant && arr[son_right] < arr[parent]) {
        parent = son_right;
    }

    if (parent != num){
        change_pos(arr, num, parent);
        sort_triangle(arr, quant, parent);
    }
    else{
        return;
    }
}

void array_out(int arr[], int lenth)
{
    for (int i = 0; i < lenth; ++i)
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void sort_all(int arr[], int lenth)
{
    for (int i = lenth / 2 - 1; i >= 0; i--) {
        sort_triangle(arr, lenth, i);
    }

    for (int i = lenth - 1; i >= 0; i--){
        change_pos(arr, 0, i);
        sort_triangle(arr, i, 0);
    }
}

int main()
{
    int const lenth = 50;
    int arr[lenth] = {0};

    array_generate(arr, lenth);
    sort_all(arr, lenth);
    array_out(arr, lenth);

    return 0;
}