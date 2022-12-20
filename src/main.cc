#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "cambio.h"

using namespace std;

int main (int argc, char *argv[]) { 
    float dinero_decimal_ = stof(argv[1]);
    float dinero_entero_ = stoi(argv[1]);

    Cambio dinero(dinero_entero_, dinero_decimal_);
}