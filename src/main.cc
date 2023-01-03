#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Karatsuba.h"

using namespace std;

BigInt NthCatalan(int n) {
  BigInt a(1), b;
  for (int i = 2; i <= n; i++) a *= i;
  b = a;
  for (int i = n + 1; i <= 2 * n; i++) b *= i;
  a *= a;
  a *= (n + 1);
  b /= a;
  return b;
}

BigInt NthFibonacci(int n) {
  BigInt a(1), b(1), c;
  if (!n) return c;
  n--;
  while (n--) {
    c = a + b;
    b = a;
    a = c;
  }
  return b;
}

BigInt Factorial(int n) {
  BigInt f(1);
  for (int i = 2; i <= n; i++) f *= i;
  return f;
}

// Driver code with some examples
int main() {
  BigInt first("93326215443944152681699238856266700490715968264381621468592963895217599993229915608941463976156518286253697920827223758251185210916864"
);
  // cout << "The number of digits"
  //      << " in first big integer = "
  //      << Length(first) << '\n';
  BigInt second("8709782489089480079416590161944485865569720643940840134215932536243379996346583325877967096332754920644690380762219607476364289411435920190573960677507881394607489905331729758013432992987184764607375889434313483382966801515156280854162691766195737493173453603519594496");
  // if (first == second) {
  //     cout << "first and second are equal!\n";
  // }
  // else
  //     cout << "Not equal!\n";
  // BigInt third("10000");
  // BigInt fourth("100000");
  // if (third < fourth) {
  //     cout << "third is smaller than fourth!\n";
  // }
  // BigInt fifth("10000000");
  // if (fifth > fourth) {
  //     cout << "fifth is larger than fourth!\n";
  // }
  //
  // // Printing all the numbers
  // cout << "first = " << first << '\n';
  // cout << "second = " << second << '\n';
  // cout << "third = " << third << '\n';
  // cout << "fourth = " << fourth<< '\n';
  // cout << "fifth = " << fifth<< '\n';
  //
  // Incrementing the value of first
  // first++;
  // cout << "After incrementing the"
  //      << " value of first is : ";
  // cout << first << '\n';
  // BigInt sum;
  // sum = (fourth + fifth);
  // cout << "Sum of fourth and fifth = "
  //      << sum << '\n';
  // BigInt product;
  // product = second * third;
  // cout << "Product of second and third = "
  //      << product << '\n';
  //
  //     // Print the fibonacci number from 1 to 100
  //     cout << "-------------------------Fibonacci"
  //          << "------------------------------\n";
  //     for (int i = 0; i <= 100; i++) {
  //         BigInt Fib;
  //         Fib = NthFibonacci(i);
  //         cout << "Fibonacci " << i << " = " << Fib<<'\n';
  //     }
  //     cout << "-------------------------Catalan"
  //          << "------------------------------\n";
  //     for (int i = 0; i <= 100; i++) {
  //         BigInt Cat;
  //         Cat = NthCatalan(i);
  //         cout << "Catalan " << i << " = " << Cat<<'\n';
  //     }
  //
  //     // Calculating factorial of from 1 to 100
  //     cout << "-------------------------Factorial"
  //          << "------------------------------\n";
  //     for (int i = 0; i <= 100; i++) {
  //         BigInt fact;
  //         fact = Factorial(i);
  //         cout << "Factorial of "
  //              << i << " = ";
  //         cout << fact << '\n';
  //     }
  //   // This code is contributed
  //   // by Gatea David

  Karatsuba karatsuba;
  BigInt temp;
  temp = karatsuba.multiply(first, second);
  std::cout << "first * second = " << temp << std::endl;
}

// int main2(int argc, char *argv[])
// {
//     float dinero_ = 0.0;
//     if (argc == 1)
//     {
//         cout << "No se ha introducido ningun argumento" << endl;
//     }
//     else if (argc == 2)
//     {
//
//     }
//     else if (argc == 3)
//     {
//         if (strcmp(argv[1] , "-b") == 0)
//         {
//
//         }
//         else if (strcmp(argv[1] , "-o") == 0)
//         {
//
//         }
//         else
//         {
//             cout << "Argumento no valido" << endl;
//         }
//     }
//     else if (argc == 4)
//     {
//         if ((strcmp(argv[1] , "-b") == 0 && strcmp(argv[2] , "-o") == 0) ||
//         strcmp(argv[2] , "-b") == 0 && strcmp(argv[1] , "-o") == 0)
//         {
//
//         }
//         else
//         {
//             cout << "Argumento no valido" << endl;
//         }
//     }else
//     {
//         cout << "Demasiados argumentos" << endl;
//     }
// }