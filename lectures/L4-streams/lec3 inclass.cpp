#include <iostream>
#include <sstream> // getline(), istringstream

using std::string; using std::istringstream;
using std::cout;  using std::cin;  using std::endl; using std::cerr;

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
int getInteger(const string& prompt = "Enter an integer: ",
               const string& reprompt = "Illegal numeric format. Try again.");

// why not using cin here?
// because when using cin, if something more than expected is typed in, ex. 12 13
// it will store the whole line, while only use the first token (12)
// when we use cin the next time, it will directly extract the leftover (13) rather than the actual input
// In my opinion, just don't use cin for future convenience
int getInteger(const string& prompt = "Enter an integer: ",
               const string& reprompt = "Illegal numeric format. Try again.") {
    while (true) { //while nothing is returned
        cout << prompt; //print "What is your age? "
        string line;
        if (!getline(cin, line)) { //getline(), if failed, error message
            throw std::domain_error("getLine: End of input reached while waiting for line.");
        }
        istringstream iss(line); //convert line to an input string stream
        int value; char extra;
        //if true, iss start with an integer and nothing more is appended, return value and break the while loop.
        if (iss >> value && !(iss >> extra)) return value;
        //if not ture, prompt error message, and go back to top, print "What is your age? " again
        cerr << reprompt << endl;
    }
}

void badWelcomeProgram(){

    string name, response;
    int age;

    cout << "What is your name? ";
    //cin >> name;
    getline(cin, name); //read until \n

    //cout << "What is your age? ";
    //cin >> age;
    age = getInteger("What is your age? ");

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
