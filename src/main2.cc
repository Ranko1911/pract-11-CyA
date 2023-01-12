#include <chrono>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Karatsuba.h"
#include "file_manager.h"

using namespace std::chrono;

// main para la entrada del profe

int main(int argc, char *argv[]) {
  Karatsuba karatsuba;
  BigInt temp;
  // BigInt first("12345678");
  // BigInt second("87654321");
  FileManager file_manager;
  string holder;
  string data1;
  string data2;

  if (argc == 1) {
    std::cin >> data1;
    std::cin >> data2;

    auto start = high_resolution_clock::now();
    ;

    BigInt first(data1);
    BigInt second(data2);

    temp = karatsuba.multiply(first, second);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    std::cout << "first * second = " << temp << std::endl;
    std::cout << "Time taken by function: " << duration.count()
              << " microseconds" << std::endl;
    std::cout << "contador: " << karatsuba.getContador() << std::endl;
  } else if (argc == 2) {
    if (strcmp(argv[1], "-k") == 0) {  // revisar
      auto start = high_resolution_clock::now();
      std::cin >> data1;
      std::cin >> data2;

      BigInt first(data1);
      BigInt second(data2);

      temp = karatsuba.multiply(first, second);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      std::cout << "first * second = " << temp << std::endl;
      std::cout << "Time taken by function: " << duration.count()
                << " microseconds" << std::endl;
      std::cout << "contador: " << karatsuba.getContador() << std::endl;

    } else if (strcmp(argv[1], "-m") == 0) {
      auto start = high_resolution_clock::now();
      // file_manager.ReadFile(argv[1]);
      // std::string primer_fichero = file_manager.GetContent();
      // file_manager.SetContent("");
      //
      // file_manager.ReadFile(argv[2]);
      // std::string segundo_fichero = file_manager.GetContent();
      // file_manager.SetContent("");
      //
      // BigInt first(primer_fichero);
      // BigInt second(segundo_fichero);

      std::cin >> data1;
      std::cin >> data2;

      std::cout << "first: " << data1 << std::endl;
      std::cout << "second: " << data2 << std::endl;

      BigInt first(data1);
      BigInt second(data2);
      BigInt temp2;
      temp2 = first * second;
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      std::cout << "first * second = " << temp2 << std::endl;
      std::cout << "Time taken by function: " << duration.count()
                << " microseconds" << std::endl;

    } else {
      cout << "Argumento no valido" << endl;
    }
  } else if (argc == 3) {
    if (strcmp(argv[1], "-r") == 0) {
      auto start = high_resolution_clock::now();

      int num_digitos = std::stoi(argv[2]);
      std::cout << "num_digitos: " << num_digitos << std::endl;
      std::string primer_numero = "";
      std::string segundo_numero = "";

      for (int i = 0; i < num_digitos; i++) {
        int random = rand() % 10;
        primer_numero += std::to_string(random);
      }
      for (int i = 0; i < num_digitos; i++) {
        int random = rand() % 10;
        segundo_numero += std::to_string(random);
      }

      std::cout << "first: " << primer_numero << std::endl;
      std::cout << "second: " << segundo_numero << std::endl;

      BigInt first(primer_numero);
      BigInt second(segundo_numero);

      temp = karatsuba.multiply(first, second);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      std::cout << "first * second = " << temp << std::endl;
      std::cout << "Time taken by function: " << duration.count()
                << " microseconds" << std::endl;
      std::cout << "contador: " << karatsuba.getContador() << std::endl;

    } else if (strcmp(argv[1], "-n") == 0) {
      auto start = high_resolution_clock::now();

      std::cin >> data1;
      std::cin >> data2;

      BigInt first(data1);
      BigInt second(data2);

      if (Length(first) < atoi(argv[2]) && Length(second) < atoi(argv[2])) {
        temp = first * second;
        std::cout << "Menor que " << atoi(argv[2]) << std::endl;
      } else {
        temp = karatsuba.multiply(first, second);
        std::cout << "Mayor que " << atoi(argv[2]) << std::endl;
        std::cout << "contador: " << karatsuba.getContador() << std::endl;
      }

      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      std::cout << "first * second = " << temp << std::endl;
      std::cout << "Time taken by function: " << duration.count()
                << " microseconds" << std::endl;

    } else {
      cout << "Argumento no valido" << endl;
    }

  } else {
    std::cout << "Argumentos incorrectos" << std::endl;
  }
}