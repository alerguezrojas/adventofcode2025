#include "functions.h"

int readFileContents(const std::string& filename) {
  std::ifstream input(filename);
  if (!input.is_open()) {
    std::cerr << "Error al abrir el fichero: " << filename << std::endl;
    return -1;
  }

  std::string line;
  while (std::getline(input, line)) {
    interpretLine(line);
  }
  input.close();
  return operateLine(0);
}

int interpretLine(const std::string& line) {
  std::string sub = line.substr(1, 1);
  int value = std::stoi(sub);

  if (line[0] == 'L') {
    return operateLine(-value);
  } else if (line[0] == 'R') {
    return operateLine(value);
  }
  return 0;
}

int operateLine(int value) {
  static int state = 50;
  static int result;
  static int count = 0;
  result = (state += value) % 100;
  if (result == 0) {
    count ++;
  }
  return count;
}



