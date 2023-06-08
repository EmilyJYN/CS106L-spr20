# include <set>
#include <iostream>

int main(){

    std::set<int> numbers;

    numbers.insert(5);
    numbers.insert(2);
    numbers.insert(7);
    numbers.insert(1);

    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
    //printed 1 2 5 7
}