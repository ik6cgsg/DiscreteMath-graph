#ifndef _QUEUE_HPP__
#define _QUEUE_HPP__
#pragma once

#include "queue.h"

template<typename type>
queue<type> & queue<type>::push(const type & data)
{
  node *new_elem = new node(data);

  // empty queue 
  if (head == nullptr)
    head = tail = new_elem;
  else
  {
    tail->next = new_elem;
    tail = new_elem;
  }
  return *this;
} // End of 'push' function 

template<typename type>
type queue<type>::pop()
{
  if (head == nullptr)
    return type();

  node *old;
  type res;

  old = head;
  res = old->data;

  head = head->next;

  delete old;

  return res;
} // End of 'pop' function 

template<typename type>
queue<type>::~queue()
{
  while (head != nullptr)
  {
    node *old;

    old = head;
    head = head->next;

    delete old;
  }
} // End of destructor 

#endif // _QUEUE_HPP__
