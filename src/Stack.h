#ifndef STACK_H
#define STACK_H

#include <forward_list>
#include <iostream>
#include <iterator>
#include <ostream>

using std::distance;
using std::forward_list;
using std::ostream;

template <typename T> class Stack {
private:
  forward_list<T> data;

public:
  Stack(int size = 0, T value = T());
  Stack(const Stack<T> &other);

  inline bool empty() const;
  inline void push(T elem);
  inline T pop();
  inline int size() const;

  template <typename U>
  friend ostream &operator<<(ostream &os, const Stack<U> stack);
};

template <typename T> Stack<T>::Stack(int size, T value) : data(size, value) {}
template <typename T>
Stack<T>::Stack(const Stack<T> &other) : data(other.data) {}

template <typename T> T Stack<T>::pop() { return this->data.pop_front(); }
template <typename T> void Stack<T>::push(T elem) {
  return this->data.push_front(elem);
}

template <typename T> int Stack<T>::size() const {
  return std::distance(data.begin(), data.end());
}
template <typename T> bool Stack<T>::empty() const {
  return this->data.empty();
}

template <typename U> ostream &operator<<(ostream &os, const Stack<U> stack) {
  auto first = true;

  for (auto i : stack.data)
    if (first) {
      os << '[' << i;
      first = false;
    } else
      os << ' ' << i;
  os << ']';
  return os;
}

#endif /* STACK_H */