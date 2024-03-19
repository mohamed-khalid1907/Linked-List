#pragma once

template <class T>
class Node
{
public:
	Node<T>* next;
	T value;

	Node();
	Node(T val);
};

template <class T>
class LinkedList
{
	int count;
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList();
	int Length();
	T At(int);
	void InsertAt(int, T);
	void Insert(T);
	void Append(T);
	T GetMin();
	void Display();
	void Merge(LinkedList<T>);
	LinkedList<T> Intersection(LinkedList<T>);
	void DeleteAt(int);
	~LinkedList(void);
};

