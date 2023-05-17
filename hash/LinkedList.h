#include <iostream>

struct LinkedList {
    int data;
    LinkedList* next;
};

LinkedList* insert_after(LinkedList*  const current, int data) {
    LinkedList* new_node = new LinkedList{data, nullptr};
    if (current != nullptr) {
        new_node->next = current->next;
        current->next = new_node;
    }
    return new_node;
}

LinkedList* remove_after(LinkedList* const current) {
    if (current == nullptr || current->next == nullptr) {
        return nullptr;
    }
    LinkedList* removed_node = current->next;
    current->next = removed_node->next;
    delete removed_node;
    return current->next;
}

LinkedList* remove_value (LinkedList *head, int key) {
    if (head == nullptr) return nullptr;
    if (head != nullptr and head->data == key) {
        auto tmp = head->next;
        delete head;
        return tmp;
    }
    LinkedList* current = head;
    while (current->next != nullptr) {
        if (current->next->data == key) remove_after(current);
    }
    return head;
}

void erase(LinkedList* const head) {
    LinkedList* current = head;
    while (current != nullptr) {
        LinkedList* to_remove = current;
        current = current->next;
        delete to_remove;
    }
}

LinkedList* reverse_rec(LinkedList* const head) {
    if (head == nullptr || head->next == nullptr) {
        return head;
    }
    LinkedList* new_head = reverse_rec(head->next);
    head->next->next = head;
    head->next = nullptr;
    return new_head;
}

LinkedList* reverse_itr(LinkedList* const head) {
    LinkedList* prev = nullptr;
    LinkedList* current = head;
    while (current != nullptr) {
        LinkedList* next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}