#ifndef _LIST_HPP__
#define _LIST_HPP__
#pragma once

#include "list.h"

template<typename type>
list<type> & list<type>::pushBegin(const type & data)
{
  node *new_node = new node(data);

  new_node->next = root;
  root = new_node;

  return *this;
} // End of 'pushBegin' function 

template<typename type>
list<type> & list<type>::pushEnd(const type & data)
{
  node *new_node = new node(data);

  if (root == nullptr)
  {
    root = new_node;
    return *this;
  }

  node *node = root;

  while (node->next != nullptr)
    node = node->next;

  node->next = new_node;

  return *this;
} // End of 'pushEnd' function 

template<typename type>
type list<type>::popBegin() const
{
  node *old = root;
  type res = old->data;

  root = root->next;
  delete old;

  return res;
} // End of 'popBegin' function 

template<typename type>
type list<type>::operator[](int ind) const
{
  node *node = root;

  for (int i = 0; i < ind; i++)
    node = node->next;

  if (node == nullptr)
    return nullptr;

  return node->data;
} // End of 'operator[]' function 

template<typename type>
list<type>::~list()
{
  while (root != nullptr)
  {
    node *old;

    old = root;
    root = root->next;

    delete old;
  }
} // End of '~list' function 

#endif // _LIST_HPP__
