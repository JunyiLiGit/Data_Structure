#include "heap.h"
#include <stdlib.h>
int main(){
  std::array<int, NUMBER> myarray = {0,4,1,3,2,16,9,10,14,8,7};
  print(myarray);
  heapSort(myarray);
  print(myarray);
}
