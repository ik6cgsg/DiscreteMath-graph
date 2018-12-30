#ifndef _LIST_H__
#define _LIST_H__
#pragma once

template<typename type>
struct list_node
{
  type data;
  list_node *next;

  list_node() : data(), next(nullptr)
  {
  } // End of constructor 
  list_node(const type & new_data, struct list_node *new_next = nullptr) : data(new_data), next(new_next)
  {
  } // End of constructor 
}; // end of 'list_node_t' struct 

template<typename type>
class list
{
private:
  typedef list_node<type> node;

  list_node<type> *root;
public:
  list() : root(nullptr)
  {
  } // End of constructor 

  list & pushBegin(const type & data);
  list & pushEnd(const type & data);
  type popBegin() const;
  type operator[](int ind) const;
  bool isEmpty()
  {
    return root == nullptr;
  }

  ~list();
}; // end of 'list' class 

#include "list.hpp"

#endif // _LIST_H__
