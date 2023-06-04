#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

using std::cout; using std::cin;
using std::endl; using std::string;
using std::ostringstream; using std::istringstream;

/*
int main(){
    std::string str = "Hello World!"; //can be written as 'string str = "Hello World!";' with the declaration on top
    str[1] = 'i';
    std::cout << str << std::endl; // can be written as 'cout << str << endl;' with the declaration on top

    return 0;
}
*/
/*
int main(){

    //std::ostringstream oss("Ito-En Green Tea"); 
    ostringstream oss("Ito-En Green Tea", ostringstream::ate);  // new oss write at the end of this string, rather than overwrite this one
    cout << oss.str() << endl; //oss is a string stram, not a string. Convert to string first

    //oss << "16.9 Ounces"; 
    oss << 16.9 << " Ounces "; 
    cout << oss.str() << endl;

    return 0;
}
*/
/*
int main(){

    istringstream iss("16.9 Ounces");
    double amount;
    //int amount;
    string unit;

    // iss start at beginning, move until find a whitespace(or any invalid character for the type)(see example below)
    // it grab the characters been through, return the type you want
    iss >> amount; 
    iss >> unit; //Extracting again will skip over any whitespace

    // returns "8 .9" when amount is int, returns "8.45 Ounces" when amount is double
    cout << amount/2 << " " << unit << endl; 

    return 0;
}
*/


int stringToInteger(const string& s);
void stringToIntegerTest();
void printStateBits(const std::istream& iss);

int stringToInteger(const string& s) {

    istringstream iss(s);
    //printStateBits(iss);

    int res;
    iss >> res; //this line doesn't do anything if it cann't read an int
    //printStateBits(iss);
    if (iss.fail()) throw std::domain_error("no value int at beginning!");
    char remain;
    iss >> remain;
    if (!iss.fail()) throw std::domain_error("more than one valid int!");

    return res; //if input is not int, the output is a random junk
}

void stringToIntegerTest(){
    while(true){
        cout << "Type in an integer:";
        string s;
        if(!getline(cin,s)) throw std::domain_error("getline failed");
        cout << "You typed in: " << s << "\n";
        int result = stringToInteger(s);
        cout << "As an integer, this is: " << result << "\n";
        cout << "Half of that is: " << result/2 << "\n";
    }
}

int main(){
    stringToIntegerTest();

    return 0;
}


/*
Quick Syntax lesson:
The following are equivalent:
[boolean] ? [statement1] : [statement2]

if (boolean){
    statement1
} else {
    statement2
}
*/


void printStateBits(const std::istream& iss){

    cout << "State bits: ";
    cout << (iss.good() ? "G" : "-");
    cout << (iss.fail() ? "F" : "-");
    cout << (iss.eof() ? "E" : "-");
    cout << (iss.bad() ? "B" : "-");
    cout << "\n";
    // automatically flushed, why?

}