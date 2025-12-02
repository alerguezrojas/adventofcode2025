#include "functions.h"

// Variables estáticas a nivel de archivo para mantener el estado
// pero permitir su reinicio en cada lectura de fichero.
static int state = 50;
static int count = 0;

int readFileContents(const std::string& filename) {
  // Reiniciar el estado para cada nuevo fichero
  state = 50;
  count = 0;

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
  
  return count; 
}

int interpretLine(const std::string& line) {
  std::string sub = line.substr(1,line.length() - 1);
  int value = std::stoi(sub);

  // si es L se resta y si es R se suma
  if (line[0] == 'L') {
    value = -value;
  }
  return operateLine(value);
}

int operateLine(int value) {
  state = (state + value) % 100;
  if (state == 0) {
    count ++;
  }
  return count;
}
