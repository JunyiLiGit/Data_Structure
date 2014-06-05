#include "insertion.h"

int main(){

  std::vector<float> v;
  v.reserve(30);
  for(int i =0; i<30; ++i){
    v.push_back(rand()%100*0.2);
    std::cout<<v[i]<<" ";
  }

  std::cout<<std::endl;

  insertion_sort(v);

  print_msg(v);



}
