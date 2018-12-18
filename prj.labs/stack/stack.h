#ifndef STACK_ON_LIST_2018
#define STACK_ON_LIST_2018

#include <stdexcept>
#include <iostream>


class Stack
{
public:
  Stack() = default;
  Stack(const Stack& stack);
  void Push(const int data);
  int Pop();
  int Top();
  void Clear();
  bool IsEmpty() const;
  std::ostream& WriteTo(std::ostream& ostrm) const;
  Stack& operator=(const Stack& stack);
  ~Stack();


private:
  struct Node
  {
    int data_{ 0 };
    Node* next_node_{ nullptr };
  };
  Node* head_node_{ nullptr };
};

inline std::ostream& operator<<(std::ostream& ostrm, const Stack& stack)
{
  return stack.WriteTo(ostrm);
}
#endif // !STACK_ON_LIST_2018
