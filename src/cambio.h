#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <vector>


class Cambio {
    private:
        float dinero_decimal_;
        float dinero_entero_;
        std::vector<std::pair <int,int>> cambio_entero_;
        std::vector<std::pair <int,int>> cambio_decimal_; 
        std::vector<int> centimos_ = {50, 20, 10, 5, 2, 1}; //valor centimos_
        std::vector<int> euros_ = {500, 200, 100, 50, 20, 10, 5, 2, 1}; //valor en euros_

    public:
        Cambio();
        Cambio(float dinero_entero_, float dinero_decimal_);
        ~Cambio();
        void calcular_cambio();
        void calcular_cambio_decimal_();
        void calcular_cambio_entero_();
        void imprimir_cambio();
};