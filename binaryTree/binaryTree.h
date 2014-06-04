/*This file implement binary search tree which is also a binary tree.
  For every node in the binary tree it contains key, left, right, and p(parents).
  The p field in root equals NULL(0).
  key[left[x]] <= key[x]; key[right[x]] >= key[x]
  The worst time complaxity of operations on the binary search tree is
  proportional to the height of the tree which is lg(n), n is the number of nodes.
  If the tree is a linked list which contains n nodes, the worst time complaxity
  is O(n)
  */

#include <iostream>
#include <assert.h>

template <typename T>
struct Node{
  T key;
  Node<T>* p;
  Node<T>* left;
  Node<T>* right;
  Node(const T& data=T(), Node<T>* p=0, Node<T>* l=0, Node<T>* r=0):
      key(data),
      p(p),
      left(l),
      right(r){}
};


template <typename T>
class BinaryTree{
public:
  BinaryTree():root(0){}

  ~BinaryTree(){
    Node<T>* x = root;
    if(x!=NULL)
    {
    destroy_tree(x->left);
    destroy_tree(x->right);
    delete x;
    }
  }

Node<T>* getRoot(){
  return root;
}


//For binary search tree, the inorder tree walk will output the sorted nodes
void inOrder_tree_walk(Node<T>* x){
    if (x != 0)
    {
      inOrder_tree_walk(x->left);
      std::cout<< x->key <<" ";
      inOrder_tree_walk(x->right);
    }
  }



  //non-recursive
Node<T>* tree_search(T k){
    Node<T>* x = root;
    while (x != 0 && k!= x->key){
      if(k < x->key) x = x->left;
      else x = x->right;
    }
    //if the searching node does not exist in the tree, the program will quit
    assert(x != 0);
    return x;
  }

/*
  //recursive search
  Node<T>* tree_search(Node<T>* r, T k){
    if(r==0 || k==r->key) return r;
    if(k < r->key) return tree_search(r->left, k);
    else return tree_search(r->right,k);

  }
*/

//The minimum node in the binary search tree is located at the left most conner
Node<T>* tree_minimum(Node<T>* x){
    while(x->left != 0){
       x = x->left;
     }
    return x;
  }

//The maximum node in the binary search tree is located at the right most conner
Node<T>* tree_maximum(Node<T>* x){
    while(x->right != 0){
      x = x->right;
    }

    return x;
  }

//find the sussessor in the in order tree walk.
Node<T>* tree_successor(Node<T>* x){
  /*if the right child of x is not NULL, successor of x is the left most node in its
    right child tree which is the minimum child.*/
    if(x->right != 0) return tree_minimum(x->right);
  /*if the right child of x is NULL, search dowm to up from x,until meet a node
    which is the left child of its parents. */
    Node<T>* y = x->p;
    while(y != 0 && x ==y->right){
      x = y;
      y = y->p;
    }
    return y;

  }

//search up to down from the root using two pointer x and y. until x equal to NULL.
void tree_insert(T n){
  //y always points to the parents of x
    Node<T>* y = 0;
    Node<T>* x = root;
    //create a node that you want to insert
    Node<T>* z=new Node<T>(n);
    while (x != 0){
      y = x;
      if(z->key < x->key)
      {
        x = x->left;

      }
      else x = x->right;
    }
    //if x equals NULL, insert z into the tree . The NULL position that x points to
    //is the place that we want to insert
    z->p = y;
    //if the tree is empty, set the node to be root
    if(y == 0){
      root = z;
    }
    //deside whether the inserted node is a left child or a right child of its parents
    else if (z->key < y->key){
        y->left = z;}
    else  {y->right = z;}

   }

/*1. if z has no child, change the parents of z, make NULL to be the child of its
  parents and delete z.
  2. if z have just one child, build a link between its parents and its child,and
  then delete z
  3. if z have two children, find the successor of z, then delete the successor
  of z, and replace key field of z to be its successor, actually the deleted node
  is the successor of z
*/
Node<T>* tree_delete(T n){
  Node<T>* z=tree_search(n);
  /*y points to the actually node that you want to delete, it may be the input
  node(if the input node has at most i child)or the successor of the input node
  (if the input node has two children)*/
  Node<T>* y=0;
  Node<T>* x=0;
  if(z->left==0 || z->right==0){
     y = z;}
    else {
      y = tree_successor(z);
    }
  //set x to be the child of y
  if(y->left != 0) x = y->left;
  else x = y->right;
  // change pointer in p[y] and x and delete y
  if(x!= 0) x->p = y->p;
  if (y->p ==0) root = x;
  else if (y == y->p->left) y->p->left = x;
  else y->p->right = x;
  /* if the deleted node is the successor of the input node, copy contents of y
  into z*/
  if (y != z)
  {
    z->key = y->key;

  }

  return y;

}



private:
  Node<T>* root;

};
