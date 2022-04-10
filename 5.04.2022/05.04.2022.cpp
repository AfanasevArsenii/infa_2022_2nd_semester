#include <iostream>

struct Str {
    int key = 0;
    Str* next = nullptr;
};

void init_FirstStr(Str* & FirstStr, int key_1) {
    if (key_1 == 0) {
        FirstStr = nullptr;
    }
    else {
        FirstStr = new Str;
        FirstStr->key = key_1;
        FirstStr->next = nullptr;
    }
}

void input_list(Str* & FirstStr) {
    int key;
    std::cin >> key;

    init_FirstStr(FirstStr, key);
    Str* pt_prev = FirstStr;
    Str* pt = FirstStr;

    while (pt != nullptr) {
        if (pt->key == 0) {
            pt = nullptr;
            pt_prev->next = nullptr;
        }
        else {
            pt->next = new Str;
            pt_prev = pt;
            pt = pt->next;
            std::cin >> pt->key;
        }
    }
}

void find_place(Str* AddedStr, Str* FirstStr, Str* & SomeStr) {
    SomeStr = FirstStr;
    while (SomeStr != nullptr) {
        if (AddedStr->key >= SomeStr->key) {
            if ((SomeStr->next) != nullptr && AddedStr->key <= SomeStr->next->key) {
                break;
            }
            if (SomeStr->next == nullptr) {
                break;
            }
        }
        Str* pt = SomeStr;
        SomeStr = pt->next;
    }
}

void add_to_begin(Str* & AddedStr, Str* & FirstStr) {
    Str* pt = FirstStr;
    AddedStr->next = pt;
    FirstStr = AddedStr;
}

void do_add_to_begin(Str* & FirstStr) {
    Str* AddedStr = new Str;
    std::cin >> AddedStr->key;
    add_to_begin(AddedStr, FirstStr);
}

void add_to_place(Str*& AddedStr, Str*& SomeStr) {
    Str* pt = SomeStr->next;
    SomeStr->next = AddedStr;
    AddedStr->next = pt;
}

void do_add_to_place(Str* & FirstStr) {
    Str* AddedStr = new Str;
    Str* SomeStr;
    std::cin >> AddedStr->key;
    if (AddedStr->key != 0 && FirstStr != nullptr) {
        find_place(AddedStr, FirstStr, SomeStr);
        add_to_place(AddedStr, SomeStr);
    }
}

void find_key(Str* FirstStr, Str* & SomeStr, int key_del) {
    SomeStr = FirstStr;
    while (SomeStr != nullptr) {
        if (key_del == SomeStr->key) {
            break;
        }
        else {
            SomeStr = SomeStr->next;
        }
    }
}

void delete_key(Str* & FirstStr, Str* & SomeStr) {
    Str* pt = FirstStr;
    if (SomeStr != nullptr && SomeStr != FirstStr) {
        while (pt-> next != nullptr && pt->next != SomeStr) {
            pt = pt->next;
        }
        pt->next = SomeStr->next;
        delete (SomeStr);
    }
    if (SomeStr != nullptr && SomeStr == FirstStr) {
        FirstStr = SomeStr->next;
        delete (SomeStr);
    }
}

void do_delete_key(Str* & FirstStr) {
    int key_del;
    Str* SomeStr;
    std::cin >> key_del;
    find_key(FirstStr, SomeStr, key_del);
    delete_key(FirstStr, SomeStr);
}

void delete_list(Str* & FirstStr) {
    while (FirstStr != nullptr) {
        Str* pt = FirstStr;
        FirstStr = pt->next;
        delete pt;
    }
}

void output_list(Str* FirstStr) {
    Str* pt_1 = FirstStr;
    std::cout << "begin" << std::endl;
    while (pt_1 != nullptr) {
        std::cout << pt_1->key << std::endl;
        pt_1 = pt_1->next;
    }
    std::cout << "end" << std::endl;
}

int main(){

    Str* FirstStr = new Str;
    input_list(FirstStr);
    output_list(FirstStr);
    //do_add_to_begin(FirstStr);
    //output_list(FirstStr);
    //delete_list(FirstStr);
    //do_add_to_place(FirstStr);
    //do_delete_key(FirstStr);
    //output_list(FirstStr);
    
    return 0;
}