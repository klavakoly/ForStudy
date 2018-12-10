#include <iostream>
#include "dynamic_array.h"

using namespace std;

void GetArray(DynamicArray& array)
{
  for (int i = 0; i < array.getSize(); i++)
  {
    cout << array[i] << " ";
  }
  cout << endl;
}
int main()
{
  DynamicArray array1(5);
  cout << "Test constructor DynamicArray(5): ";
  GetArray(array1);
  cout << endl;
  DynamicArray array2(array1);
  cout << "Test constructor DynamicArray(DynamicArray(5)): ";
  GetArray(array2);
  cout << endl;

  cout << "Test function GetSize array.size_= 5. GetSize return: " << array2.getSize() << endl;
  cout << endl;
  for (int i = 0; i < array1.getSize(); i++)
  {
    array1[i] = 5;
  }

  cout << "Test function Resize array.size_= 5. New size = 7." << endl;
  cout << "Before: ";
  GetArray(array1);
  array1.Resize(7);
  cout << "After: ";
  GetArray(array1);
  cout << endl;

  cout << "Test function Resize array.size_= 7. New size = 3." << endl;
  cout << "Before: ";
  GetArray(array1);
  array1.Resize(3);
  cout << "After: ";
  GetArray(array1);
  cout << endl;

  cout << "Test operator[]. Index < 0. Return: ";
  try
  {
    cout << array1[-3] << endl;
  }
  catch (exception e)
  {
    cout << e.what() << endl;
    cout << endl;
  }

  cout << "Test operator[]. Index > DynamicArray.size. Return: ";
  try
  {
    cout << array1[100] << endl;
  }
  catch (exception e)
  {
    cout << e.what() << endl;
    cout << endl;
  }

  cout << "Test operator[]. Inddex = 2. Return: " << array1[2] << endl;
  cout << endl;

  cout << "Test operator= . Array1 = array2 :" << endl;
  cout << "array1: ";
  GetArray(array1);
  cout << "array2: ";
  GetArray(array2);
  cout << "array1 = array2. Return array1: ";
  array1 = array2;
  GetArray(array1);
  cout << endl;
  system("pause");
  return 0;
}