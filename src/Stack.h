#ifndef STACK_H
#define STACK_H

#include <forward_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <utility>

using std::distance;
using std::forward_list;
using std::move;
using std::ostream;

template <typename T> class Stack {
private:
  forward_list<T> data;

public:
  Stack(int size = 0, T value = T());
  Stack(const Stack<T> &other);

  class StackIter {
    Stack<T> *stack;

  public:
    StackIter() : stack(nullptr) {}
    StackIter(Stack<T> *elem) : stack(elem) {}

    bool operator!=(StackIter const &other) { return not(*this == other); }
    bool operator==(StackIter const &other) {
      return stack == nullptr and other.stack->empty() or
             stack->empty() and other.stack == nullptr or stack == other.stack;
    }

    StackIter &operator++() {
      stack->pop();
      return *this;
    }

    T &operator*() { return stack->data.front(); }
  };

  StackIter end() { return StackIter(); }
  StackIter begin() { return StackIter(this); }

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

template <typename T> T Stack<T>::pop() {
  T v = move(this->data.front());
  this->data.pop_front();
  return v;
}
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
