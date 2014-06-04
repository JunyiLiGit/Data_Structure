/* self-balancing binary search tree.
propertities of red black tree:
1. Every node is either red or black.
2. The root is black.
3. Every leaf ( NIL ) is black.
4. If a node is red, then both its children are black.
5. For each node, all simple paths from the node to descendant leaves contain the
same number of black nodes.
Every node has five fields, color, parents, key, left, right
As a matter of convenience in dealing with boundary conditions in red-black
tree code, we use a single sentinel to represent NIL
bh(x): from one node to a leaf(not including the node itself),
the number of black nodes. Assuming h is the height of a red black tree,
bh(x) of the tree equals h/2. h<=2lg(n+1), so bh(x)<= lg(n+1).
So time complaxity for search, minimum, maximun,successor and predecessor are
all O(lgn)= O(h).
*/

/*There is no such rule like red black can only be used in a particular case
it depends upon the application in cases like when You have to build the tree
only once and you have to query it many times then you can go for a AVL tree
because in AVL tree searching is quite fast.. But it is strictly balanced so
insertion and deletion may take some time AVl tree may be used for language
dictionery where You have to build the data structure just once and the red
black tree is used in the Completely Fair Scheduler used in current Linux
kernels now a days..
For example they are used in implementing the following:
Java: java.util.TreeMap , java.util.TreeSet .
C++ STL: map, multimap, multiset.
Linux kernel: completely fair scheduler, linux/rbtree.h

*/

// black = 0; red = 1;
#include <assert.h>
template <typename T>
struct Node{
  T key;
  int color;
  Node<T>* p;
  Node<T>* left;
  Node<T>* right;
  Node(const T& data=T(), int c=0, Node* p=0, Node* l=0, Node* r=0):
  key(data),
  color(c),
  p(p),
  left(l),
  right(r){}
};

template <typename T>
class RedBlackTree{
public:
  RedBlackTree():root(0){
    nil= new Node<T>();
    nil->p = nil->left = nil->right = nil;
    root = nil;
  }

  ~RedBlackTree(){
  Node<T>* x = root;
  if(x!=nil)
  {
  destroy_tree(x->left);
  destroy_tree(x->right);
  delete x;
  }

}

  Node<T>* getRoot(){
    return root;
  }


  void rb_insert(T n){
    Node<T>* z = new Node<T>(n);
    //z->color = 1;
    Node<T>* y = nil;
    Node<T>* x = root;
    while(x != nil){
      y = x;
      if (z->key < x->key){
        x = x->left;
        }
        else x = x->right;
      }
    z->p = y;
    if (y == nil){
      root = z;
    }
    else if (z->key < y->key){
      y->left = z;
    }
    else y ->right = z;
    z->left = nil;
    z->right = nil;
    z->color = 1;
    //printNode(z);
    rb_insert_fixup(z);
  }

void rb_insert_fixup(Node<T>* z){

  while (z->p->color == 1){
//if z->p is a left child;
    if(z->p == z->p->p->left){

      Node<T>* y = z->p->p->right;
      //case 1 if z->uncle = red
      if(y->color == 1){
      z->p->color = 0;
      y->color = 0;
      z->p->p->color = 1;
      z = z->p->p;
    }
    else {
      //case 2 if z->uncle = black, z is a right child
     if(z == z->p->right){
      z = z->p;
      //make z to be the left child
      left_rotate(z);
    }
    //case 3 if z->uncle = black, z is a left child
      z->p->color = 0;
      z->p->p->color= 1;
      right_rotate(z->p->p);
    }
  }

  //if z->p is a right child;
    else {
    Node<T>* y = z->p->p->left;
    //case 1
      if(y->color == 1){
      z->p->color = 0;
      y->color = 0;
      z->p->p ->color = 1;
      z = z->p->p;
    }
    else
     {  //case 2
       if(z == z->p->left){
        z = z->p;
        right_rotate(z->p);
     }
    // case 3
    z->p->color = 0;
    z->p->p->color= 1;
    left_rotate(z->p->p);}


  }

  assert(root != nil);

  }
  root->color = 0;

}

void left_rotate(Node<T>* x){
  Node<T>* y = x->right;
  x->right = y->left;
  if(y->left != nil){
    y->left->p = x;
  }
  y->p = x->p;
  if (x->p == nil){
    root = y;
  }
  else if(x == x->p->left){
    x->p->left = y;
  }
  else x->p->right = y;
  y->left = x;
  x->p = y;
}

void right_rotate(Node<T>* x){
  Node<T>* y = x->left;
  x->left = y->right;
  if(y->right != nil){
    y->right->p = x;
  }
  y->p = x->p;
  if(x->p == nil){
    root = y;
  }
  else if(x == x->p->left){
    x->p->left = y;
  }
  else x->p->right = y;
  y->right = x;
  x->p = y;
}


void inOrder_tree_walk(Node<T>* x){
    if (x != nil)
    {
      inOrder_tree_walk(x->left);
      printNode(x);
      //std::cout<< x->key <<" ";

      inOrder_tree_walk(x->right);
    }
  }

void printNode(Node<T>* n) {
  std::cout<<" key "<<n->key;
  if (n->p != nil)
    std::cout<<" parent "<<n->p->key;
  else
    std::cout<<" parent nil ";

  if (n->left != nil)
    std::cout<<" left "<<n->left->key;
  else
    std::cout<<" left nil ";
  if (n->right != nil)
    std::cout<<" right "<<n->right->key;
  else
    std::cout<<" right nil ";
  std::cout<<" color "<<n->color;
  std::cout<<std::endl;

}

private:
  Node<T>* nil;
  Node<T>* root;
};
