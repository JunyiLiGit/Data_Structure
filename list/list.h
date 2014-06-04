#include <iostream>

//This is a Node template, you have to define the Node before you can use
template <typename T>
struct Node{
	T key;
	Node<T>* prev;
	Node<T>* next;
	Node(const T& data=T(), Node<T>* p=0, Node<T>* n=0):
	key(data),
	prev(p),
	next(n){}

};

//template list
template <typename T>
class List {
public:
	List(){
  head = 0;
	tail = 0;
  }

	~List(){

		Node<T>* x = head;
		while(x != 0){

      Node<T>* y = x->next;
			delete x;
			x = y;

		}

	}




//search function will search a certain element in the list,
//and return the pointer that point to the element
	Node<T>* search(const T k){
    Node<T>* x = head;
    while (x != 0 && x->key != k){

      x = x->next;
    }

    return x;


  }

//insert an element in the list, insert the element at the beginging of the list
//(behind the head),like push_front
	void push_front(T n){
		Node<T>* x=new Node<T>(n);
    x->next = head;
    if(head != 0){
      head->prev = x;
    }
    head = x;
    x->prev = 0;

  }

	void push_back(T n){
		Node<T>* x=new Node<T>(n);
		x->prev = tail;
	  if( tail!= 0){
    tail->next = x;
		}
		else head =x;
	  tail = x;
		x->next = 0;

	}

//delete the element that the pointer x point to, first you have to use
//search function to find the pointer and pass the pointer to the delete function
	void del(Node<T>* x){
		if(x->prev != 0){

			x->prev->next = x->next;
		}
		else head = x->next;
		if(x->next != 0){
			x->next->prev = x->prev;
		}

		delete x;


	}

//print the element in the list
	void print(){

		Node<T>* x = head;
		while(x != 0){

			std::cout<< x->key<<" ";
			x = x->next;

		}

		std::cout << std::endl;


	}



private:

//if you implement insert like push_front, you need member head,
//push_back you need member tail.
Node<T>* head;
Node<T>* tail;

};
