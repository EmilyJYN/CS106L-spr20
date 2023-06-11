#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>

using std::pair; using std::string; using std::vector;
using std::cout; using std::endl; using std::cin; using std::cerr;

// Unary Predicate (one arguement)
bool isEqualto3(int val){
    return val == 3;
}

// Binary Pridicate (two arguements)
bool isDivisibleBy(int dividend, int divisor){
    return dividend % divisor == 0;
}


template <typename InputIterator, typename UnaryPredicate> //定义了两个template parameter: InputIterator, UnaryPredicate
int countOccurences(InputIterator begin, InputIterator end, UnaryPredicate predicate){

    int count = 0;
    for(auto iter = begin; iter != end; ++iter){
        if(predicate(*iter)) count++;
    }
    return count;
}

bool isLessThan5(int val){
    return val < 5;
}

int main(){
    vector<int> vec{1,3,5,7,9};
    cout << countOccurences(vec.begin(), vec.end(), isLessThan5) << endl; //isLessThan5不加()，否则报错
    return 0;
}