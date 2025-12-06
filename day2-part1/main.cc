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




int main() {
  // std::cout << "Mostramos datos procesados del fichero:" << std::endl;
  // std::vector<Range> ranges = readFile("input.txt");
  // for (const auto& range : ranges) {
  //   std::cout << "Rango: " << range.start <<  " " << range.end << std::endl;
  // }

  
  return 0;
}