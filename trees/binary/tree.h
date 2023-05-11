#include <iostream>

struct Tree {
    int key;
    Tree *left = nullptr;
    Tree *right = nullptr;
};

Tree *new_node(int key) {
    Tree *node = new Tree{key, nullptr, nullptr};
    return node;
}

bool empty_node(Tree *node) {
    return node == nullptr;
}

int example_node (Tree *root) {
    return root->key;
}

bool contains_node(Tree *root, int key) {
    auto temp = root;
    while (temp != nullptr) {
        if (key < temp->key)
            temp = temp->left;
        else if (key > temp->key)
            temp = temp->right;
        else
            return true;        
    }
    return false;
}

Tree *insert_node(Tree *node, int key) {
    // поиск места вставки и рекурсивная вставка
    if (node == nullptr)
        return new_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    else
        return node;

    return node;
}

Tree *min_node(Tree *node) {
    Tree *current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

Tree *delete_node(Tree *root, int key) {
    if (root == nullptr) 
        return root;

    if (key < root->key)
        root->left = delete_node(root->left, key);

    else if (key > root->key)
        root->right = delete_node(root->right, key);

    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            Tree *temp;
            if (root->left) temp = root->left;
            else temp = root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } 
            else *root = *temp;
            delete temp;
        } 
        else {
            Tree *temp = min_node(root->right);

            root->key = temp->key;

            root->right = delete_node(root->right, temp->key);
        }
    }

    return root;
}

void tree_erase(Tree *root) {
    if (root != nullptr) {
        tree_erase(root->left);
        tree_erase(root->right);
        delete root;
    }
}
