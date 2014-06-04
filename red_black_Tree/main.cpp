#include <iostream>
#include "redBlackTree.h"
#include <stdlib.h>

/*
template <typename T>
void print_msg(RedBlackTree<T>* t){
std::cout<<t->getRoot()->key<<std::endl;
t->inOrder_tree_walk(t->getRoot());
std::cout<<std::endl;
}
*/

int main(){

  RedBlackTree<int>* t= new RedBlackTree<int>();

  for(int i=1; i<=10; ++i){

    t->rb_insert(i);
  }
std::cout<<"root is "<<t->getRoot()->key<<std::endl;

t->inOrder_tree_walk(t->getRoot());

}
