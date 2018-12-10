#include <iostream>
#include "dynamic_array.h"

DynamicArray::DynamicArray(const int size)
  : size_(size), data_(new int[size_])
{
  for (int i(0); i < size_; i++)
  {
    data_[i] = 0;
  }
}

DynamicArray::DynamicArray(const DynamicArray& obj)
  :size_(obj.size_), data_(new int[size_])
{
  for (int i = 0; i < size_; i++)
  {
    data_[i] = obj.data_[i];
  }
}



DynamicArray::~DynamicArray()
{
  delete[] data_;
}

int DynamicArray::getSize() const
{
  return size_;
}

void DynamicArray::Resize(const int size)
{
  int* data = new int[size];
  if (size >= size_)
  {
    for (int i = 0; i < size_; i++)
    {
      data[i] = data_[i];
    }
  }
  else
  {
    for (int i = 0; i < size; i++)
    {
      data[i] = data_[i];
    }
  }
  delete data_;
  data_ = data;
  size_ = size;

}

int& DynamicArray::operator[](const int i)
{
  if (i < 0)
  {
    throw std::out_of_range("Uncorrect index. Index < 0!");
  }

  if (i > size_)
  {
    throw std::out_of_range("Uncorrect index. Index more than array size!");
  }

  return data_[i];
}

DynamicArray& DynamicArray::operator=(const DynamicArray& rhs)
{
  if (this != &rhs)
  {
    int* data(new int[rhs.size_]);
    delete data_;
    data_ = data;
    size_ = rhs.size_;
    for (int i = 0; i < rhs.size_; i++)
    {
      data_[i] = rhs.data_[i];
    }
  }
  return *this;
}