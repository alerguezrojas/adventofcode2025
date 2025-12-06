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
    ranges.push_back({start, end}); // {{start1, end1}, {start2, end2}, ...}

    if (file.peek() == ',') {
      file >> comma; // Leer la coma
    }
  }

  file.close();
  return ranges;
}

long long sumInvalidIDs(const std::vector<Range>& ranges) {
  long long sumInvalidIDs = 0;
  for (const auto& range : ranges) {
    for (long long id = range.start; id <= range.end; ++id) {
      // si la longitud del ID es par y 
      // la primera mitad es igual a la segunda mitad es un ID invalido
      if ((std::to_string(id).length() % 2 == 0) && 
          (std::to_string(id).substr(0, std::to_string(id).length() / 2) == 
           std::to_string(id).substr(std::to_string(id).length() / 2))) {

        sumInvalidIDs += id;
      }
    }
  }
  return sumInvalidIDs;
}


int main() {
  std::cout <<"Total sum of invalid ids: " << sumInvalidIDs(readFile("input.txt")) << std::endl;
  return 0;
}