#include "quick.h"
#include <stdlib.h>
#define NUMBER 100

int main(){
  std::vector<int> myvector;
  myvector.reserve(NUMBER);


  for(int i=0; i<NUMBER; ++i){
    myvector.push_back(rand()%1000);
    std::cout<<myvector[i]<<" ";
  }
  std::cout<<std::endl;
  quickSort(myvector,0, myvector.size()-1);

  for(int i=0; i<NUMBER; ++i){
   std::cout<<myvector[i]<<" ";
  }


  std::cout<<std::endl;


}
