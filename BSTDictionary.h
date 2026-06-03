#pragma once
#include "Pair.h"
#include "LinkedList.h"
#include "Dictionary.h"
#include <stdexcept>
#include <iostream>

using namespace std;

template<typename K, typename V>
class BSTDictionary : public Dictionary<K, V> {
private:
    class Node {
    public:
        Pair<K, V> element;
        Node* left;
        Node* right;

        Node(Pair<K, V> elem) : element(elem), left(nullptr), right(nullptr) {}
    };

    Node* root;
    int count;

    Node* insertAux(Node* current, Pair<K, V> element) {
        if (current == nullptr) {
            count++;
            return new Node(element);
        }
        if (element.key == current->element.key)
            throw runtime_error("DUPLICATED KEY");
        if (element.key < current->element.key)
            current->left = insertAux(current->left, element);
        else
            current->right = insertAux(current->right, element);
        return current;
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;
        return node;
    }

    Node* removeAux(Node* current, K key, V& removedValue) {
        if (current == nullptr)
            throw runtime_error("KEY NOT FOUND");
        if (key < current->element.key)
            current->left = removeAux(current->left, key, removedValue);
        else if (key > current->element.key)
            current->right = removeAux(current->right, key, removedValue);
        else {
            removedValue = current->element.value;
            if (current->left == nullptr && current->right == nullptr) {
                delete current;
                count--;
                return nullptr;
            }
            else if (current->left == nullptr) {
                Node* temp = current->right;
                delete current;
                count--;
                return temp;
            }
            else if (current->right == nullptr) {
                Node* temp = current->left;
                delete current;
                count--;
                return temp;
            }
            else {
                Node* minNode = findMin(current->right);
                current->element = minNode->element;
                current->right = removeAux(current->right, minNode->element.key, removedValue);
            }
        }
        return current;
    }

    Pair<K, V>* findNode(Node* current, K key) {
        if (current == nullptr)
            return nullptr;
        if (key == current->element.key)
            return &(current->element);
        if (key < current->element.key)
            return findNode(current->left, key);
        else
            return findNode(current->right, key);
    }

    void clearAux(Node* current) {
        if (current != nullptr) {
            clearAux(current->left);
            clearAux(current->right);
            delete current;
        }
    }

    void getKeysAux(Node* current, List<K>* list) {
        if (current != nullptr) {
            getKeysAux(current->left, list);
            list->append(current->element.key);
            getKeysAux(current->right, list);
        }
    }

    void getValuesAux(Node* current, List<V>* list) {
        if (current != nullptr) {
            getValuesAux(current->left, list);
            list->append(current->element.value);
            getValuesAux(current->right, list);
        }
    }

public:
    BSTDictionary() : root(nullptr), count(0) {}

    ~BSTDictionary() {
        clear();
    }

    void insert(K key, V value) {
        Pair<K, V> p(key, value);
        root = insertAux(root, p);
    }

    V remove(K key) {
        V removedValue;
        root = removeAux(root, key, removedValue);
        return removedValue;
    }

    V getValue(K key) {
        Pair<K, V>* p = findNode(root, key);
        if (p == nullptr)
            throw runtime_error("KEY NOT FOUND");
        return p->value;
    }

    void setValue(K key, V value) {
        Pair<K, V>* p = findNode(root, key);
        if (p == nullptr)
            throw runtime_error("KEY NOT FOUND");
        p->value = value;
    }

    bool contains(K key) {
        return findNode(root, key) != nullptr;
    }

    bool isEmpty() {
        return count == 0;
    }

    void clear() {
        clearAux(root);
        root = nullptr;
        count = 0;
    }

    List<K>* getKeys() {
        List<K>* keys = new LinkedList<K>();
        getKeysAux(root, keys);
        return keys;
    }

    List<V>* getValues() {
        List<V>* values = new LinkedList<V>();
        getValuesAux(root, values);
        return values;
    }

    int getSize() {
        return count;
    }

    void print() {
        cout << "{ ";
        List<Pair<K, V>>* allPairs = new LinkedList<Pair<K, V>>();
        getPairsAux(root, allPairs);
        for (allPairs->goToStart(); !allPairs->atEnd(); allPairs->next()) {
            Pair<K, V> p = allPairs->getElement();
            cout << p.key << " : " << p.value;
            if (allPairs->getPos() < allPairs->getSize() - 1)
                cout << ", ";
        }
        cout << " }";
        delete allPairs;
    }

    void update(Dictionary<K, V>* D) {
        if (D == nullptr) return;
        List<K>* keys = D->getKeys();
        for (keys->goToStart(); !keys->atEnd(); keys->next()) {
            K key = keys->getElement();
            V value = D->getValue(key);
            if (contains(key))
                setValue(key, value);
            else
                insert(key, value);
        }
        delete keys;
    }

    void zip(List<K>* keys, List<V>* values) {
        if (keys == nullptr || values == nullptr) return;
        int keysSize = keys->getSize();
        int valuesSize = values->getSize();
        int pairsToProcess = (keysSize < valuesSize) ? keysSize : valuesSize;
        keys->goToStart();
        values->goToStart();
        for (int i = 0; i < pairsToProcess; i++) {
            K key = keys->getElement();
            V value = values->getElement();
            if (contains(key))
                setValue(key, value);
            else
                insert(key, value);
            keys->next();
            values->next();
        }
    }

private:
    void getPairsAux(Node* current, List<Pair<K, V>>* list) {
        if (current != nullptr) {
            getPairsAux(current->left, list);
            list->append(current->element);
            getPairsAux(current->right, list);
        }
    }
};