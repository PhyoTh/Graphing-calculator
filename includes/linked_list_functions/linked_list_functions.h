#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
#include "../node/node.h"
using namespace std;

// Linked List General Functions:
template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE> *head); //

// recursive fun! :)
// template <typename ITEM_TYPE>
// void _print_list_backwards(node<ITEM_TYPE> *head);

// return ptr to key or NULL
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_search_list(node<ITEM_TYPE> *head,
                              ITEM_TYPE key); //

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_head(node<ITEM_TYPE> *&head,
                              ITEM_TYPE insert_this); //

// insert after ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_after(node<ITEM_TYPE> *&head,
                               node<ITEM_TYPE> *after_this,
                               ITEM_TYPE insert_this); //

// insert before ptr
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_before(node<ITEM_TYPE> *&head,
                                node<ITEM_TYPE> *before_this,
                                ITEM_TYPE insert_this); //

// ptr to previous node
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_previous_node(node<ITEM_TYPE> *head,
                                node<ITEM_TYPE> *prev_to_this); //

// delete, return item
template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE> *&head,
                       node<ITEM_TYPE> *delete_this); //

// duplicate the list...
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_copy_list(node<ITEM_TYPE> *head); //

// duplicate list and return the last node of the copy
template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src); //

// delete all the nodes
template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE> *&head); //

//_item at this position
template <typename ITEM_TYPE>
ITEM_TYPE &_at(node<ITEM_TYPE> *head, int pos); //

//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .
//      Sorted List Routines. order: 0: ascending, order: other: descending
//                              Assume a Sorted List
//. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . .

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_sorted(node<ITEM_TYPE> *&head, // insert
                                ITEM_TYPE item,
                                bool ascending = true);

// insert or add if a dup
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_sorted_and_add(node<ITEM_TYPE> *&head,
                                        ITEM_TYPE item,
                                        bool ascending = true);
// node after which this item goes order: 0 ascending
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_where_this_goes(node<ITEM_TYPE> *head,
                                  ITEM_TYPE item,
                                  bool ascending = true);
// Last Node in the list
template <typename ITEM_TYPE>
node<ITEM_TYPE> *_last_node(node<ITEM_TYPE> *head); //

//- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
// template <typename ITEM_TYPE, typename DUP>
// node<ITEM_TYPE> *_insert_sorted_unique(node<ITEM_TYPE> *&head,
//                                        const ITEM_TYPE item,
//                                        DUP Dup = Dup_Nothing<ITEM_TYPE>());
///////////////////////////////////////////////////////////////

template <typename ITEM_TYPE>
void _print_list(node<ITEM_TYPE> *head)
{
    node<ITEM_TYPE> *walker = head;
    while (walker != nullptr)
    {
        cout << *walker;
        walker = walker->_next;
    }
    if (walker == nullptr)
    {
        cout << "|||";
    }
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_search_list(node<ITEM_TYPE> *head, ITEM_TYPE key)
{
    node<ITEM_TYPE> *walker = head;
    while (walker != nullptr)
    {
        if (walker->_item == key)
        {
            break;
        }
        walker = walker->_next;
    }
    if (walker == nullptr)
        return nullptr;
    return walker;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_head(node<ITEM_TYPE> *&head, ITEM_TYPE insert_this)
{
    node<ITEM_TYPE> *temp = new node<ITEM_TYPE>(insert_this);
    temp->_next = head;
    head = temp;
    return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_after(node<ITEM_TYPE> *&head, node<ITEM_TYPE> *after_this, ITEM_TYPE insert_this)
{
    if (head == nullptr)
    {
        head = _insert_head(head, insert_this);
        return head;
    }
    node<ITEM_TYPE> *temp = new node<ITEM_TYPE>(insert_this, after_this->_next);
    after_this->_next = temp;
    return temp;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_before(node<ITEM_TYPE> *&head, node<ITEM_TYPE> *before_this, ITEM_TYPE insert_this)
{
    if (head == nullptr)
    {
        return _insert_head(head, insert_this);
    }
    node<ITEM_TYPE> *temp = new node<ITEM_TYPE>(insert_this, before_this);
    _previous_node(head, before_this)->_next = temp;
    return temp;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_previous_node(node<ITEM_TYPE> *head, node<ITEM_TYPE> *prev_to_this)
{
    if (prev_to_this == head)
    {
        return nullptr;
    }
    node<ITEM_TYPE> *walker = head;
    while (walker != nullptr)
    {
        if (walker->_next == prev_to_this)
        {
            break;
        }
        walker = walker->_next;
    }
    assert(walker != nullptr);
    return walker;
}

template <typename ITEM_TYPE>
ITEM_TYPE _delete_node(node<ITEM_TYPE> *&head, node<ITEM_TYPE> *delete_this)
{
    if (head == nullptr)
        return ITEM_TYPE();
    if (delete_this == head)
    {
        head = head->_next;
        ITEM_TYPE value = delete_this->_item;
        delete delete_this;
        return value;
    }
    _previous_node(head, delete_this)->_next = delete_this->_next;
    ITEM_TYPE value = delete_this->_item;
    delete delete_this;
    return value;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_copy_list(node<ITEM_TYPE> *head)
{
    if (head == nullptr)
        return nullptr;
    node<ITEM_TYPE> *copy = nullptr;
    copy = _insert_head(copy, head->_item);
    if (head->_next != nullptr)
    {
        node<ITEM_TYPE> *walker1 = head->_next;
        node<ITEM_TYPE> *walker2 = copy;
        while (walker1 != nullptr)
        {
            _insert_after(copy, walker2, walker1->_item);
            walker1 = walker1->_next;
            walker2 = walker2->_next;
        }
    }
    return copy;
}

template <typename T>
node<T> *_copy_list(node<T> *&dest, node<T> *src)
{
    _clear_list(dest);
    dest = _copy_list(src);
    return _last_node(dest);
}

template <typename ITEM_TYPE>
void _clear_list(node<ITEM_TYPE> *&head)
{
    if (head != nullptr)
    {
        while (head != nullptr)
        {
            node<ITEM_TYPE> *walker = head;
            head = head->_next;
            delete walker;
        }
    }
}

template <typename ITEM_TYPE>
ITEM_TYPE &_at(node<ITEM_TYPE> *head, int pos)
{
    assert(pos >= 0);
    node<ITEM_TYPE> *walker = head;
    for (int i = 0; i < pos; i++)
    {
        walker = walker->_next;
    }
    assert(walker != nullptr);
    return walker->_item;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_sorted(node<ITEM_TYPE> *&head, ITEM_TYPE item, bool ascending)
{
    node<ITEM_TYPE> *iMarker = _where_this_goes(head, item, ascending);
    if (iMarker == nullptr)
        return _insert_head(head, item);
    // cout << "Entering insert:" << endl;
    // cout << *iMarker << endl;
    _insert_after(head, iMarker, item);
    return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_insert_sorted_and_add(node<ITEM_TYPE> *&head, ITEM_TYPE item, bool ascending)
{
    node<ITEM_TYPE> *search = _search_list(head, item);
    if (search != nullptr)
    {
        search->_item += item;
        return search;
    }
    return _insert_sorted(head, item, ascending);
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_where_this_goes(node<ITEM_TYPE> *head, ITEM_TYPE item, bool ascending)
{
    if (head == nullptr)
        return nullptr;
    // if (head->_next = nullptr)
    //     return head;
    node<ITEM_TYPE> *walker = head;
    node<ITEM_TYPE> *walker1 = head->_next;
    if (ascending == true)
    {
        if (item < walker->_item)
            return nullptr;
        while (walker1 != nullptr)
        {
            if (walker->_item <= item && walker1->_item >= item)
                break;
            walker = walker->_next;
            walker1 = walker1->_next;
        }
        return walker;
    }
    if (ascending == false)
    {
        if (item > walker->_item)
            return nullptr;
        while (walker1 != nullptr)
        {
            if (walker->_item >= item && walker1->_item <= item)
                break;
            walker = walker->_next;
            walker1 = walker1->_next;
        }
        return walker;
    }
    return nullptr;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE> *_last_node(node<ITEM_TYPE> *head)
{
    if (head == nullptr)
        return nullptr;
    node<ITEM_TYPE> *rear = head;
    while (rear->_next != nullptr)
    {
        rear = rear->_next;
    }
    return rear;
}
#endif