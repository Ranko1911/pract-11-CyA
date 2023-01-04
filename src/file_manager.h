#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
//clase para el manejo de fciheros de entrada y de salida

//clase para el manejo de fciheros de entrada y de salida

class FileManager {
 public:
  FileManager();
  ~FileManager();
  void ReadFile(std:: string file_name);
  void WriteFile(std::string file_name, std::string content);
  std::string GetContent();
  void SetContent(std::string content);
  private:
  std::string content_;
};