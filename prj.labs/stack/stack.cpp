#include "stack.h"

Stack::Stack(const Stack& stack)
{
  Node* head_node_=new Node();
  head_node_->data_ = stack.head_node_->data_;
  
  Node* ucazatel_this = head_node_;
  Node* ucazatel = stack.head_node_;
  while (ucazatel!= nullptr)
  {
    give me 20 bytes;
    ucazatel_this->next_node_ = ucazatel->next_node_;
    ucazatel_this=
  }
}

void Stack::Push(const int data)
{
  Node* head_node = new Node();
  head_node->data_ = data;
  head_node->next_node_ = head_node_;
}
int Stack::Pop()
{
  int data = head_node_->data_;
  head_node_ = head_node_->next_node_;
  return data;
}