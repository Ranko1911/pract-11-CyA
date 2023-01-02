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
    result = x[0] * y[0];
    return result;
  }
  int half = k / 2;
  for (int i = 0; i < half; i++) {
    a.digits.push_back(x[i]);
    c.digits.push_back(y[i]);
  }
  for (int i = half; i < k; i++) {
    b.digits.push_back(x[i]);
    d.digits.push_back(y[i]);
  }
  ac = multiply(a, c);
  bd = multiply(b, d);
  BigInt a1;
  a1 = add(a, b); // a1 = a + b
  BigInt c1;
  c1 = add(c, d); // c1 = c + d
  abcd = multiply(a1, c1);
  BigInt a2;
  a2 = subtract(abcd, ac); // a2 = abcd - ac
  adbc = subtract(a2, bd);
  for (int i = 0; i < 2 * half; i++) {
    ac.digits.push_back(0);
  }
  for (int i = 0; i < half; i++) {
    adbc.digits.push_back(0);
  }
  BigInt a3;
  a3 = add(ac, bd); // a3 = ac + bd
  result = add(a3, adbc);
  return result;
}
