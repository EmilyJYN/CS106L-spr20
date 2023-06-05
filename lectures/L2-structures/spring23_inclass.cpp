//Example from ppt of CS106L spring 2023 Lecture 3 Slides p57
#include <vector>
#include <iostream>

using std::vector;
using std::cout; using std::endl;

void shift(vector<std::pair<int, int>>& nums);

void shift(vector<std::pair<int, int>>& nums) {
    for (size_t i = 0; i < nums.size(); ++i) {
        auto [num1, num2] = nums[i]; // only shifting [num1,num2], not nums[i]
        //auto& [num1, num2] = nums[i]; //shifting both [num1,num2] and nums[i]
        num1++;
        num2++;
        cout << "[num1,num2] is: [" << num1 << "," << num2 << "]" << endl;
        cout << "nums[i] is: [" << nums[i].first << "," << nums[i].second << "]" << endl;
    }
}

int main(){

    vector<std::pair<int,int>> a = {{5,10}, {1,1}}; //vector

    shift(a);

    return 0;
}