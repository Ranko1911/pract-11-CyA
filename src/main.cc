#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main (int argc, char *argv[]) { 
    float dinero_decimal = stof(argv[1]);
    int dinero_entero = stoi(argv[1]);

    dinero_decimal = dinero_decimal - dinero_entero;

    cout << "Dinero decimal: " << dinero_decimal << endl;
    cout << "Dinero entero: " << dinero_entero << endl;
}

