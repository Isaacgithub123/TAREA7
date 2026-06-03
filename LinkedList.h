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
	void insert(E element) override {
		current->next = new Node<E>(element, current->next);
		if (current == tail)
			tail = tail->next;
		size++;
	}
	void append(E element) override {
		tail = tail->next = new Node<E>(element);
		size++;
	}
	E remove() override {
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
	void setElement(E element) override {
		if (current == nullptr || current->next == nullptr)
			throw runtime_error("No current element");
		current->next->element = element;
	}
	E getElement() override {
		if (current == nullptr || current->next == nullptr)
			throw runtime_error("No current element");
		return current->next->element;
	}
	void clear() override {
		while (head != nullptr) {
			Node<E>* temp = head;
			head = head->next;
			delete temp;
		}
		head = new Node<E>();
		tail = head;
		current = head;
		size = 0;
	}
	void goToStart() override {
		current = head;
	}
	void goToEnd() override {
		current = tail;
	}
	void goToPos(int pos) override {
		if (pos < 0 || pos > size)
			throw runtime_error("Position out of range");
		current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
	}
	void next() override {
		if (current != nullptr && current->next != nullptr)
			current = current->next;
	}
	void previous() override {
		Node<E>* temp = head;
		while (temp != nullptr && temp->next != current)
			temp = temp->next;
		current = temp;
	}
	bool atStart() override {
		return current == head;
	}
	bool atEnd() override {
		return current == tail;
	}
	int getPos() override {
		int pos = 0;
		Node<E>* temp = head;
		while (temp != nullptr && temp != current) {
			pos++;
			temp = temp->next;
		}
		return pos;
	}
	int getSize() override {
		return size;
	}
	void print() override {
		Node<E>* temp = head->next;
		cout << "[";
		while (temp != nullptr) {
			cout << temp->element;
			if (temp->next != nullptr)
				cout << ", ";
			temp = temp->next;
		}
		cout << "]";
	}
};