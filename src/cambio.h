#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <vector>


class Cambio {
    private:
        float dinero_decimal_;
        float dinero_entero_;
        std::vector<std::pair <float,int>> cambio_entero_;
        std::vector<std::pair <float,int>> cambio_decimal_; 
        std::vector<float> monedas_ = {2, 1 , 0.5, 0.2, 0.1, 0.05, 0.02, 0.01}; //valor en monedas
        std::vector<float> billetes_ = {500, 200, 100, 50, 20, 10, 5}; //valor en billetes

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