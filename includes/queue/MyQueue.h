#ifndef MYQUEUE_H
#define MYQUEUE_H

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
class Queue
{
public:
    class Iterator
    {
    public:
        friend class Queue;               // give access to list to access _ptr
        Iterator() { _ptr = nullptr; }    // default ctor
        Iterator(node<T> *p) : _ptr(p){}; // Point Iterator to where
        //...                        //  p is pointing to

        T &operator*() // dereference operator
        {
            assert(_ptr != nullptr);
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

    Queue();

    Queue(const Queue<T> &copyMe);
    ~Queue();
    Queue &operator=(const Queue<T> &RHS);

    bool empty();
    T front();
    T back();

    void push(T item);
    T pop();

    Iterator begin() const // Iterator to the head node
    {
        return Iterator(_front);
    }
    Iterator end() const // Iterator to NULL
    {
        return Iterator(nullptr);
    }
    void print_pointers();
    int size() const { return _size; }
    node<T> *front() const { return _front; }
    node<T> *rear() const { return _rear; }
    template <typename TT>
    friend ostream &operator<<(ostream &outs, const Queue<TT> &printMe)
    {
        node<TT> *walker = printMe._front;
        outs << "Queue:Head->";
        while (walker != nullptr)
        {
            outs << *walker;
            walker = walker->_next;
        }
        outs << "|||" << endl;
        return outs;
    }

private:
    node<T> *_front;
    node<T> *_rear;
    int _size;
};

template <typename T>
Queue<T>::Queue()
{
    _front = nullptr;
    _rear = nullptr;
    _size = 0;
}

template <typename T>
Queue<T>::Queue(const Queue<T> &copyMe)
{
    _rear = _copy_list(_front, copyMe._front);
    _size = copyMe._size;
}

template <typename T>
Queue<T>::~Queue()
{
    _clear_list(_front);
    _rear = nullptr;
}

template <typename T>
Queue<T> &Queue<T>::operator=(const Queue<T> &RHS)
{
    if (this == &RHS)
        return *this;
    _clear_list(_front);
    _rear = _copy_list(_front, RHS._front);
    _size = RHS._size;
    return *this;
}

template <typename T>
bool Queue<T>::empty()
{
    if (_front == nullptr)
    {
        // assert
        return true;
    }
    return false;
}

template <typename T>
T Queue<T>::front()
{
    assert(_front != nullptr);
    return _front->_item;
}

template <typename T>
T Queue<T>::back()
{
    assert(_rear != nullptr);
    return _rear->_item;
}

template <typename T>
void Queue<T>::push(T item)
{
    if (_front == nullptr)
        _rear = _insert_head(_front, item);
    else
        _rear = _insert_after(_front, _rear, item);
    _size++;
}

template <typename T>
T Queue<T>::pop()
{
    _size--;
    T pop = _delete_node(_front, _front);
    if (_front == nullptr)
        _rear = nullptr;
    return pop;
}

template <typename T>
void Queue<T>::print_pointers()
{
    node<T> *walker = _front;
    cout << "H->";
    while (walker != nullptr)
    {
        cout << "[" << *(walker->_item) << "]->";
        walker = walker->_next;
    }
    cout << "|||";
}
#endif