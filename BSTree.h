#pragma once


template <typename E>
class BSTree {
private:
	BSTNode<E>* root;

	BSTNode<E>* insertAux(BSTNode<E>* current, E element) {
		if (current == nullptr)
			return new BSTNode<E>(element);
		if (element == current->element)
			throw runtime_error("duplicated");
		if (element < current->element)
			current->left = insertAux(current->left, element);
		else
			current->right = insertAux(current->right, element);
		return current;
	}

public:
	BSTree() {
		root = nullptr;
	}
	~BSTree() {
		clear()
	}

	void insert(E element) {
		insertAux(root, element);
	}

};

