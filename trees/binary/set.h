#include <iostream>
#include "tree.h"

struct Set {
    Tree *root;
};

Set set_new() {
    return Set{nullptr};
}

bool set_is_empty(Set const &set) {
    return empty_node(set.root);
}

int set_example(Set const &set) {
    return example_node(set.root);
}

bool set_contains(Set const &set, int key) {
    return contains_node(set.root, key);
}

Set& set_insert(Set &set, int key) {
    set.root = insert_node(set.root, key);
    return set;
}

Set& set_remove(Set &set, int key) {
    set.root = delete_node(set.root, key);
    return set;
}

Set& set_erase(Set &set) {
    tree_erase(set.root);
    set.root = nullptr;
    return set;
}