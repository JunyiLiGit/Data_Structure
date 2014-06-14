//compile using clang++ -g main.cpp hashTable.cpp -std=c++0x
#include "hashTable.h"
#include <fstream>

int main(){
  HashTable myHash(3);
  std::ifstream fin;
  fin.open("students.txt");
  Record newStudent;
  string blank_line;
  while(fin>>newStudent){
    myHash.insert(newStudent);
    getline(fin, blank_line);
  }
  fin.close();
  //std::cout<<myHash;
  myHash.erase(myHash.find("Darth Vader"));
  std::cout<<myHash;



}
