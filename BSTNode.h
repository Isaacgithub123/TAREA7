#pragma once



template <typename E>
class BSTNode {
public:
	E elment;
	BSTNode<E>* left;
	BSTNode<E>* right;
	BSTNode(E element) {
		this->elemet = element;
		right = left = nullptr;
	}
};

