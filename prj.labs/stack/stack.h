class Stack
{
public:
  Stack() = default;
  Stack(const Stack& stack);
  void Push(const int data);
  int Pop();
  ~Stack();


private:
  struct Node
  {
    int data_{ 0 };
    Node* next_node_{ nullptr };
  };
  Node* head_node_{ nullptr };
};