#include "file_manager.h"

/**
 * @brief Construct a new File Manager:: File Manager object
 * 
 */
FileManager::FileManager() {}

/**
 * @brief Destroy the File Manager:: File Manager object
 * 
 */
FileManager::~FileManager() {}

/**
 * @brief 
 * 
 * @param file_name 
 */
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

/**
 * @brief 
 * 
 * @param file_name 
 * @param content 
 */
void FileManager::WriteFile(std::string file_name, std::string content) {
  std::ofstream file(file_name);
  if (file.is_open()) {
    file << content;
    file.close();
  } else {
    std::cout << "Unable to open file";
  }
}

/**
 * @brief 
 * 
 * @return std::string 
 */
std::string FileManager::GetContent() { return content_; }

/**
 * @brief 
 * 
 * @param content 
 */
void FileManager::SetContent(std::string content) { content_ = content; }

// Path: src/file_manager.h