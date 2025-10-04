#include <fstream>
#include <string>

#include "LinkedList.h"

typedef std::string String;

const String IN_FILE = "input.txt";
const String OUT_FILE = "output.txt";

void populateNames(const String& fileName, LinkedList& list) {
  std::ifstream inFile(fileName);
  if (!inFile.is_open()) {  // Check if the file opened successfully
    throw std::runtime_error("'" + fileName +
                             "' could not be found. Aborting.");
  }

  String line;
  while (std::getline(inFile, line)) {
    list.insertLast(line);
  }
}

int main() {
  LinkedList names = LinkedList();

  populateNames(IN_FILE, names);
  names.print();
}
