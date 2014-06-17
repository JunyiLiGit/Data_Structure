#include <iostream>
#include <array>
#define NUMBER 11

template <typename T>
void print(std::array<T, NUMBER> myarray){
  for(int i = 1; i < myarray.size(); ++i){
    std::cout<<myarray[i]<<" ";
  }
  std::cout<<std::endl;
}

template <typename T>
void exchange(T& i, T& j){
  T temp = i;
  i = j;
  j = temp;
}

template <typename T>
void max_heapify(std::array<T, NUMBER>& A, int i, int heapSize){

  int left = 2*i;
  int right = 2*i + 1;
  int largest = 0;
  if(left <= heapSize && A[left] > A[i]){
     largest = left;
  }
  else largest = i;
  if(right <= heapSize && A[right] > A[largest]){
    largest = right;
  }
  if (largest != i){
    exchange(A[i],A[largest]);
    max_heapify(A, largest,heapSize);
  }
}

template <typename T>
void build_max_heap(std::array<T, NUMBER>& myarray){
  int heapSize = myarray.size()-1;
  for(int i = heapSize/2; i>=1; --i){
    max_heapify(myarray,i,heapSize);
  }
}



template <typename T>
void heapSort(std::array<T, NUMBER>& A){
  build_max_heap(A);
  int heapSize = A.size()-1;
  for(int i= A.size()-1; i>=2; --i){
    exchange(A[1], A[i]);
    heapSize = heapSize - 1;
    max_heapify(A, 1,heapSize);
  }

}
