#include "cambio.h"

Cambio::Cambio()
{
    dinero_decimal_ = 0.0;
    dinero_entero_ = 0.0;
}

Cambio::~Cambio()
{
}

Cambio::Cambio(float dinero_entero, float dinero_decimal)
{
    dinero_entero_ = dinero_entero;
    dinero_decimal_ = dinero_decimal * 100 - dinero_entero * 100;
    dinero_decimal_ = dinero_decimal_ / 100;
    // std::cout << std::endl;
    // std::cout << dinero_decimal_ << std::endl;
    // std::cout << dinero_entero_ << std::endl;
}

Cambio::Cambio(float dinero)
{
    dinero_decimal_ = dinero;
    // std::cout << dinero_decimal_ << std::endl;
    // std::cout << std::endl;
}

void Cambio::calcular_cambio()
{
    calcular_cambio_entero();
    calcular_cambio_decimal();
}

void Cambio::calcular_cambio_entero()
{
    int dinero = dinero_entero_;
    int counter = 0;
    std::pair<int, int> variable;
    for (int i = 0; i < billetes_.size(); i++)
    {
        if (dinero == 0)
        {
        }
        else
        {
            while (dinero >= billetes_[i])
            {
                dinero -= billetes_[i];
                counter++;
            }
            variable.second = counter;
            variable.first = billetes_[i];
            cambio_entero_.push_back(variable);
            variable.first = 0;
            variable.second = 0;
            counter = 0;
        }
    }
}

void Cambio::calcular_cambio_decimal()
{
    float dinero = dinero_decimal_;
    int counter = 0;
    std::pair<float, int> variable;
    for (int i = 0; i < monedas_.size(); i++)
    {
        if (dinero == 0.0)
        {
        }
        else
        {
            while (dinero >= monedas_[i])
            {
                dinero -= monedas_[i];
                dinero = round(dinero * 100) / 100;//funciona
                counter++;
            }
            variable.second = counter;
            variable.first = monedas_[i];
            cambio_decimal_.push_back(variable);
            variable.first = 0.0;
            variable.second = 0;
            counter = 0;
        }
    }
}

void Cambio::imprimir_cambio()
{
    int total = 0;

    std::cout << "Solucion: ";

    for (auto i = 0; i < billetes_.size(); i++)
    {
        if (cambio_entero_[i].second == 1)
        {
            std::cout << cambio_entero_[i].first << "€ ";
        }
        else if (cambio_entero_[i].second != 0)
        {
            std::cout << cambio_entero_[i].second << "x" << cambio_entero_[i].first << "€ ";
        }
    }

    for (auto i = 0; i < monedas_.size(); i++)
    {
        if (cambio_decimal_[i].second == 1)
        {
            std::cout << cambio_decimal_[i].first << "¢ ";
        }
        else if (cambio_decimal_[i].second != 0)
        {
            std::cout << cambio_decimal_[i].second << "x" << cambio_decimal_[i].first << "¢ ";
        }
    }

    for (auto i = 0; i < billetes_.size(); i++)
    {
        total += cambio_entero_[i].second;
    }

    for (auto i = 0; i < monedas_.size(); i++)
    {
        total += cambio_decimal_[i].second;
    }

    std::cout << std::endl;
    std::cout << "Total de billetes y/o monedas: " << total << std::endl;
}

void Cambio::imprimir_cambio_monedas()
{
    int total = 0;

    std::cout << "Solucion: ";

    for (auto i = 0; i < monedas_.size(); i++)
    {
        if (cambio_decimal_[i].second == 1)
        {
            std::cout << cambio_decimal_[i].first << "¢ ";
        }
        else if (cambio_decimal_[i].second != 0)
        {
            std::cout << cambio_decimal_[i].second << "x" << cambio_decimal_[i].first << "¢ ";
        }
    }

    for (auto i = 0; i < monedas_.size(); i++)
    {
        total += cambio_decimal_[i].second;
    }

    std::cout << std::endl;
    std::cout << "Total de monedas: " << total << std::endl;
}
