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
  
  std::cout << "--------------- abrir -----------------" << std::endl;

  a = (x / std::pow(10,half));
  c = (y / std::pow(10,half));
  std::cout << "a: " << a << std::endl;
  std::cout << "c: " << c << std::endl;

  b = (x % std::pow(10,half));
  d = (y % std::pow(10,half));
  std::cout << "b: " << b << std::endl;
  std::cout << "d: " << d << std::endl;

  std::cout << "multilpliying a and c in ac" << std::endl;
  ac = multiply(a, c);  
  std::cout << "ac: " << ac << std::endl;

  std::cout << "multilpliying b and d in db" << std::endl;
  bd = multiply(b, d);  
  std::cout << "bd: " << bd << std::endl;

  std::cout << "adding a and b in a1" << std::endl;
  BigInt a1;
  a1 = a + b;  // a1 = a + b 
  std::cout << "a1: " << a1 << std::endl;

  std::cout << "adding c and d in c1" << std::endl;
  BigInt c1;
  c1 = c + d;  // c1 = c + d 
  std::cout << "c1: " << c1 << std::endl;


  std::cout << "multilpliying a1 and c1 in abcd" << std::endl;
  abcd = multiply(a1, c1); // abcd = a1 * c1 
  std::cout << "abcd: " << abcd << std::endl;


  std::cout << "subtracting ac and bd in a2" << std::endl;
  BigInt a2;
  a2 = abcd - ac;  // a2 = abcd - ac 
  std::cout << "a2: " << a2 << std::endl;

  std::cout << "subtracting a2 and bd in adbc" << std::endl;
  adbc = a2 - bd; // adbc = a2 - bd 
  std::cout << "adbc: " << adbc << std::endl;

  std::cout << " insert 0s in ac" << std::endl;
  ac.digits.insert( ac.digits.begin() , 2 * half, '0' - '0'); // ac = ac * 10^2half // '0' - '0' = 0
  std::cout << "ac: " << ac << std::endl;

  std::cout << " insert 0s in adbc" << std::endl;
  adbc.digits.insert(adbc.digits.begin() , half, '0' - '0'); // adbc = adbc * 10^half // '0' - '0' = 0
  std::cout << "adbc: " << adbc << std::endl;

  std::cout << "adding ac and bd in a3" << std::endl;
  BigInt a3;
  a3 = ac + bd;  // a3 = ac + bd 
  std::cout << "a3: " << a3 << std::endl;
  
  std::cout << "adding a3 and adbc in result" << std::endl;
  result = a3 + adbc; // result = a3 + adbc 
  std::cout << "result: " << result << std::endl;
  
  std::cout << "--------------- cerrar -----------------" << std::endl;

  return result;
}
