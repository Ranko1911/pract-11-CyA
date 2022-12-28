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
  if (carry) {
    result.digits.push_back(carry);
  }
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
  return result;
}

//algoritmo de multiplicacion recursivo de karatsuba
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
  abcd = multiply(add(a,b), add(c, d));
  adbc = subtract(subtract(abcd, ac), bd);
  for (int i = 0; i < 2 * half; i++) {
    ac.digits.push_back(0);
  }
  for (int i = 0; i < half; i++) {
    adbc.digits.push_back(0);
  }
  result = add(add(ac, bd), adbc);
  return result;
}
