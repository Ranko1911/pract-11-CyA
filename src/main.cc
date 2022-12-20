#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "cambio.h"

using namespace std;

int main(int argc, char *argv[])
{
    // float a = 1.8;
    // float b = 0.6;

    // float diff = a - b;

    // cout << diff << endl;
    if (argc == 1)
    {
        cout << "No se ha introducido ningun argumento" << endl;
    }
    else if (argc == 2)
    {
        float dinero_ = stof(argv[1]);

        Cambio dinero(dinero_);
        dinero.calcular_cambio_decimal();
        dinero.imprimir_cambio_monedas();
    }
    else if (argc == 3)
    {
        if (argv[1] == "-b")
        {
            float dinero_decimal_ = stof(argv[2]);
            float dinero_entero_ = stoi(argv[2]);

            Cambio dinero(dinero_entero_, dinero_decimal_);
            dinero.calcular_cambio();
            dinero.imprimir_cambio();
        }
        else if (argv[1] == "-o")
        {
            /* code */
        }
        else
        {
            cout << "Argumento no valido" << endl;
        }
    }
    else
    {
        cout << "Demasiados argumentos" << endl;
    }
}