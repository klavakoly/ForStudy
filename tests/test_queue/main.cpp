#include <iostream>
#include<ostream>
#include "../../prj.labs/queue//queue.h"

int main()
{
  using namespace std;

  Queue queue1;
  cout << "Check default contructor. Return: ";
  queue1.WriteTo(cout);
  cout << endl<< endl;
  Queue queue2(13);
  cout << "Check constructor with size in parametr. Queue size = 13. GetSize return: ";
  cout << queue2.GetSize()<< endl << endl;
  queue2.Push(2);
  queue2.Push(4);
  queue2.Push(27);
  queue2.Push(7);
  Queue queue3(queue2);
  cout << "Check constructor with queue in parametr. " << endl;
  cout << "queue2: ";
  queue2.WriteTo(cout);
  cout << endl;
  cout << "queue2 size = " << queue2.GetSize() << endl;
  cout << "queue3(queue2) return queue3: ";
  queue3.WriteTo(cout);
  cout << endl;
  cout << "queue3 size = " << queue3.GetSize() << endl;
  cout << endl;
  cout << "Check function IsEmpty. queue1 is empty. queue1.IsEmpty() return: ";
  cout << queue1.IsEmpty() << endl << endl;
  cout << "Check function IsEmpty. queue2 isn't empty. queue2.IsEmpty() return: ";
  cout << queue2.IsEmpty() << endl << endl;
  queue2.Push(7);
  queue2.Push(7);
  queue2.Push(7);
  queue2.Push(7);
  queue2.Push(7);
  queue2.Push(7);
  queue2.Push(7);
  queue2.Push(7);
  queue2.Push(7);
  cout << "Check function Full. queue2 is full. queue2.IsFull() return: ";
  cout << queue2.IsFull() << endl << endl;
  cout << "Check function IsFull. queue1 isn't full. queue1.IsFull() return: ";
  cout << queue1.IsFull() << endl << endl;
  cout << "Check function Top(). queue3: ";
  queue3.WriteTo(cout);
  cout << endl;
  cout << "queue3.Top() return: " << queue3.Top() << endl << "queue3 retern: ";
  queue3.WriteTo(cout);
  cout << endl<<endl;
  cout << "Check function Pop(). queue3: ";
  queue3.WriteTo(cout);
  cout << endl;
  cout << "queue3.Pop() return: " << queue3.Pop() << endl << "queue3 retern: ";
  queue3.WriteTo(cout);
  cout << endl << endl;
  cout << "Check function GetSize. queue size = 13. queue.GetSize() return: " << queue2.GetSize() << endl << endl;
  cout << "Check function Push(). queue3 :";
  queue3.WriteTo(cout);
  cout << endl;
  cout << "queue3.Push(15) return queue3: ";
  queue3.Push(15);
  queue3.WriteTo(cout);
  cout << endl<<endl;
  cout << "Check operator=. " << endl;
  cout << "queue2: ";
  queue2.WriteTo(cout);
  cout << endl;
  cout << "queue3: ";
  queue3.WriteTo(cout);
  cout << endl;
  cout << "queue2 = queue3 return queue2: ";
  queue2 = queue3;
  queue2.WriteTo(cout);
  cout << endl<< endl;

}