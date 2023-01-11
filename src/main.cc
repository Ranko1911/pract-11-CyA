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
    if (strcmp(argv[1], "-r") == 0) {
      // std::cout << "Primer argumento: " << argv[1] << std::endl;
      // std::cout << "Segundo argumento: " << argv[2] << std::endl;

      // generar un numero aleatorio dado el numero de digitos
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
    } else {
      auto start = high_resolution_clock::now();
      file_manager.ReadFile(argv[1]);
      std::string primer_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      file_manager.ReadFile(argv[2]);
      std::string segundo_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      BigInt first(primer_fichero);
      BigInt second(segundo_fichero);

      temp = karatsuba.multiply(first, second);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);

      std::cout << "first * second = " << temp << std::endl;
      std::cout << "Time taken by function: " << duration.count()
                << " microseconds" << std::endl;
    }
  } else if (argc == 4) {
    if (strcmp(argv[1], "-k") == 0) {
      auto start = high_resolution_clock::now();
      file_manager.ReadFile(argv[2]);
      std::string primer_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      file_manager.ReadFile(argv[3]);
      std::string segundo_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      BigInt first(primer_fichero);
      BigInt second(segundo_fichero);

      temp = karatsuba.multiply(first, second);
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      std::cout << "first * second = " << temp << std::endl;
      std::cout << "Time taken by function: " << duration.count()
                << " microseconds" << std::endl;

    } else if (strcmp(argv[1], "-m") == 0) {
      auto start = high_resolution_clock::now();
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
      auto stop = high_resolution_clock::now();
      auto duration = duration_cast<microseconds>(stop - start);
      std::cout << "first * second = " << temp << std::endl;
      std::cout << "Time taken by function: " << duration.count()
                << " microseconds" << std::endl;
    } else {
      cout << "Argumento no valido" << endl;
    }
  } else if (argc == 5) {
    if (strcmp(argv[1], "-n") == 0) {
      // std::cout << "Argumento 1: " << argv[1] << std::endl;
      // std::cout << "Argumento 2: " << argv[2] << std::endl;
      // std::cout << "Argumento 3: " << argv[3] << std::endl;
      // std::cout << "Argumento 4: " << argv[4] << std::endl;

      auto start = high_resolution_clock::now();
      file_manager.ReadFile(argv[3]);
      std::string primer_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      file_manager.ReadFile(argv[4]);
      std::string segundo_fichero = file_manager.GetContent();
      file_manager.SetContent("");

      BigInt first(primer_fichero);
      BigInt second(segundo_fichero);

      if (primer_fichero.length() < atoi(argv[2]) &&
          segundo_fichero.length() < atoi(argv[2])) {
        temp = first * second;
        std::cout << "Menor que " << atoi(argv[2]) << std::endl;
      } else {
        temp = karatsuba.multiply(first, second);
        std::cout << "Mayor que " << atoi(argv[2]) << std::endl;
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
    std::cout << "Demasiados argumentos" << std::endl;
  }
}