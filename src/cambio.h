#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>



class Cambio {
    private:
        float dinero_decimal_;
        int dinero_entero_;

        std::vector<std::pair <float,int>> cambio_entero_; 
        std::vector<std::pair <float,int>> cambio_decimal_; 

        std::vector<std::pair <int  ,int>> cambio_alternarivo_; //alternativo con monedas
        std::vector<std::pair <int  ,int>> cambio_alternarivo_2; // alternativo con billetes

        std::vector<float> monedas_ = {2.0, 1.0 , 0.5, 0.2, 0.1, 0.05, 0.02, 0.01}; //valor de monedas
        std::vector<float> billetes_ = {500.0, 200.0, 100.0, 50.0, 20.0, 10.0, 5.0}; //valor de billetes

        std::vector<int> monedas_alternativo_ = {200, 100, 50, 20, 10, 5, 2, 1}; // valores para calcular las monedas en el modo alternativo
        std::vector<int> billetes_alternativo_ = {50000, 20000, 10000, 5000, 2000, 1000, 500}; // valores para calcular los billetes en el modo alternativo

    public:
        Cambio();
        Cambio(int dinero_entero_, float dinero_decimal_);
        Cambio(float dinero);
        ~Cambio();
        void calcular_cambio();
        void calcular_cambio_decimal();
        void calcular_cambio_entero();

        void calcular_cambio_alternativo();
        void calcular_cambio_alternativo_2();

        void imprimir_cambio();
        void imprimir_cambio_monedas(); 

        void Alternativo();
        void imprimir_cambio_alternativo();
        void imprimir_cambio_alternativo_2();
};