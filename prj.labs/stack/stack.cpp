#include "stack.h"

Stack::Stack(const Stack& stack)
{
  if (stack.head_node_ != nullptr)
  {
    head_node_ = new Node();
    head_node_->data_ = stack.head_node_->data_;
    Node* ucazatel_this = head_node_;
    Node* ucazatel_stack = stack.head_node_->next_node_;
    while (ucazatel_stack != nullptr)
    {
      ucazatel_this->next_node_ = new Node();
      ucazatel_this->next_node_->data_ = ucazatel_stack->data_;

      ucazatel_this = ucazatel_this->next_node_;
      ucazatel_stack = ucazatel_stack->next_node_;
    }
  }
}

void Stack::Push(const int data)
{
  Node* new_head = new Node();
  new_head->data_ = data;
  new_head->next_node_ = head_node_;
  head_node_ = new_head;
}
int Stack::Pop()
{
  if (IsEmpty())
  {
    throw std::out_of_range("Empty");
  }
  int data = head_node_->data_;
  Node* head_node = head_node_;
  head_node_ = head_node_->next_node_;
  delete head_node;
  return data;
}

int Stack::Top()
{
  if (IsEmpty())
  {
    throw std::out_of_range("Empty");
  }
  return head_node_->data_;
}


Stack& Stack::operator=(const Stack& stack)
{
  if (this != &stack)
  {
    if (head_node_ == nullptr)
    {
      head_node_ = new Node();
    }
    head_node_->data_ = stack.head_node_->data_;

    Node* ucazatel_this = head_node_;
    Node* ucazatel_stack = stack.head_node_;

    while (ucazatel_stack->next_node_ != nullptr)
    {
      if (ucazatel_this->next_node_ == nullptr)
      {
        ucazatel_this->next_node_ = new Node();
      }
      ucazatel_this->next_node_->data_ = ucazatel_stack->next_node_->data_;
      ucazatel_stack = ucazatel_stack->next_node_;
      ucazatel_this = ucazatel_this->next_node_;
    }

    Node* same = ucazatel_this->next_node_;
    ucazatel_this->next_node_ = nullptr;
    while (same != nullptr)
    {
      Node* p = same->next_node_;
      delete same;
      same = p;
    }
  }
  return *this;
}

bool Stack::IsEmpty() const
{
  if (head_node_ == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

void Stack::Clear()
{
  while (!IsEmpty())
  {
    Pop();
  }
}

Stack::~Stack()
{
  Clear();
}

std::ostream& Stack::WriteTo(std::ostream& ostrm) const
{
  Node* printed_node(head_node_);
  ostrm << '{';
  while (printed_node)
  {
    ostrm << printed_node->data_;
    printed_node = printed_node->next_node_;
    if (printed_node)
    {
      ostrm << ", ";
    }
  }
  ostrm << '}';
  return ostrm;
}