#include <iostream>
#include <string>
#include "BSTDictionary.h"
#include "LinkedList.h"

using namespace std;

int main() {
    BSTDictionary<int, string> diccionario1;
    BSTDictionary<int, string> diccionario2;

    int opcion = -1;
    int dictSeleccionado;

    diccionario1.insert(10, "Diez");
    diccionario1.insert(20, "Veinte");
    diccionario1.insert(5, "Cinco");

    diccionario2.insert(1, "Uno");
    diccionario2.insert(2, "Dos");
    diccionario2.insert(3, "Tres");

    while (opcion != 0) {
        cout << "\nEstado actual de los diccionarios:\n";
        cout << "Diccionario 1: ";
        diccionario1.print();
        cout << endl;
        cout << "Diccionario 2: ";
        diccionario2.print();
        cout << endl;

        cout << "\nMenu:\n";
        cout << "1. insert\n";
        cout << "2. remove\n";
        cout << "3. getValue\n";
        cout << "4. setValue\n";
        cout << "5. contains\n";
        cout << "6. clear\n";
        cout << "7. getKeys\n";
        cout << "8. getValues\n";
        cout << "9. update\n";
        cout << "10. zip\n";
        cout << "0. Salir\n";

        cout << "Seleccione una opcion: ";
        cin >> opcion;
    }
    if (opcion == 1) {
    int key;
    string value;

    cout << "Seleccione diccionario (1 o 2): ";
    cin >> dictSeleccionado;
    cout << "Ingrese la llave (entero): ";
    cin >> key;
    cout << "Ingrese el valor (string): ";
    cin >> value;

    if (dictSeleccionado == 1) {
        try {
            diccionario1.insert(key, value);
            cout << "Insertado correctamente." << endl;
        }
        catch (runtime_error& e) {
            cout << "No se puede realizar esta operacion." << endl;
        }