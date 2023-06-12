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
int countOccurences(InputIterator begin, InputIterator end, UnaryPredicate predicate){ //这里pass的function是这个function的pointer

    int count = 0;
    for(auto iter = begin; iter != end; ++iter){
        if(predicate(*iter)) count++; //pass one of the element of the container into the predicate function
    }
    return count;
}
/*
bool isLessThan5(int val){
    return val < 5;
}*/

int main(){
    vector<int> vec{1,3,5,7,9};
    
    int limit = 5;
    //atuo val, 这里起的作用类似于一个template，使这个lambda函数可以输入很多种type的变量
    auto isLessThanLimit = [limit](auto val) -> bool{ 
        return val < limit;
    };

    //cout << "Occurence of # less than 5: ";
    //cout << countOccurences(vec.begin(), vec.end(), isLessThan5) << endl; //isLessThan5不加()，否则报错
    cout << "Occurence of # less than 5: ";
    cout << countOccurences(vec.begin(), vec.end(), isLessThanLimit) << endl;
    cout << "Occurence of # less than 5 in second half: ";
    cout << countOccurences(vec.begin()+vec.size()/2, vec.end(), isLessThanLimit) << endl; 

    return 0;
}