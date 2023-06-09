#include <vector>
#include <set>
#include <iostream>
#include <algorithm>

using std::vector; using std::set;
using std::cout; using std::endl;

const int ELEM_TO_FIND = 9; //global constant

// vector不像int/bool这些小型type，一般使用reference，详见pass by value和pass by reference的区别
//这里我们不需要改动vector的内容，用const
void printVec(const vector<int>& vec){ 
    for (auto elem : vec){
        cout << elem << " ";
    }
    cout << endl;
}

int main(){

    vector<int> vec {3,1,4,1,5,9,2,6};
    cout << "Original Vector: " << endl;
    printVec(vec);
    std::sort(vec.begin(), vec.begin() + 4);
    cout << "Updated Vector: " << endl;
    printVec(vec);

    set<int> elems {3,1,4,1,5,9,2,6};
    cout << "Set size: " << elems.size() << endl;

    auto testit = std::find(elems.begin(),elems.end(),ELEM_TO_FIND);
    if(testit == elems.end()){
        cout << "Not found! " << endl;
    }else{
        cout << "Found number: " << *testit << endl;
    }

    set<int>::iterator lower = elems.lower_bound(4); //返回指向大于等于4的iterator，这里为4
    set<int>::iterator upper = elems.upper_bound(6); //返回指向大于6的iterator，这里为9
    cout << "start: " << *lower << ", end: " << *upper << endl;

    for(; lower != upper; ++lower){ //initialization already finished
        cout << *lower << " ";
    }
    cout << endl;

    return 0;
}