/*testing code*/
#include "binaryTree.h"
#include <stdlib.h>


int main(){
  BinaryTree<int>* b= new BinaryTree<int>();

  for(int i=0; i<10; ++i){

    b->tree_insert(rand()%20);
  }


  b->inOrder_tree_walk(b->getRoot());

  std::cout<<std::endl;
  std::cout<<b->tree_search(5)->key;
  std::cout<<std::endl;

  std::cout<<(b->tree_successor(b->tree_search(5)))->key<<std::endl;

  std::cout<<(b->tree_minimum(b->getRoot()))->key<<std::endl;
  std::cout<<(b->tree_maximum(b->getRoot()))->key<<std::endl;

  std::cout<<b->getRoot()->key<<std::endl;

  std::cout<<(b->tree_delete(5))->key<<std::endl;

  std::cout<<"-------"<<std::endl;
  b->inOrder_tree_walk(b->getRoot());

  std::cout<<std::endl;


}
