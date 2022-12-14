#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "cambio.h"

using namespace std;

int main (int argc, char *argv[]) { 
    float dinero_decimal_ = stof(argv[1]);
    int dinero_entero_ = stoi(argv[1]);

    dinero_decimal_ = dinero_decimal_ - dinero_entero_;

    cout << "Dinero decimal: " << dinero_decimal_ << endl;
    cout << "Dinero entero: " << dinero_entero_ << endl;

    Cambio dinero(dinero_entero_, dinero_decimal_);
}