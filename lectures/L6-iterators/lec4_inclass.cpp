#include <iterator>
#include <set>
#include <iostream>

using std::cout; using std::endl;
using std::set;

int main(){

    set<int> container;
    for (int i = 0; i < 10; i++){
        container.insert(i);
    }

    //set<int>::iterator itr = container.begin()
    auto itr = container.begin();
    while (itr != container.end()){
        cout << *itr << " ";
        ++itr;
    }
    cout << endl;

    set<int>::iterator itr2;
    for(itr2 = container.begin(); itr2 != container.end(); ++itr2){
        cout << *itr2 << " ";
    }
    cout << endl;
}