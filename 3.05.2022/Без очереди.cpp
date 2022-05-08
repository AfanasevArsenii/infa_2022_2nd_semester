#include <iostream>

struct BinaryTree {
    BinaryTree* left;
    BinaryTree* right;
    int key;
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

void output_Tree_beauty(BinaryTree* Tree, int level) {
    if (Tree == nullptr) {
        return;
    }

    output_Tree_beauty(Tree->right, level + 1);
    for (int i = 0; i < level; i++) std::cout << "   ";
    std::cout << Tree->key << std::endl;
    output_Tree_beauty(Tree->left, level + 1);
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
        output_Tree_beauty(FirstTree, 0);
    } while (key != 0);


    delete_Tree(FirstTree);
    return 0;
}
