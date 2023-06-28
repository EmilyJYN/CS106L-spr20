#include <iostream>

using std::cout; using std::endl;

class Drink{
public:
    //constructors
    Drink() = default;
    Drink(std::string flavor) : _flavor(flavor) {}
    //destructor
    virtual ~Drink() = default;

    //纯虚函数
    virtual void make() = 0;

private:
    std::string _flavor;

};


class Tea : public Drink{
public:
    // constructors
    Tea() = default; //生成系统自动生成的默认构造函数

    //Tea();         //定义了一个构造函数，但是会在后面定义它。如果后面没有定义，则报错。

    Tea(std::string flavor) : Drink(flavor) {} //再声明一个接收参数的constructor，和前面无参数的默认constructor不一样。
                                               //这个构造函数接收了flavor作为参数，并将它用来初始化基类中的带参构造函数
                                               //这里的Drink不是class，而是Drink的带参构造函数！
    //destructor
    ~Tea() = default;
    void make(){
        //statement;
    }

};


int main(){



    return 0;
}