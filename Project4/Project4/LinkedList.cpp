#include "LinkedList.h"
#include <assert.h>
#include<iostream>
using namespace std;
template <class T>
Node<T>::Node()
{
	value = 0;
	next = 0;
}

template <class T>
Node<T>::Node(T val)
{
	value = val;
	next = 0;
}

template <class T>
LinkedList<T>::LinkedList(void)
{
	head = tail = 0;
	count = 0;
}

template <class T>
int LinkedList<T>::Length()
{
	return count;
}

template <class T>
void LinkedList<T>::Append(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (head == 0)
		head = tail = newNode;
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
	count++;
}

template<class T>
T LinkedList<T>::GetMin()
{
	assert(head != nullptr);
	return head->value;
}

template<class T>
void LinkedList<T>::Display()
{
	for (Node<T>* cur = head; cur != nullptr; cur = cur->next)
	{
		cout << cur->value << endl;
	}
}

template<class T>
void LinkedList<T>::Merge(LinkedList<T> x)
{
	for (Node<T>* cur = x.head; cur != nullptr; cur = cur->next)
	{
		this->Insert(cur->value);
	}
}

template<class T>
LinkedList<T> LinkedList<T>::Intersection(LinkedList<T> other)
{
	LinkedList<T> result;
	Node<T>* current1 = head;
	Node<T>* current2 = other.head;
	while (current1 && current2) {
		if (current1->value < current2->value) {
			current1 = current1->next;
		}
		else if (current1->value > current2->value) {
			current2 = current2->next;
		}
		else {
			result.Insert(current1->value);
			current1 = current1->next;
			current2 = current2->next;
		}
	}
	return result;
}
template <class T>
T LinkedList<T>::At(int pos)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return tmp->value;
}

template <class T>
void LinkedList<T>::InsertAt(int pos, T val)
{
	assert(pos >= 0 && pos < count);
	Node<T>* tmp = head;
	Node<T>* newNode = new Node<T>(val);
	if (pos == 0)
	{
		newNode->next = head;
		head = newNode;
	}
	else
	{
		for (int i = 0; i < pos - 1; i++)
			tmp = tmp->next;

		newNode->next = tmp->next;
		tmp->next = newNode;
	}
	count++;

}

template<class T>
void LinkedList<T>::Insert(T val)
{
	Node<T>* newNode = new Node<T>(val);
	if (!head || val <= head->value) {
		newNode->next = head;
		head = newNode;
		if (!tail) {
			tail = head;
		}
	}
	else if (val >= tail->value) {
		tail->next = newNode;
		tail = newNode;
	}
	else {
		Node<T>* current = head;
		while (current->next && current->next->value < val) {
			current = current->next;
		}
		newNode->next = current->next;
		current->next = newNode;
	}
	count++;
}

template <class T>
void LinkedList<T>::DeleteAt(int pos)
{
	assert(pos < count && pos >= 0);
	int i = 0;
	for (Node<T>* cur = head; cur != nullptr; cur = cur->next, i++)
	{
		if (i == pos - 1)
		{
			Node<T>* c = cur->next->next;
			cur->next = c;
			break;
		}
	}
	count--;

}
template <class T>
LinkedList<T>::~LinkedList(void)
{
	while (count != 0)
		DeleteAt(0);
}
