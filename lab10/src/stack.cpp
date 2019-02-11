#ifdef STACK_H
#include <stdlib.h>
#include <iostream>
#include "stack.hpp"

template <class T>
Stack<T>::Stack() {
}

template <class T>
Stack<T>::Stack(const Stack<T> &sll) {
}

template <class T>
Stack<T>::~Stack() {
}

template <class T>
int Stack<T>::getLength() const {
}

template <class T>
bool Stack<T>::push(const T &val) {
}

template <class T>
T& Stack<T>::top() {
}

template <class T>
void Stack<T>::pop() {
}

template <class T>
void Stack<T>::print() const {
}

template <class T>
bool Stack<T>::isEmpty() const {
}

#endif
