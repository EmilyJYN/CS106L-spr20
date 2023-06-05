#include <iostream>
#include <fstream>
#include <sstream>

using std::string; using std::istringstream; using std::ifstream;
using std::cout;  using std::cin;  using std::endl; using std::cerr;

string prompUserFile(ifstream& stream, 
                     string prompt ="Please enter a file name: ", 
                     string reprompt = "Invalid file name, please re-enter a file name. ");

/* Write the following function which 
prompts the user for a filename, opens the ifstream to the file,
reprompt if the filename is not valid and then return the filename.*/
string prompUserFile(ifstream& stream, string prompt, string reprompt){
    while(true){
        cout << prompt;
        string filename;
        if(!getline(cin,filename)){
            throw std::domain_error("getline: End of input reached while waiting for line.");
        }

        if(!filename.empty()){ //if the entered filename is not empty
            stream.clear(); //clearing the possible error flags from the past
            stream.open(filename); //open file
            if (stream) return filename; // if stream's fail bit is not on
        }
        cerr << reprompt << endl;
    }
    
}


int main(){

    ifstream inputFile;
    string filename = prompUserFile(inputFile);
    
    cout << "Selected filename: " << filename << endl;
    
    // 在这里可以使用 inputFile 进行文件读取操作

    return 0;
}