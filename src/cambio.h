#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>



class Cambio {
    private:
        float dinero_decimal_;
        float dinero_entero_;
        std::vector<std::pair <float,int>> cambio_entero_;
        std::vector<std::pair <float,int>> cambio_decimal_; 
        std::vector<float> monedas_ = {2.0, 1.0 , 0.5, 0.2, 0.1, 0.05, 0.02, 0.01}; //valor en monedas
        std::vector<float> billetes_ = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0}; //valor en billetes

    public:
        Cambio();
        Cambio(float dinero_entero_, float dinero_decimal_);
        Cambio(float dinero);
        ~Cambio();
        void calcular_cambio();
        void calcular_cambio_decimal();
        void calcular_cambio_entero();
        void imprimir_cambio();
        void imprimir_cambio_monedas(); 
};