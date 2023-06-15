#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> v = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    std::nth_element(v.begin(), v.begin() + v.size()/2, v.end());

    std::cout << "The median is " << v[v.size()/2] << '\n';

    for(auto elem : v){
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}