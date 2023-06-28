#include <iterator>
#include <set>
#include <vector>
#include <deque>
#include <string>
#include <algorithm>
#include <iostream>

using std::set; using std::string; using std::vector;

template <typename Iter>
size_t my_distance(Iter first, Iter last){

    using category = typename std::iterator_traits<Iter>::iterator_category; //用typename, 因为这里的Iter是模板参数，只有在编译后才会实例化

    if constexpr(std::is_same<category, std::random_access_iterator_tag>::value){ //use constexpr to perform at compile time
        return last - first;
    }else{
        size_t result = 0;
        while(first != last){
            ++first;
            ++result;
        }
        return result;
    }
}

int main(){

    vector<string> names {"Anna", "Ethan", "Nikhil", "Avery"};

    auto anna_iter = std::find(names.begin(), names.end(), "Anna");
    auto avery_iter = std::find(names.begin(), names.end(), "Avery");

    std::cout << my_distance(anna_iter, avery_iter) << std::endl;
    return 0;
}