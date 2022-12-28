#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "BIGINT.h"

using namespace std;

// clase que implemente el algoritmo de karatsuba
class Karatsuba {
 private:

  public:
    Karatsuba();
    ~Karatsuba();
    BigInt multiply(BigInt x, BigInt y);
    BigInt divide(BigInt x, BigInt y);
    BigInt add(BigInt x, BigInt y);
    BigInt subtract(BigInt x, BigInt y);
    BigInt modulo(BigInt x, BigInt y);
};
