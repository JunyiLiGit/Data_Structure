#include "hashTable.h"
#include <istream>
#include <sstream>
#include <stdlib.h>

const string& Record::getKey() const{
  return name;
}

void Record::setKey(const string& key){
  name = key;
}

int Record::getHash(const int M) const{
  const string key = getKey();
  int index = 0;
  for(int i=0; i< key.length(); ++i){
    index += (int)key[i];
  }

  index = index % M;
  return index;
}

HashTable::HashTable(int tableSize): table(tableSize){
  //table.resize(tableSize);
}

void HashTable::insert(const Record& newRecord){
  int index = newRecord.getHash(table.size());

  table[index].push_back(newRecord);
}

Record* HashTable::find (const string& key){

  Record tempRecord;
  tempRecord.setKey(key);
  int index = tempRecord.getHash(table.size());
  for(int i = 0; i< table[index].size(); ++i){
    if(table[index][i].getKey() == key){
      return &table[index][i];
    }
  }
return 0;
}

void HashTable::erase(Record *pos){
if(pos == 0) return;
int index = pos->getHash(table.size());
//std::cout<<index<<table.size()<<std::endl;
for (std::vector<Record>::iterator iter = table[index].begin();
          iter != table[index].end();
          ++iter) {
      if (pos == &(*iter)) {
        iter = table[index].erase(iter);
        break;
      }
    }
/*
for(int i = 0; i< table[index].size(); ++i){
  if(&table[index][i] == pos){
    //erase takes an iterator...
    table[index].erase(table[index][i]);
    for(int j = i; j<table[index].size()-1; ++j){
      table[index][j] = table[index][j+1];
    }
  }
  else
    std::cout << "entry not found" << std::endl;
}
*/
}


std::ostream& operator<<(std::ostream& out, const Record& right){
  out << "Name: " << right.name << std::endl;
  out << "ID Number: " << right.id_number << std::endl;
  out << "Rank: " << right.rank << std::endl;
  out << "GPA: " << right.gpa << std::endl;
  out << "Major: " << right.major << std::endl;
  return out;
}

std::ostream& operator<<(std::ostream& out, const HashTable& right){
  for(int i = 0; i<right.table.size(); ++i){
    for(int j = 0; j< right.table[i].size(); ++j){
      Record r = right.table[i][j];
      out<<"Bucket " << i << ",Record " << j << std::endl;
      out<<r<<std::endl;
    }
  }
  return out;
}
/// Read in values for a Record through the input operator
std::istream& operator>>(std::istream& in,  Record& r) {
  std::string line;
  /// Tries to read the first line from the input stream.
  /// If it cannot read the first line, we cannot read the file.
  if (!getline(in, line)) {
    return in;
  }
  /// Set the name to be the value of line
  //getline(in, line);
  r.name = line;
 /// Repeat for the other types
  getline(in, line);
  r.id_number = line;

  getline(in, line);
  r.rank = stoi(line); // uses C++ 11. Compile with -std=c++0x

  getline(in, line);
  r.gpa = stod(line); // uses C++ 11

  getline(in, line);
  r.major = line;

  return in;
}
