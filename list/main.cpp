#include "list.h"

int main(){
List<int> mylist;
for(int i=0; i<10; ++i){
mylist.push_front(i);

}
mylist.print();

mylist.del(mylist.search(5));

mylist.print();

return 0;
}
