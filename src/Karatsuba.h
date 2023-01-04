#pragma once


#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "BIGINT.h"

using namespace std;

// clase que implemente el algoritmo de karatsuba
class Karatsuba {
  public:
    Karatsuba();
    ~Karatsuba();
    BigInt multiply(BigInt x, BigInt y);
    // BigInt multiplicacion(BigInt x, BigInt y);
    BigInt add(BigInt x, BigInt y);
    BigInt subtract(BigInt x, BigInt y);
};
