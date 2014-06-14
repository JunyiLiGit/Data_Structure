/*
A hash table is a fixed size list of records according to a unique key.
Each block of the hash table is called a bucket
The key is usually one of the data fields in the record
Bucket may be empty, so the hash table wast memory
The hash function maps the record's key to an integer called the hash index.
This tells us which bucket to put the record into.
If every key maps to unique hash index, then the hash table operations are very fast
*/
/*
A collision happens when two keys are maped to the same hash index.
One way to resolve collision is to allow each bucket to store multiple records.
That is called chaining
We must have a way to hash a key to an interger index
*/
#include <string>
#include <iostream>
#include <vector>


using std::string;

class Record{
public:
//  Record();
//  ~Record();
  const string& getKey() const;
  void setKey(const string& key);
  int getHash(const int M) const;
  friend std::istream& operator>>(std::istream& in,  Record& r);
  friend std::ostream& operator<<(std::ostream& out, const Record& r);
private:
  string name;
  string id_number;
  int rank;
  double gpa;
  string major;
};


class HashTable{
public:
  HashTable(int tableSize);
  void insert(const Record& newRecord);
  Record* find (const string& key);
  void erase(Record* pos);
  friend std::istream& operator>>(std::istream& in, const HashTable& right);
  friend std::ostream& operator<<(std::ostream& out, const HashTable& right);

private:
  std::vector< std::vector<Record> > table;
};
