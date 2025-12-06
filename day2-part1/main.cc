#include <vector>
#include <string>
#include <fstream>
#include <iostream>


struct Range {
  long long start;
  long long end;
};

std::vector<Range> readFile(const std::string& filename) {
  std::vector<Range> ranges;
  std::ifstream file(filename);

  if (!file.is_open()) {
    std::cerr << "Error: No se pudo abrir el fichero." << std::endl;
    return ranges;
  }

  long long start, end;
  char hyphen, comma;

  while(file >> start >> hyphen >> end) {
    
  }
  
}


int main() {

  
  return 0;
}