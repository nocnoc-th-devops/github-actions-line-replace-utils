#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <regex>

const std::string PREFIX = "/github/workspace/";

int main(int argc, char *argv[]) {
  if (argc != 5) {
    std::cerr << "Invalid argument!" << std::endl;
    std::cerr << "Usage: " << argv[0] << " <input file> <line pattern> <value|file> <string value|path to file>" << std::endl;
    std::cerr << "Example:" << argv[0] << " data.txt 'hello.+' value 'Hello World'" << std::endl;
    return -1;
  }
  std::string input_file = PREFIX;
  input_file.append(argv[1]);

  std::string file_path = PREFIX;
  file_path.append(argv[4]);

  const char * INPUT_FILE   = input_file.c_str();
  const char * LINE_PATTERN = argv[2];
  const char * MODE         = argv[3];
  const char * STRING_VALUE = argv[4];
  const char * FILE_PATH    = file_path.c_str();

  if (!(strcmp(MODE, "value") == 0 || strcmp(MODE, "file") == 0)) {
    std::cerr << "The replacement type can only be 'value' or 'file'!" << std::endl;
    return -2;
  }

  struct stat st;
  if (stat(INPUT_FILE, &st) != 0) {
    std::cerr << stat(INPUT_FILE, &st) << std::endl;
    std::cerr << INPUT_FILE << " does not exist!" << std::endl;
    return -2;
  }

  bool stringMode = strcmp(MODE, "value") == 0;

  if (!stringMode && stat(FILE_PATH, &st) != 0) {
    std::cerr << FILE_PATH << " does not exist!" << std::endl;
    return -2;
  }

  std::ifstream infile(INPUT_FILE);
  std::string line;
  
  std::regex re(LINE_PATTERN);
  std::cout << "replaced_string=";
  while (std::getline(infile, line)) {
    if (std::regex_match(line, re)) {
      if (stringMode) {
        std::cout << STRING_VALUE << std::endl;
      }
      else {
        std::ifstream replacementfile(FILE_PATH);
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

