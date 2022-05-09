#include <iostream>
#include <queue>

struct BinaryTree {
    BinaryTree* left;
    BinaryTree* right;
    int key;
};

struct Queue {
    Queue* next;
    BinaryTree* tree;
};

void add_Tree(int key, BinaryTree*& Tree) {
    if (Tree == nullptr) {
        Tree = new BinaryTree;
        Tree->key = key;
        Tree->left = nullptr;
        Tree->right = nullptr;
    }
    else {
        if (key > Tree->key) {
            add_Tree(key, Tree->left);
        }
        else {
            add_Tree(key, Tree->right);
        }
    }
}

void add_Queue(Queue** q, BinaryTree* Tree) {
    Queue* cur = *q;
    Queue* prev = nullptr;
    Queue* new_TreeQ = new Queue;

    if (Tree == nullptr) {
        BinaryTree* Tree = new BinaryTree;
        Tree->key = 0;
        Tree->left = Tree->right = nullptr;
        new_TreeQ->tree = Tree;
    }
    else {
        new_TreeQ->tree = Tree;
    }
    new_TreeQ->next = nullptr;

    while (cur != nullptr) {
        prev = cur;
        cur = cur->next;
    }
    if (prev != nullptr) {
        prev->next = new_TreeQ;
    }
    else {
        *q = new_TreeQ;
    }
}

BinaryTree* get_Tree(Queue** q) {
    Queue* old_TreeQ = *q;
    BinaryTree* old_Tree = nullptr;
    if (*q != nullptr) {
        old_Tree = old_TreeQ->tree;
        *q = (*q)->next;
        delete old_TreeQ;
    }
    return old_Tree;
}

void show_Tree(BinaryTree* Tree){
    Queue* global_q = nullptr;
    add_Queue(&global_q, Tree);
    int empty_line = 40;
    bool is_row_empty = false;
    
    while (is_row_empty == false) {
        Queue* local_q = nullptr;
        is_row_empty = true;

        for (int j = 0; j < empty_line; j++)
            std::cout << ' ';
        while (global_q != nullptr)
        {
            Tree = get_Tree(&global_q);

            if (Tree != nullptr && Tree->key != 0)
            {
                std::cout << Tree->key;
                add_Queue(&local_q, Tree->left);
                add_Queue(&local_q, Tree->right);

                if (Tree->left != nullptr) {
                    is_row_empty = false;
                }
                if (Tree->right != nullptr) {
                    is_row_empty = false;
                }
            }
            else
            {
                std::cout << " ";
                add_Queue(&local_q, nullptr);
                add_Queue(&local_q, nullptr);
            }
            for (int j = 0; j < empty_line * 2 - 2; j++)
                std::cout << ' ';
        }
        std::cout << std::endl;

        empty_line /= 1.5;
        while (local_q != nullptr) {
            Tree = get_Tree(&local_q);
            add_Queue(&global_q, Tree);
        }
    }
}

void delete_Tree(BinaryTree* Tree) {
    if (Tree == nullptr) {
        return;
    }
    else {
        delete_Tree(Tree->left);
        delete_Tree(Tree->right);
        delete Tree;
    }
}

int main() {
    BinaryTree* FirstTree = nullptr;
    Queue* q = nullptr;
    int key = 0;


    do {
        std::cin >> key;
        std::cout << std::endl;
        add_Tree(key, FirstTree);
        show_Tree(FirstTree);
        std::cout << std::endl;
    } while (key != 0);
    
    delete_Tree(FirstTree);

    return 0;
}