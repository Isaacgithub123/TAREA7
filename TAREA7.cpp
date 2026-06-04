#include <iostream>
#include <string>
#include "BSTDictionary.h"
#include "LinkedList.h"

using namespace std;

int main() {
    BSTDictionary<int, string> d1, d2;

    d1.insert(10, "Diez");
    d1.insert(20, "Veinte");
    d1.insert(5, "Cinco");

    d2.insert(1, "Uno");
    d2.insert(2, "Dos");
    d2.insert(3, "Tres");

    int opcion = -1, dict, key, cantidad;
    string value;

    while (opcion != 0) {
        cout << "\nD1: "; d1.print(); cout << endl;
        cout << "D2: "; d2.print(); cout << endl;

        cout << "\n1.Insert\n";
        cout << "2.Remove\n";
        cout << "3.GetValue\n";
        cout << "4.SetValue\n";
        cout << "5.Contains\n";
        cout << "6.Clear\n";
        cout << "7.GetKeys\n";
        cout << "8.GetValues\n";
        cout << "9.Update\n";
        cout << "10.Zip\n";
        cout << "0.Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion >= 1 && opcion <= 8 && opcion != 0) {
            cout << "Diccionario (1 o 2): ";
            cin >> dict;
        }

        if (opcion == 1) {
            cout << "Llave: "; cin >> key;
            cout << "Valor: "; cin >> value;
            try {
                if (dict == 1) d1.insert(key, value);
                else d2.insert(key, value);
                cout << "Insertado" << endl;
            }
            catch (runtime_error& e) {
                cout << "Error: " << e.what() << endl;
            }
        
}