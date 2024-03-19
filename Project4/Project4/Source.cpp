#include <iostream>
#include "LinkedList.cpp"
using namespace std;
int main()
{
	LinkedList<int> L;
	LinkedList<int> x;
	LinkedList<int> i;
	L.Insert(1);
	L.Insert(3);
	L.Insert(0);
	x.Insert(5);
	x.Insert(4);
	x.Insert(2);
	x.Insert(3);
	i = L.Intersection(x);
	i.Display();
	x.Merge(L);
	x.Display();
	return 0;
}