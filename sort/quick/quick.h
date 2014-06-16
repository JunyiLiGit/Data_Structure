/*
Divide-and-Conqer
worst: O(n*n)
average: O(nlgn)
*/

#include <iostream>
#include <vector>

template <typename T>
void exchange(T& i, T& j){
  T temp = i;
  i = j;
  j = temp;
}


template <typename T>
int partition(std::vector<T>& A, int p, int r){
  T x = A[r];
  int i = p-1;
  for(int j = p; j<= r-1; ++j){
    if(A[j] <= x){
      i = i+1;
      exchange(A[i],A[j]);
    }
  }
 exchange(A[i+1],A[r]);
 return i+1;
}


template <typename T>
void quickSort(std::vector<T>& A, int p, int r){
  if (p < r){
    int q = partition(A, p, r);
    quickSort(A, p, q-1);
    quickSort(A, q+1, r);
  }
}
