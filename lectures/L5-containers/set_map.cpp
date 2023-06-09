# include <set>
#include <map>
#include <string>
#include <iostream>

/*
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
}*/

int main(){
    std::map<int,std::string> studs;
    studs.insert({1,"Alice"});
    studs.insert({3,"Charlie"});
    studs.insert({2,"Bob"}); //map is ordered by keys

    auto iter = studs.begin();
    while (iter != studs.end()){
        std::cout << (*iter).first << (*iter).second << " "; //括号一定要加
        ++iter;
    }
    //printed 1Alice 2Bob 3Charlie 
    return 0;
}