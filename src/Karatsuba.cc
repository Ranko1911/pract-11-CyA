#include "Karatsuba.h"

Karatsuba::Karatsuba() {}

Karatsuba::~Karatsuba() {}

BigInt Karatsuba::add(BigInt x, BigInt y) {
  BigInt result;
  int carry = 0;
  int i = 0;
  while (i < Length(x) || i < Length(y)) {
    int sum = carry;
    if (i < Length(x)) {
      sum += x[i];
    }
    if (i < Length(y)) {
      sum += y[i];
    }
    result.digits.push_back(sum % 10);
    carry = sum / 10;
    i++;
  }

  result.digits.erase(result.digits.begin());

  return result;
}

BigInt Karatsuba::subtract(BigInt x, BigInt y) {
  BigInt result;
  int carry = 0;
  int i = 0;
  while (i < Length(x) || i < Length(y)) {
    int sum = carry;
    if (i < Length(x)) {
      sum += x[i];
    }
    if (i < Length(y)) {
      sum -= y[i];
    }
    if (sum < 0) {
      sum += 10;
      carry = -1;
    } else {
      carry = 0;
    }
    result.digits.push_back(sum);
    i++;
  }

  while (Length(result) > 1 && result[Length(result) - 1] == 0) {
    result.digits.pop_back();
  }

  result.digits.erase(result.digits.begin());

  return result;
}

// algoritmo de multiplicacion recursivo de karatsuba
BigInt Karatsuba::multiply(BigInt x, BigInt y) { 
  BigInt a, b, c, d, ac, bd, abcd, adbc, result;
  int n = Length(x);
  int m = Length(y);
  int k = max(n, m);

  if (k == 1) {
    result = x * y;
    return result;
  }
  int half = k / 2;

  a.digits = x.digits.substr(0, half);
  c.digits = y.digits.substr(0, half);
  std::cout << "a: " << a << std::endl;
  std::cout << "c: " << c << std::endl;

  b.digits = x.digits.substr(half, k);
  d.digits = y.digits.substr(half, k);
  std::cout << "b: " << b << std::endl;
  std::cout << "d: " << d << std::endl;

  ac = multiply(a, c);  // se queda pillado aqui // 4
  bd = multiply(b, d);  // 1
  BigInt a1;
  a1 = a + b;  // a1 = a + b // 3
  BigInt c1;
  c1 = c + d;  // c1 = c + d // 2
  abcd = multiply(a1, c1); // abcd = a1 * c1 // 6
  BigInt a2;
  a2 = abcd - ac;  // a2 = abcd - ac // 2
  adbc = a2 - bd; // adbc = a2 - bd // 1

  ac.digits.insert( 0 , 2 * half, '0'-'0');

  adbc.digits.insert(0 , half, '0' - '0');
  BigInt a3;
  a3 = ac + bd;  // a3 = ac + bd // 5
  result = a3 + adbc; // result = a3 + adbc // 6
  return result;
}
