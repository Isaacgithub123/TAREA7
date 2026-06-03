#include <iostream>
#include <string>
#include "BSTDictionary.h"  
using namespace std;

int main() {
    BSTDictionary<int, string> diccionario1;
    BSTDictionary<int, string> diccionario2;

    diccionario1.insert(10, "Diez");
    diccionario1.insert(20, "Veinte");
    diccionario1.insert(5, "Cinco");


    diccionario2.insert(1, "Uno");
    diccionario2.insert(2, "Dos");
    diccionario2.insert(3, "Tres");

    cout << "Diccionario 1: ";
    diccionario1.print();
    cout << endl;

    cout << "Diccionario 2: ";
    diccionario2.print();
    cout << endl;

    return 0;
}