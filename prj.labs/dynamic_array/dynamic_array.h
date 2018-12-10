
#pragma once
#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

class DynamicArray
{
public:
  DynamicArray() = default;
  explicit DynamicArray(const int size);
  DynamicArray(const DynamicArray& obj);

  ~DynamicArray();

  int getSize() const;
  void Resize(const int size);

  int& operator[](const int i);
  DynamicArray& operator=(const DynamicArray& rhs);
private:
  int size_{ 0 };
  int* data_{ nullptr };
};

#endif