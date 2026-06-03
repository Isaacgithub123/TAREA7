include <iostream>
#include <string>
#include "BSTDictionary.h"
#include "LinkedList.h"
using namespace std;

void mostrarMenu() {
    cout << "\n========== MENU ==========" << endl;
    cout << "1. Insert" << endl;
    cout << "2. Remove" << endl;
    cout << "3. GetValue" << endl;
    cout << "4. SetValue" << endl;
    cout << "5. Contains" << endl;
    cout << "6. Clear" << endl;
    cout << "7. GetKeys" << endl;
    cout << "8. GetValues" << endl;
    cout << "9. Update" << endl;
    cout << "10. Zip" << endl;
    cout << "11. Salir" << endl;
    cout << "=========================" << endl;
}

void mostrarDiccionarios(BSTDictionary<int, string>& d1, BSTDictionary<int, string>& d2) {
    cout << "\n--- DICCIONARIO 1 ---" << endl;
    cout << "Tamano: " << d1.getSize() << " | Contenido: ";
    d1.print();
    cout << endl;

    cout << "--- DICCIONARIO 2 ---" << endl;
    cout << "Tamano: " << d2.getSize() << " | Contenido: ";
    d2.print();
    cout << endl;
}
}