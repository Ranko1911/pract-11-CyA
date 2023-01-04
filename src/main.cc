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
  Karatsuba karatsuba;
  BigInt temp;
  BigInt first("12345678");
  BigInt second("87654321");
  FileManager file_manager;

  if (argc == 1) {
    std::cout << "No se ha introducido ningun argumento" << std::endl;
  } else if (argc == 2) {
    std::cout << "No se ha introducido suficientes argumentos " << std::endl;
  } else if (argc == 3) {
    file_manager.ReadFile(argv[1]);
    std::string primer_fichero = file_manager.GetContent();
    file_manager.SetContent("");

    file_manager.ReadFile(argv[2]);
    std::string segundo_fichero = file_manager.GetContent();
    file_manager.SetContent("");

    BigInt first(primer_fichero);
    BigInt second(segundo_fichero);

    temp = karatsuba.multiply(first, second);
    std::cout << "first * second = " << temp << std::endl;
  } else if (argc == 4) {
    if (strcmp(argv[1], "-k") == 0) {
      file_manager.ReadFile(argv[2]);
      std::string primer_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      file_manager.ReadFile(argv[3]);
      std::string segundo_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      BigInt first(primer_fichero);
      BigInt second(segundo_fichero);

      temp = karatsuba.multiply(first, second);
      std::cout << "first * second = " << temp << std::endl;

    } else if (strcmp(argv[1], "-m") == 0) {
      file_manager.ReadFile(argv[2]);
      std::string primer_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      file_manager.ReadFile(argv[3]);
      std::string segundo_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      BigInt first(primer_fichero);
      BigInt second(segundo_fichero);
      BigInt temp2;
      temp2 = first * second;
      std::cout << "first * second = " << temp2 << std::endl;
    } else {
      cout << "Argumento no valido" << endl;
    }
  } else {
    std::cout << "Demasiados argumentos" << std::endl;
  }
}