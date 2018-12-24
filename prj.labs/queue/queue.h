#ifndef QUEUE_2018
#define QUEUE_2018
#include <iostream>

class Queue
{
public:
  Queue() = default;
  explicit Queue(int size);
  Queue(const Queue& queue);
  ~Queue();
  bool IsEmpty() const;
  bool IsFull() const;
  int Top() const;
  int Pop();
  int GetSize();
  void Push(int value);
  std::ostream& WriteTo(std::ostream& strm) const;
  Queue& operator=(const Queue& queue);

private:
  int* data_{ nullptr };
  int size_{ 1 };
  int first_{ 0 };
  int last_{ 0 };
};

std::ostream& operator<<(std::ostream& strm, Queue& queue);

#endif // !QUEUE_2018