#ifndef _QUEUE_H__
#define _QUEUE_H__
#pragma once

#include "list.h"

template<typename type>
class queue
{
private:
  typedef list_node<type> node;

  node *head, *tail;

public:
  queue() : head(nullptr), tail(nullptr)
  {
  } // End of constructor 

  queue & push(const type & data);

  queue & operator<<(const type & data)
  {
    push(data);
    return *this;
  } // End of 'operator<<' function 

  type pop();

  queue & operator>>(type & data)
  {
    data = pop();
    return *this;
  } // End of 'operator>>' function 

  bool isEmpty()
  {
    return head == nullptr;
  } // End of 'isEmpty' function 

  ~queue();
}; // end of 'queue' class 

#include "queue.hpp"

#endif // _QUEUE_H__
