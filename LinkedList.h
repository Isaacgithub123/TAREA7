#pragma once
#include"List.h"
#include<iostream>
#include"Node.h"
#include <stdexcept>

using namespace std;

template<typename E>
class LinkedList :public List<E> {
private:
	Node<E>* head;
	Node<E>* current;
	Node<E>* tail;
	int size;
public:
	LinkedList() {
		head = current = tail = new Node<E>();
		size = 0;
	}
	~LinkedList() {
		clear();
		delete head;
	}
	void insert(E element) {
		current->next = new Node<E>(element, current->next);
		if (current == tail)
			tail = tail->next;
		size++;
	}
	void append(E element) {
		tail = tail->next = new Node<E>(element);
		size++;
	}
	E remove() {
		if (size == 0)
			throw runtime_error("empty");
		if (current == tail)
			throw runtime_error("No current Element");
		E result = current->next->element;
		Node<E>* temp = current->next;
		current->next = temp->next;
		if (temp == tail)
			tail = current;
		delete temp;
		size--;
		return result;
	}
};