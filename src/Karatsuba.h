#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "BIGINT.h"

using namespace std;

// clase que implemente el algoritmo de karatsuba
class Karatsuba {
  private:
    int counter = 0;
  public:
    Karatsuba();
    ~Karatsuba();
    BigInt time_complex(BigInt x, BigInt y);
    // BigInt multiplicacion(BigInt x, BigInt y);
    BigInt divide(BigInt x, BigInt y);
    BigInt add(BigInt x, BigInt y);
    BigInt subtract(BigInt x, BigInt y);
    BigInt modulo(BigInt x, BigInt y);
};
