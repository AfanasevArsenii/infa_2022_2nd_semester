#include <iostream>

struct AvlTree {
    AvlTree* left;
    AvlTree* right;
    int key;
    int balance;
};

int find_height(AvlTree* Tree) {
    if (Tree == nullptr) {
        return 0;
    }
    int l_height = find_height(Tree->left);
    int r_height = find_height(Tree->right);
    if (l_height > r_height) {
        return l_height + 1;
    }
    else {
        return r_height + 1;
    }
}

void balance_Tree(AvlTree*& Tree) {
    if (Tree != nullptr) {
        Tree->balance = find_height(Tree->right) - find_height(Tree->left);
    }

}

void right_turn_Tree(AvlTree*& Tree) {
    AvlTree* lTree;
    AvlTree* rlTree;
    lTree = Tree->left;
    rlTree = lTree->right;

    lTree->right = Tree;
    Tree->left = rlTree;
    Tree = lTree;
    balance_Tree(Tree->right);
    balance_Tree(Tree);
}

void left_turn_Tree(AvlTree*& Tree) {
    AvlTree* rTree;
    AvlTree* lrTree;
    rTree = Tree->right;
    lrTree = rTree->left;

    rTree->left = Tree;
    Tree->right = lrTree;
    Tree = rTree;
    balance_Tree(Tree->left);
    balance_Tree(Tree);
}

void add_Tree(int key, AvlTree*& DadTree) {
    if (DadTree == nullptr) {
        DadTree = new AvlTree;
        DadTree->key = key;
        DadTree->balance = 0;
        DadTree->left = nullptr;
        DadTree->right = nullptr;
    }
    else {
        if (key > DadTree->key) {
            add_Tree(key, DadTree->right);
            if (find_height(DadTree->right) - find_height(DadTree->left) > 1) {
                if (find_height(DadTree->right->right) < find_height(DadTree->right->left)) {
                    right_turn_Tree(DadTree->right);
                }
                left_turn_Tree(DadTree);
            }
        }
        else {
            if (key < DadTree->key) {
                add_Tree(key, DadTree->left);
                if (find_height(DadTree->left) - find_height(DadTree->right) > 1) {
                    if (find_height(DadTree->left->left) < find_height(DadTree->left->right)) {
                        left_turn_Tree(DadTree->left);
                    }
                    right_turn_Tree(DadTree);
                }
            }
            balance_Tree(DadTree);
        }
    }
}

void output_Tree(AvlTree* Tree) {
    if (Tree == nullptr) {
        return;
    }

    std::cout << "(";
    output_Tree(Tree->right);
    std::cout << Tree->key;
    output_Tree(Tree->left);
    std::cout << ")";
}

void delete_Tree(AvlTree* Tree) {
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
    AvlTree* FirstTree = nullptr;
    int key = 0;

    output_Tree(FirstTree);
    do {
        std::cin >> key;
        add_Tree(key, FirstTree);
        output_Tree(FirstTree);
        std::cout << std::endl;
    } while (key != 0);

    delete_Tree(FirstTree);
    return 0;
}