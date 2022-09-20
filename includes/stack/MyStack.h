#ifndef MYSTACK_H
#define MYSTACK_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
#include "../node/node.h"
#include "../linked_list_functions/linked_list_functions.h"
using namespace std;

template <typename T>
class Stack
{
public:
    class Iterator
    {
    public:
        friend class Stack;                // give access to list to access _ptr
        Iterator() { _ptr = NULL; }        // default ctor
        Iterator(node<T> *p) { _ptr = p; } // Point Iterator to where
                                           //   p is pointing to

        T &operator*() // dereference operator
        {
            assert(_ptr);
            return _ptr->_item;
        }

        T *operator->() // member access operator
        {
            return &(operator*());
        }

        bool is_null() // true if _ptr is NULL
        {
            if (_ptr == nullptr)
                return true;
            return false;
        }

        friend bool operator!=(const Iterator &left,
                               const Iterator &right) // true if left != right
        {
            if (left._ptr != right._ptr)
                return true;
            return false;
        }

        friend bool operator==(const Iterator &left,
                               const Iterator &right) // true if left == right
        {
            return !(left != right);
        }

        Iterator &operator++() // member operator: ++it; or ++it = new_value
        {
            _ptr = _ptr + 1;
            return *this;
        }

        friend Iterator operator++(Iterator &it, int unused) // friend operator: it++
        {
            Iterator hold = it;
            it._ptr = it._ptr->_next;
            return hold;
        }

    private:
        node<T> *_ptr; // pointer being encapsulated
    };

    Stack();
    Stack(const Stack<T> &copyMe);
    ~Stack();
    Stack<T> &operator=(const Stack<T> &RHS);
    T top();
    bool empty();
    void push(T item);
    T pop();
    void print_pointers();
    template <typename TT>
    friend ostream &operator<<(ostream &outs,
                               const Stack<TT> &printMe)
    {
        node<TT> *walker = printMe._top;
        outs << "Stack:Head->";
        while (walker != nullptr)
        {
            outs << *walker;
            walker = walker->_next;
        }
        outs << "|||" << endl;
        return outs;
    }

    Iterator begin() const // Iterator to the head node
    {
        return Iterator(_top);
    }
    Iterator end() const // Iterator to NULL
    {
        return Iterator(nullptr);
    }
    int size() const { return _size; }

private:
    node<T> *_top;
    int _size;
};

template <typename T>
Stack<T>::Stack()
{
    _top = nullptr;
    _size = 0;
}

template <typename T>
Stack<T>::Stack(const Stack<T> &copyMe)
{
    _top = _copy_list(copyMe._top);
    _size = copyMe._size;
}

template <typename T>
Stack<T>::~Stack()
{
    _clear_list(_top);
}

template <typename T>
Stack<T> &Stack<T>::operator=(const Stack<T> &RHS)
{
    if (this == &RHS)
        return *this;
    _clear_list(_top);
    _top = _copy_list(RHS._top);
    _size = RHS._size;
    return *this;
}

template <typename T>
T Stack<T>::top()
{
    return _top->_item;
}

template <typename T>
bool Stack<T>::empty()
{
    if (_size == 0)
        return true;
    return false;
}

template <typename T>
void Stack<T>::push(T item)
{
    _insert_head(_top, item);
    _size++;
}

template <typename T>
T Stack<T>::pop()
{
    assert(_top != nullptr);
    _size--;
    return _delete_node(_top, _top);
}

template <typename T>
void Stack<T>::print_pointers()
{
    node<T> *walker = _top;
    cout << "H->";
    while (walker != nullptr)
    {
        cout << *(walker->_item);
        walker = walker->_next;
    }
    cout << "|||";
}
#endif