#include <utility>
#include <string>
using std::string;

int main(){

    std::pair<string, int> phone1 ("Stanford", 6507232300); 
	//uniform initialization
    std::pair<string,int> phone2{"Stanford", 6507232300};
    //make_pair automatically deduces the type, great place to use auto!
    auto phone3 = std::make_pair("Stanford", 6507232300); 

    string name; int num;
	name = phone2.first; //Stanford
	num = phone2.second; //6507232300
    return 0;
}