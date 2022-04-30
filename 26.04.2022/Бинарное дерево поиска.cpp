#include <iostream>

struct BinaryTree {
    BinaryTree* left;
    BinaryTree* right;
    int key;
};

void add_Tree(int key, BinaryTree*& DadTree) {
    if (DadTree == nullptr) {
        DadTree = new BinaryTree;
        DadTree->key = key;
        DadTree->left = nullptr;
        DadTree->right = nullptr;
    }
    else {
        if (key > DadTree->key) {
            add_Tree(key, DadTree->left);

        }
        else {
            add_Tree(key, DadTree->right);
        }
    }
}

void output_Tree(BinaryTree* Tree) {
    if (Tree == nullptr) {
        return;
    }

    std::cout << "(";
    output_Tree(Tree->right);
    std::cout << Tree->key;
    output_Tree(Tree->left);
    std::cout << ")";
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
    int key = 0;

    do {
        std::cin >> key;
        add_Tree(key, FirstTree);
        output_Tree(FirstTree);
        std::cout << std::endl;
    } while (key != 0);

    delete_Tree(FirstTree);
    return 0;
}