#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <regex>

int main(int argc, char *argv[]) {
  if (argc != 5) {
    std::cerr << "Invalid argument!" << std::endl;
    std::cerr << "Usage: " << argv[0] << " <input file> <line pattern> <value|file> <string value|path to file>" << std::endl;
    std::cerr << "Example:" << argv[0] << " data.txt 'hello.+' value 'Hello World'" << std::endl;
    return -1;
  }

  if (!(strcmp(argv[3], "value") == 0 || strcmp(argv[3], "file") == 0)) {
    std::cerr << "The replacement type can only be 'value' or 'file'!" << std::endl;
    return -2;
  }

  struct stat st;
  if (stat(argv[1], &st) != 0) {
    std::cerr << stat(argv[1], &st) << std::endl;
    std::cerr << argv[1] << " does not exist!" << std::endl;
    return -2;
  }

  bool stringMode = strcmp(argv[3], "value") == 0;

  if (!stringMode && stat(argv[4], &st) != 0) {
    std::cerr << argv[4] << " does not exist!" << std::endl;
    return -2;
  }

  std::ifstream infile(argv[1]);
  std::string line;
  
  std::regex re(argv[2]);
  std::cout << "replaced_string=";
  while (std::getline(infile, line)) {
    if (std::regex_match(line, re)) {
      if (stringMode) {
        std::cout << argv[4] << std::endl;
      }
      else {
        std::ifstream replacementfile(argv[4]);
        std::string replacement;
        while (std::getline(replacementfile, replacement)) {
          std::cout << replacement << std::endl;
        }
      }
    }
    else {
      std::cout << line << std::endl;
    }
  }

  return 0;
}

