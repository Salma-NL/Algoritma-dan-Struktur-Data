#include "single_linked_list.h"
#include <iostream>
#include <stdexcept>

void SingleLinkedList::init() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

bool SingleLinkedList::is_empty() {
    return head == nullptr;
}

void SingleLinkedList::add_front(int val) {
    Node* new_node = new Node{val, head};
    if (is_empty()) {
        head = tail = new_node;
        new_node->next = head;
    } else {
        head = new_node;
        tail->next = head;
    }
    size++;
}

void SingleLinkedList::add_back(int val) {
    if (is_empty()) {
        add_front(val);
        return;
    }
    Node* new_node = new Node{val, head};
    tail->next = new_node;
    tail = new_node;
    size++;
}

void SingleLinkedList::add_idx(int val, int idx) {
    if (idx < 0 || idx > size) throw std::out_of_range("Index out of range");
    if (idx == 0) { add_front(val); return; }
    if (idx == size) { add_back(val); return; }

    Node* ptr_current = head;
    for (int i = 0; i < idx - 1; i++) {
        ptr_current = ptr_current->next;
    }
    Node* new_node = new Node{val, ptr_current->next};
    ptr_current->next = new_node;
    size++;
}

void SingleLinkedList::delete_front() {
    if (is_empty()) throw std::underflow_error("List is empty");
    
    Node* ptr_delete = head;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        head = head->next;
        tail->next = head;
    }
    delete ptr_delete;
    size--;
}

void SingleLinkedList::delete_back() {
    if (is_empty()) throw std::underflow_error("List is empty");
    
    if (head == tail) {
        delete_front();
    } else {
        Node* ptr_current = head;
        while (ptr_current->next != tail) {
            ptr_current = ptr_current->next;
        }
        delete tail;
        tail = ptr_current;
        tail->next = head;
        size--;
    }
}

void SingleLinkedList::delete_idx(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index out of range");
    if (idx == 0) { delete_front(); return; }
    if (idx == size - 1) { delete_back(); return; }

    Node* ptr_current = head;
    for (int i = 0; i < idx - 1; i++) {
        ptr_current = ptr_current->next;
    }
    Node* ptr_delete = ptr_current->next;
    ptr_current->next = ptr_delete->next;
    delete ptr_delete;
    size--;
}

void SingleLinkedList::display() {
    if (is_empty()) {
        std::cout << std::endl;
        return;
    }
    Node* ptr_temp = head;
    for (int i = 0; i < size; i++) {
        std::cout << ptr_temp->data << " ";
        ptr_temp = ptr_temp->next;
    }
    std::cout << std::endl;
}

int SingleLinkedList::get(int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index out of range");
    
    Node* ptr_temp = head;
    for (int i = 0; i < idx; i++) {
        ptr_temp = ptr_temp->next;
    }
    return ptr_temp->data;
}

void SingleLinkedList::set(int val, int idx) {
    if (idx < 0 || idx >= size) throw std::out_of_range("Index out of range");

    Node* ptr_temp = head;
    for (int i = 0; i < idx; i++) {
        ptr_temp = ptr_temp->next;
    }
    ptr_temp->data = val;
}

void SingleLinkedList::clear() {
    while (!is_empty()) {
        delete_front();
    }
}