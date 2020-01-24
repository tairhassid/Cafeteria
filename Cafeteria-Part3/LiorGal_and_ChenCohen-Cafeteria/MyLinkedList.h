#ifndef __MY_LINKED_LIST_H
#define __MY_LINKED_LIST_H
#include <iostream>
using namespace std;


//The linked list must contain pointers, and all the elements must implement operator<< 
//each element must have method getId()
template <class T>
class Node;


template<class T>
class MyLinkedList {

private:
	Node<T>* head;
	Node<T>* tail;
	int size;


public:
	MyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
	MyLinkedList(const MyLinkedList& other) = delete;
	~MyLinkedList();

	void insertLast(T data);
	T removeItem(int index) throw (const string&);
	void print() const;
	int getSize() const;

};


template<class T>
class Node
{
	friend class MyLinkedList<T>;

private:
	T data;
	Node<T>* next;

public:
	Node<T>(const T& data) : data(data), next(nullptr) {}

};


template<class T>
MyLinkedList<T>::~MyLinkedList()
{
	Node<T>* current = this->head;
	Node<T>* temp = nullptr;

	while (current)
	{
		temp = current->next;
		delete current;
		current = temp;
	}
}

template<class T>
void MyLinkedList<T>::insertLast(T data)
{
	Node<T>* newNode = new Node<T>(data);
	if (tail == nullptr)
	{
		newNode->next = nullptr;
		tail = newNode;
		head = newNode;
		size++;
		return;
	}
	tail->next = newNode;
	tail = tail->next;
	size++;
}

template<class T>
int MyLinkedList<T>::getSize() const
{
	return size;
}

template<class T>
void MyLinkedList<T>::print() const
{
	Node<T>* current = head;

	while (current)
	{
		cout << "\n" << *(current->data) << endl;
		current = current->next;
	}

}

template<class T>
T MyLinkedList<T>::removeItem(int id) throw (const string&)
{
	if (head == nullptr)
	{
		throw string("empty list!");
	}

	T data;
	Node<T>* current = head;
	Node<T>* previous = nullptr;

	if ((current->data)->getId() == id)
	{
		if (current == tail)
			tail = nullptr;
		data = head->data;
		head = current->next;
		size--;
		delete current;
		return data;
	}

	while (current != nullptr && (current->data)->getId() != id)
	{
		previous = current;
		current = current->next;
	}

	if (current != nullptr)
	{
		data = current->data;
		previous->next = current->next;
		size--;
		delete current;
		return data;
	}

	throw string("id not found");
}


#endif //MY_LINKED_LIST_H


