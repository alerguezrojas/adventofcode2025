#include <iostream>

#include "functions.h"

int main() {
  std::cout << "Numero de veces que pasa por 0: " << readFileContents("input.txt") << std::endl;
  
  return 0;
}
