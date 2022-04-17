#include <iostream>

struct THINGS{
    int num;
    int mass;
    int utility;
    double per_utility;
};

struct BACKPACK {
    //int things_quant = 0;
    int space = 0;
    int size = 0;
    double all_utility = 0;
    THINGS* things = new THINGS[space];
};

THINGS* things_input(int& num) {
    std::cout << "Enter the number of things: ";
    std::cin >> num;

    THINGS* things = new THINGS[num];

    for (int j = 0; j < num; j++) {
        std::cout << "Enter the mass of thing: ";
        std::cin >> things[j].mass;
        std::cout << "Enter the utulity of thing: ";
        std::cin >> things[j].utility;
        things[j].per_utility = double(things[j].utility) / things[j].mass;
        things[j].num = j+1;
    }

    return things;
}

BACKPACK* backpack_input() {
    BACKPACK* backpack = new BACKPACK;
    std::cout << "Enter the size of backpack: ";
    std::cin >> backpack->space;
    backpack->size = backpack->space;
    return backpack;
}

void sort_things(int num, THINGS things[]) {
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num - 1; j++) {
            if (things[j].per_utility < things[j+1].per_utility) {
                THINGS tmp = things[j];

                things[j] = things[j+1]; // меняем местами
                things[j+1] = tmp;
            }
        }
    }

    for (int i = 0; i < num; i++) {
        std::cout << things[i].per_utility << std::endl;
    }
}


void choose_things(int num, THINGS* things, BACKPACK* backpack) {
    int i = 0;
    while (backpack->space != 0 && i < num){
        if (things[i].mass <= backpack->space) {
            backpack->things[i] = things[i];
            backpack->space -= things[i].mass;
            backpack->all_utility += things[i].per_utility * things[i].mass;
        }
        else {
            things[i].mass = backpack->space;
            backpack->things[i] = things[i];
            backpack->space -= things[i].mass;
            backpack->all_utility += things[i].per_utility * things[i].mass;
        }
        i++;
    }


}


void backpack_output(BACKPACK* backpack, int num) {
    for (int i = 0; i != std::min(backpack->size, num); i++) {
        std::cout << "num: " << backpack->things[i].num << " mass: " << backpack->things[i].mass << " per_utility: " << backpack->things[i].per_utility << std::endl;
    }

    std::cout << "all_utility: " << backpack->all_utility << std::endl;
}

int main() {
    int num = 0;
    BACKPACK* backpack = backpack_input();
    THINGS* things = things_input(num);
    sort_things(num, things);
    choose_things(num, things, backpack);
    backpack_output(backpack, num);
    delete[] things;

    return 0;
}