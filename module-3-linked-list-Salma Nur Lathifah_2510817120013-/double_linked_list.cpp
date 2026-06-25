#include "double_linked_list.h"
#include <iostream>
#include <stdexcept>

void DoubleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool DoubleLinkedList::is_empty() {
    return head == nullptr;
}

void DoubleLinkedList::add_front(char val) {
    Node* new_node = new Node;
    new_node->data = val;
    new_node->prev = nullptr;
    new_node->next = head;

    if (is_empty()) {
        head = tail = new_node;
    } else {
        head->prev = new_node;
        head = new_node;
    }
    size++;
}

void DoubleLinkedList::add_back(char val) {
    Node* new_node = new Node;
    new_node->data = val;
    new_node->next = nullptr;
    new_node->prev = tail;

    if (is_empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    size++;
}

void DoubleLinkedList::add_idx(char val, int idx) {
    if (idx < 0 || idx > size) return;

    if (idx == 0) {
        add_front(val);
        return;
    }
    if (idx == size) {
        add_back(val);
        return;
    }

    Node* ptr_current = head;
    for (int i = 0; i < idx - 1; i++) {
        ptr_current = ptr_current->next;
    }

    Node* new_node = new Node;
    new_node->data = val;
    new_node->next = ptr_current->next;
    new_node->prev = ptr_current;

    if (ptr_current->next != nullptr) {
        ptr_current->next->prev = new_node;
    }
    ptr_current->next = new_node;
    size++;
}

void DoubleLinkedList::delete_front() {
    if (is_empty()) return;

    Node* ptr_delete = head;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        head = head->next;
        head->prev = nullptr;
    }
    delete ptr_delete;
    size--;
}

void DoubleLinkedList::delete_back() {
    if (is_empty()) return;

    Node* ptr_delete = tail;
    if (size == 1) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete ptr_delete;
    size--;
}

void DoubleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) return;

    if (idx == 0) {
        delete_front();
        return;
    }
    if (idx == size - 1) {
        delete_back();
        return;
    }

    Node* ptr_delete = head;
    for (int i = 0; i < idx; i++) {
        ptr_delete = ptr_delete->next;
    }

    ptr_delete->prev->next = ptr_delete->next;
    if (ptr_delete->next != nullptr) {
        ptr_delete->next->prev = ptr_delete->prev;
    }

    delete ptr_delete;
    size--;
}

void DoubleLinkedList::display() {
    Node* ptr_temp = head;
    while (ptr_temp != nullptr) {
        std::cout << ptr_temp->data;
        ptr_temp = ptr_temp->next;
    }
    std::cout << std::endl;
}

char DoubleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index");
    }

    Node* ptr_temp = head;
    for (int i = 0; i < idx; i++) {
        ptr_temp = ptr_temp->next;
    }
    return ptr_temp->data;
}

void DoubleLinkedList::set(char val, int idx) {
    if (idx < 0 || idx >= size) {
        throw std::out_of_range("Index");
    }

    Node* ptr_temp = head;
    for (int i = 0; i < idx; i++) {
        ptr_temp = ptr_temp->next;
    }
    ptr_temp->data = val;
}

void DoubleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}