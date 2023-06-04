#include <iostream>
#include <sstream> // getline(), istringstream

using std::string; using std::istringstream;
using std::cout;  using std::cin;  using std::endl;

/*
void badWelcomeProgram();
int getInteger(const string& prompt);

//First attempt
int getInteger(const string& prompt){
    cout << prompt; //print string
    int result;
    cin >> result; //convert to int

    return result; //return int
}
*/

void badWelcomeProgram();
/* Does not work somehow, need extra learning to fix
int getInteger(const string& prompt);

int getInteger(const string& prompt){
    while(true){
        cout << prompt;
        string line;
        if(!getline(cin,line)){
            throw std::domain_error("No input.");
        istringstream iss(line);

        int result; char trash;
        //if true, iss start with an integer and nothing more is appended.
        //if not ture, back to getline()
        if(iss >> result && !(iss >> trash)){
            return result;
        }
        }
    }
}
*/

void badWelcomeProgram(){

    string name, age, response;

    cout << "What is your name? ";
    //cin >> name;
    getline(cin, name); //read until \n

    cout << "What is your age? ";
    cin >> age;
    //getInteger(age);

    cout << "Hello " << name << "(age " << age << ")\n";

    cout << "Do you want to try again? ";
    //cin >> response;
    getline(cin, response);

    cout << "You said: " << response << endl;
}

int main(){

    badWelcomeProgram();

    return 0;
}


/*
int main(){

    istringstream iss("16.9\n 24");
    double val;
    string line;
    iss >> val; // val = 16.9
    iss.ignore(); //ignores one char, which is "\n"
    getline(cin,line); // line = "". With iss.ignore, line = " 24" 
    getline(cin,line); // line = " 24" 

}
*/
