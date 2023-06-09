//Example from ppt of CS106L spring 2023 Lecture 3 Slides
#include <vector>
#include <iostream>

using std::vector;
using std::cout; using std::endl;

/*
//p57 references
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
*/

/*
// p52 references
int main(){

    vector<int> original{1, 2};
    vector<int> copy = original;
    vector<int>& ref = original;
    original.push_back(3);
    copy.push_back(4);
    ref.push_back(5);
    
    //cout << original << endl; // {1, 2, 3, 5}
    cout << "original: ";
    for (auto i: original) {
    cout << i << ' '; // will print: "a b c"
    }
    cout << endl;
    
    //cout << copy << endl; // {1, 2, 4}
    cout << "copy: ";
    for (auto i: copy) {
    cout << i << ' '; // will print: "a b c"
    }
    cout << endl;
    
    //cout << ref << endl; // {1, 2, 3, 5}
    cout << "ref: ";
    for (auto i: ref) {
    cout << i << ' '; // will print: "a b c"
    }
    cout << endl;
}
*/


// value reference pointer const
//auto关键字不保留等号右边的reference（&）属性
//当类型为 ref 或 pointer 时，auto 的推导结果将保留表达式的 const 属性, 否则不保留。（copy3，copy4）
//auto可以推导出pointer，也可以直接定义auto*（等号右边为内存地址时）（p1，p2）
int main(){

    vector<int> vec{1, 2, 3};
    const vector<int> c_vec{7, 8};

    const vector<int>& c_ref = vec; //c_ref = const ref to vector, 不能通过它来修改所引用的向量的内容
    auto copy1 = c_ref; // copy1 = vector, c_ref = const ref to vector
    const auto copy2 = c_ref; // copy2 = const vector, c_ref = const ref to vector
    auto& copy3 = c_ref; //copy3 = const ref to vector, 
    auto* copy4 = &c_ref; //copy4 = const pointer to vector

    vector<int>& ref = vec; // ref = ref to vector
    auto& a_ref = ref; // a_ref = ref to (ref to vec)= ref to vec, a_ref 和 ref 完全等价
    const auto& c_aref = ref; // c_aref = const ref to (ref to vec) = const ref to vec

    int  x = 0;
    auto* p1 = &x; //这里定义的是p1，p1 = 指针 = int* = 内存地址 = &x 。对p1进行解引用，*p1 = x = int。 
    auto p2 = &x; //p2 = &x = 内存地址 = 指针  = int*
    auto p3 = *p1; //对p1解引用，获得x
    //auto p4 = *x; //不对，解引用符（*）只能用在pointer上，而x是int
    //auto *p5 = x; //不对，因为*p5（指针）需要存储一个内存地址，而 x 是int
    auto& p6 = p1; //p6 = int*&，是pointer p1的reference
    auto* p7 = &p6; //p7 = int**，因为auto不保留reference

    return 0;
}
