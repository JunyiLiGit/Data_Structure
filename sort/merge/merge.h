#include <vector>
#include <iostream>
#include <limits>

template <typename T>
void merge(std::vector<T>& v, int p, int q, int r){
  int n1 = q-p+1;
  int n2 = r-q;
  std::vector<T> vl, vr;
  vl.reserve(n1+1);
  vr.reserve(n2+1);
  for(int i=0; i<n1; ++i){
    vl[i] = v[p+i];
  }

  for(int j=0; j<n2; ++j){
    vr[j] = v[q+j+1];
  }

  int max = std::numeric_limits<int>::max();
  vl[n1] = max;
  vr[n2] = max;
  int i = 0;
  int j = 0;
  for(int k = p; k<=r; ++k){
    if(vl[i] < vr[j]){
      v[k] = vl[i];
      ++i;
    }
    else {
    v[k] = vr[j];
    ++j;
  }

  }
}


template <typename T>
void merge_sort(std::vector<T>& v, int p, int r){
  if (p < r){

    int q = (p+r)/2;
    merge_sort(v,p,q);
    merge_sort(v,q+1,r);
    merge(v,p,q,r);

  }



}
