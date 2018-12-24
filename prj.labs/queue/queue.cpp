#include "queue.h"

Queue::Queue(int size)
  :size_(size + 1)
{
  data_ = new int[size_];
}

Queue::Queue(const Queue& queue)
  : size_(queue.size_)
  , first_(queue.first_)
  , last_(queue.last_)
{
  data_ = new int[size_];
  for (int i = 0; i < size_; i++)
  {
    data_[i] = queue.data_[i];
  }
}

Queue::~Queue()
{
  delete[] data_;
}

bool Queue::IsEmpty() const
{
  return first_ == last_;
}

bool Queue::IsFull() const
{
  return (first_ == (last_ + 1) % size_)&&((size_ - 1) != 0);
}

int Queue::Top() const
{
  if (IsEmpty())
  {
    throw std::out_of_range("empty");
  }
  return data_[first_];
}

int Queue::Pop()
{
  if (IsEmpty())
  {
    throw std::out_of_range("empty");
  }
  int data = data_[first_];
  first_ = (first_ + 1) % size_;
  return data;
}

void Queue::Push(int value)
{
  if (IsFull())
  {
    throw std::out_of_range("full");
  }
  data_[last_] = value;
  last_ = (last_ + 1) % size_;
}

std::ostream & Queue::WriteTo(std::ostream & strm) const
{
  strm << "{";
  if (size_ > 1)
  {
    int i = first_;
    while (i != last_)
    {
      strm << data_[i];
      i = (i + 1) % size_;
      if (last_ != i)
      {
        strm << ", ";
      }
    }
  }
  strm << "}";
  return strm;
}

Queue& Queue::operator=(const Queue& queue)
{
  if (this != &queue)
  {
    if (queue.size_ > size_)
    {
      int* new_data = new int[queue.size_];
      delete data_;
      data_ = new_data;
    }
    int i = queue.first_;
    while (i != queue.last_)
    {
      data_[i] = queue.data_[i];
      i = (i + 1) % queue.size_;
    }
    first_ = queue.first_;
    last_ = queue.last_;
  }
  return *this;
}

std::ostream& operator<<(std::ostream& strm, Queue& queue)
{
  return queue.WriteTo(strm);
}

int Queue::GetSize()
{
  return size_ - 1;
}