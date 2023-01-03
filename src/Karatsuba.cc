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
  // for (int i = 0; i < 2 * half; i++) { //hacer metodo separado
  //   ac.digits.push_back(0); // ac.digits.insert(ac.digits.begin(), 0);
  //   // ac.digits.erase(ac.digits.begin());
  // }
  ac.digits.insert( 0 , 2 * half, '0'-'0');
  // for (int i = 0; i < half; i++) { // hacer metodo separado
  //   adbc.digits.push_back(0);
  // }
  adbc.digits.insert(0 , half, '0' - '0');
  BigInt a3;
  a3 = ac + bd;  // a3 = ac + bd // 5
  result = a3 + adbc; // result = a3 + adbc // 6
  return result;
}

// //karatsuba
// BigInt Karatsuba::multiplicacion(BigInt a, BigInt b) {
	
// 	BigInt result;
	
//     // int n = Length(a);
// 		// int m = Length(b);
//     // if(n < 10 || m < 10)
//     //     return a * b;
//     // int k = (n + m) / 2;
//     // BigInt a1, a0, b1, b0;
//     // // a1 = a >> k; // a1 = a / 2^k
//     // // a0 = a - (a1 << k);
//     // // b1 = b >> k;
//     // // b0 = b - (b1 << k);
//     // BigInt z0;
// 		// z0 = multiplicacion(a0, b0);
//     // BigInt z2;
// 		// z2 = multiplicacion(a1, b1);
//     // BigInt z1;
// 		// z1 = multiplicacion(a0 + a1, b0 + b1) - z0 - z2;
//     // return (z2 << (2 * k)) + (z1 << k) + z0;

// 		    if(a.digits.size() < b.digits.size())
//         multiplicacion(a, b);
//     if(b.digits.size() == 1){
// 				result = a * b.digits[0];
//         return result;
// 		}

//     int n = a.digits.size();
//     int m = b.digits.size();
//     int half = n / 2;
//     BigInt a0, a1, b0, b1;
//     for (int i = 0; i < half;i++){
//         a0.digits.push_back(a.digits[i]);
//         b0.digits.push_back(b.digits[i]);
//     }
//     for (int i = half; i < n;i++){
//         a1.digits.push_back(a.digits[i]);
//         if(i < m)
//             b1.digits.push_back(b.digits[i]);
//     }
//     BigInt z0;
// 		z0 = multiplicacion(a0, b0);
//     BigInt z2;
// 		z2 = multiplicacion(a1, b1);
//     BigInt z1;
// 		BigInt a2;
// 		a2 = add(a0, a1);
// 		BigInt b2;
// 		b2 = add(b0, b1);
// 		z1 = multiplicacion(a2, b2) - z0 - z2;
//     for (int i = 0; i < 2 * half;i++)
//         z2.digits.insert(z2.digits.begin(), 0);
//     for (int i = 0; i < half;i++)
//         z1.digits.insert(z1.digits.begin(), 0);
// 		result = z2 + z1 + z0;
//     return result;
// }