#ifndef VECTORMYCLASS_H
#define VECTORMYCLASS_H

#include <iterator>


template <typename T>
class vector{
public:
    vector<T>::vector(size_t capacity = 10){
    _capacity = capacity;
    _size = 0;
    _elems = new T[_capacity];
    }

    vector<T>::~vector(){
    delete[] _elems;
    }

    //Access elements(完全没搞懂为什么这么写)
    typename vector<T>::T& vector<T>::at(size_t pos){ //typename后，空格前，是一个type
    return const_cast<typename vector<T>::T&>(
        static_cast<const vector<T>*>(this) -> at(pos)
    );
    }
    T& front();
    T& back();

    const T& at(size_t pos) const;
    const T& front() const;
    const T& back() const;
    
    //iterators
    /*这里不使用真正的iterator而是pointer，因为：
    1. 如果在template的parameter中，比如，加一个T_iterator类型，则在main中每次使用vector类型的时候，
    都要写为，例如，vector<int, int*>格式。也就是说iterator的类型需要用户自定义，容易出错。我们希望这个class能自己推导iterator的类型。
    2. 我们可以定义自己的迭代器类型，但这通常需要定义一个完整的迭代器类。对于简单的vector类型，pointer已经足够满足迭代器的功能了。
    */
    T* begin(); 
    T* end();

    const T* begin() const;
    const T* end() const;

    //operator overloading
    vector<T>& operator+=(const T& other); //return的是整个vector而不是其中的一个element
    vector<T>& operator+=(const vector<T>& other); //可以加一个数（例如上一行代码），也可以加一个vector（例如本行代码）


private:
    size_t _capacity;
    size_t _size;
    T* _elems;
};

#endif