#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Karatsuba.h"
#include "file_manager.h"

int main2(int argc, char *argv[]) {
  std::string first_("12345678");
  std::string second_("87654321");
  BigInt first(first_);
  BigInt second(second_);
  Karatsuba karatsuba;
  BigInt temp;
  temp = karatsuba.multiply(first, second);
  std::cout << "first * second = " << temp << std::endl;
  return 0;
}

int main(int argc, char *argv[]) {

  std::string first_("12345678");
  std::string second_("87654321");

  BigInt first(first_);
  BigInt second(second_);

  Karatsuba karatsuba;
  BigInt temp;

  FileManager file_manager;
  file_manager.ReadFile(argv[1]);
  std::string hola = file_manager.GetContent();
  file_manager.ReadFile(argv[2]);
  std::string adios = file_manager.GetContent();

  std::cout << "hola: " << hola << std::endl;
  std::cout << "adios: " << adios << std::endl;

  if (argc == 1) {
    std::cout << "No se ha introducido ningun argumento" << std::endl;
  } else if (argc == 2) {
    std::cout << "No se ha introducido suficientes argumentos " << std::endl;
  } else if (argc == 3) {
    temp = karatsuba.multiply(first, second);
    std::cout << "first * second = " << temp << std::endl;
  } else if (argc == 4) {
    
  } else {
    std::cout << "Demasiados argumentos" << std::endl;
  }
}