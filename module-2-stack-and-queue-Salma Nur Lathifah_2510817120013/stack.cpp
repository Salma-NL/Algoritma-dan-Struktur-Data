#include "stack.h"
#include <stdexcept>

void init(Stack* s) {
    s->top = nullptr;
}

bool isEmpty(const Stack* s) {
    return s->top == nullptr;
}

bool isFull(const Stack* s) {
    if (isEmpty(s)) return false;
    return s->top == &(s->data[MAX - 1]);
}

void push(Stack* s, int value) {
    if (isFull(s)) throw std::overflow_error("Stack Penuh");
    
    if (isEmpty(s)) {
        s->top = &(s->data[0]);
    } else {
        s->top++;
    }
    *(s->top) = value;
}

void pop(Stack* s) {
    if (isEmpty(s)) throw std::underflow_error("Stack Kosong");
    
    if (s->top == &(s->data[0])) {
        s->top = nullptr;
    } else {
        s->top--;
    }
}

int peek(const Stack* s) {
    if (isEmpty(s)) throw std::underflow_error("Stack Kosong");
    return *(s->top);
}