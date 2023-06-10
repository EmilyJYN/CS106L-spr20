#include <utility>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <ctime>

using std::pair; using std::string; using std::vector;
using std::cout; using std::endl; using std::cin; using std::cerr;

/* Have to write a new function for each type
pair<int,int> my_minmax(int a, int b){
    if (a<b) return {a,b};
    else return {b,a};
}

pair<double,double> my_minmax(double a, double b){
    if (a<b) return {a,b};
    else return {b,a};
}

pair<string,string> my_minmax(string a, string b){
    if (a<b) return {a,b};
    else return {b,a};
}
*/
/*
//specify the following function to be a template
template <typename T, typename U> //when inputs are in different types
pair<T,T> my_minmax(T a, U b){
    if (a<b) return {a,b};
    else return {b,a};
}*/

template <typename T> //specify the following function to be a template
pair<T,T> my_minmax(T a, T b){
    if (a<b) return {a,b};
    else return {b,a};
}

template <typename T>
void printMinAndMax(T min, T max){
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << endl;
}
/*
void minmaxTestBasic(){

    auto [min1,max1] = my_minmax(4.2,-7.9);
    printMinAndMax(min1,max1);
    auto [min2,max2] = my_minmax("Avery","Anna");
    printMinAndMax(min2,max2);
    auto [min3,max3] = my_minmax(3,3);
    printMinAndMax(min3,max3);

}*/

void minmaxTestExplicit(){

    auto [min0,max0] = my_minmax<double>(4.2,-7.9);
    printMinAndMax(min0,max0);
    auto [min1,max1] = my_minmax<char>('l','b');
    printMinAndMax(min1,max1); 
    auto [min2,max2] = my_minmax<string>("Avery","Anna");
    printMinAndMax(min2,max2);
    auto [min3,max3] = my_minmax<int>(3,3);
    printMinAndMax(min3,max3);
    //auto [min4,max4] = my_minmax<vector<int>>({1,2},{3,1}); //this does not compile, STL vector does not have operator <<
    //printMinAndMax(min4,max4);
}

template <typename T>
T getTypeValue(const string& prompt = "Enter a ",
               const string& reprompt = "Illegal format. Try again.") {
    while (true) { //while nothing is returned
        cout << prompt << typeid(T).name() << ": ";
        string line;
        if (!getline(cin, line)) { //getline(), if failed, error message
            throw std::domain_error("getLine: End of input reached while waiting for line.");
        }
        std::istringstream iss(line); //convert line to an input string stream
        T value; char extra;
        //if true, iss start with an integer and nothing more is appended, return value and break the while loop.
        if (iss >> value && !(iss >> extra)) return value;
        //if not ture, prompt error message, and go back to top, prompt again
        cerr << reprompt << endl;
    }
}

void getTypeTest(){
    int val0 = getTypeValue<int>();
    int val1 = getTypeValue<int>();
    double val2 = getTypeValue<double>();
    cout << "int is: " << val1 << endl;
    cout << "double is: " << val2 << endl;
}

int main(){
    getTypeTest();
    return 0;
}