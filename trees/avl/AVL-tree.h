struct AVL_tree {
    int key;
    AVL_tree *left = nullptr;
    AVL_tree *right = nullptr;
    int height;
};


int height(AVL_tree *node) {
    if (node == nullptr)
        return 0;
    return node->height;
}

int max(int a, int b) {
    if (a >= b) return a;
    else return b;
}

AVL_tree *new_node(int key) {
    AVL_tree *node = new AVL_tree{key, nullptr, nullptr, 1};
    return node;
}

bool empty_node(AVL_tree *node) {
    if (node == nullptr)
        return true;
    else
        return false;;
}

int example_node(AVL_tree *root) {
    return root->key;
}

bool contains_node(AVL_tree *root, int key) {
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

// правый поворот
AVL_tree *right_rotate(AVL_tree *node) {
    AVL_tree *left_node = node->left;
    AVL_tree *tmp = left_node->right;

    left_node->right = node;
    node->left = tmp;

    node->height = max(height(node->left), height(node->right)) + 1;
    left_node->height = max(height(left_node->left), height(left_node->right)) + 1;

    return left_node;
}

// левый поворот
AVL_tree *left_rotate(AVL_tree *node) {
    AVL_tree *right_node = node->right;
    AVL_tree *tmp = right_node->left;

    right_node->left = node;
    node->right = tmp;

    node->height = max(height(node->left), height(node->right)) + 1;
    right_node->height = max(height(right_node->left), height(right_node->right)) + 1;

    return right_node;
}

int get_balance(AVL_tree *node) {
    if (node == nullptr)
        return 0;
    return height(node->left) - height(node->right);
}


AVL_tree *insert_node(AVL_tree *node, int key) {
    // поиск места вставки и рекурсивная вставка
    if (node == nullptr)
        return new_node(key);

    if (key < node->key)
        node->left = insert_node(node->left, key);
    else if (key > node->key)
        node->right = insert_node(node->right, key);
    else
        return node;

    // балансировка дерева
    node->height = 1 + max(height(node->left),height(node->right));

    int balance = get_balance(node);
    if (balance > 1 && key < node->left->key)
        return right_rotate(node);

    if (balance < -1 && key > node->right->key)
        return left_rotate(node);

    if (balance > 1 && key > node->left->key) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    if (balance < -1 && key < node->right->key) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

AVL_tree *min_node(AVL_tree *node) {
    AVL_tree *current = node;

    while (current->left != nullptr)
        current = current->left;

    return current;
}

AVL_tree *delete_node(AVL_tree *root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->key)
        root->left = delete_node(root->left, key);

    else if (key > root->key)
        root->right = delete_node(root->right, key);

    else {
        if ((root->left == nullptr) || (root->right == nullptr)) {
            AVL_tree *temp = root->left ? root->left : root->right;

            if (temp == nullptr) {
                temp = root;
                root = nullptr;
            } else
                *root = *temp;
            delete temp;
        } else {
            AVL_tree *temp = min_node(root->right);

            root->key = temp->key;

            root->right = delete_node(root->right, temp->key);
        }
    }

    // балансировка дерева
    if (!root)
        return root;
        
    root->height = 1 + max(height(root->left), height(root->right));

    int balance = get_balance(root);
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

void tree_erase(AVL_tree *root) {
    if (root != nullptr) {
        tree_erase(root->left);
        tree_erase(root->right);
        delete root;
    }
}

