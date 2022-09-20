#ifndef NODE_H
#define NODE_H

#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <list>
#include <cassert>
using namespace std;

template <typename ITEM_TYPE>
struct node
{
public:
    node(const ITEM_TYPE &item = ITEM_TYPE(), node *next = nullptr);

    template <typename T>
    friend std::ostream &operator<<(std::ostream &outs, const node<T> &printMe)
    {
        outs << "[" << printMe._item << "] -> ";
        return outs;
    }
    ITEM_TYPE _item;
    node *_next;
};

template <typename ITEM_TYPE>
node<ITEM_TYPE>::node(const ITEM_TYPE &item, node *next)
{
    _item = item;
    _next = next;
}
#endif