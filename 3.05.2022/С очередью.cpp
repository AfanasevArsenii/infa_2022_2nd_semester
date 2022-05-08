#include <iostream>

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

void form_Queue(BinaryTree* Tree) {
    Queue* q = nullptr;
    int level = 0;
    int counter_0 = 0;
    int counter_n = 0;
    int check_line = 1;
    add_Queue(&q, Tree);
    Queue* q_first = q;
    while (q != nullptr) {

        Tree = get_Tree(&q);

        if (Tree->key == 0) {
            counter_0++;
        }
        else {
            counter_0 = 0;
        }

        counter_n++;

        if (check_line == 1) {
            for (int i = 0; i != 40 - pow(2, level); i++) {
                std::cout << " ";
            }
            check_line = 0;
        }

        if (Tree->key != 0) {
            std::cout << Tree->key << " ";
        }
        else {
            std::cout << "    ";
        }

        if (counter_n == pow(2, level)) {
            level++;
            std::cout << std::endl;
            if (counter_n == counter_0) {
                break;
            }
            counter_0 = 0;
            counter_n = 0;
            check_line = 1;
        }

        if (Tree->left != nullptr)
            add_Queue(&q, Tree->left);
        if (Tree->right != nullptr)
            add_Queue(&q, Tree->right);
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

void delete_Queue(Queue* q) {
    if (q == nullptr) {
        return;
    }
    else {
        delete_Queue(q->next);
        delete q;
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
        form_Queue(FirstTree);
        std::cout << std::endl;
    } while (key != 0);


    delete_Tree(FirstTree);
    return 0;
}