#include "file_manager.h"

FileManager::FileManager() {}

FileManager::~FileManager() {}

void FileManager::ReadFile(std::string file_name) {
  std::ifstream file(file_name);
  std::string line;
  if (file.is_open()) {
    while (getline(file, line)) {
      content_ += line;
    }
    file.close();
  } else {
    std::cout << "Unable to open file";
  }
}

void FileManager::WriteFile(std::string file_name, std::string content) {
  std::ofstream file(file_name);
  if (file.is_open()) {
    file << content;
    file.close();
  } else {
    std::cout << "Unable to open file";
  }
}

std::string FileManager::GetContent() { return content_; }

void FileManager::SetContent(std::string content) { content_ = content; }

// Path: src/file_manager.h