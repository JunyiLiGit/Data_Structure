#include <stdlib.h>
#include <iostream>
#include <vector>
/*insertion sort, which is an efficient algorithm for sorting a small
number of elements
Using incremental approach: having sorted the subarray A[1,2...j-1],
we inserted the single element A[j] into its proper place, yielding the sorted
subarray A[1,2,....j].
Insertion sort works the way many people sort a hand of
playing cards. We start with an empty left hand and the cards face down on the
table. We then remove one card at a time from the table and insert it into the
correct position in the left hand. To find the correct position for a card, we
compare it with each of the cards already in the hand, from right to left.
At all times, the cards held in the left hand are sorted, and these cards
were originally the top cards of the pile on the table.
*/

/*Worest time complaxity: O(n*n)
 if the elements in the input array or vector is reversed order;
 Best time complacity : O(n)
 if the elements in the input array or vector is already sorted.
*/


template <typename T>
void insertion_sort(std::vector <T>& myvector){
for (int j=1; j<myvector.size(); ++j){
  T key = myvector[j];
  int i = j-1;
  while(i>=0 && myvector[i] > key){
    myvector[i+1] = myvector[i];
    i = i-1;
  }

  myvector[i+1] = key;
}

}


template <typename T>
void print_msg(std::vector <T>& v){
for(int i =0; i<v.size(); ++i){
  std::cout<<v[i]<<" ";
}

std::cout<<std::endl;
}
