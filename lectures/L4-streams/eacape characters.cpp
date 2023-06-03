#include <iostream>

int main() {
    std::cout << "Hello, World!\r";   // 输出 "Hello, World!"，但光标回到行的起始位置
    std::cout << "This is a new line.\n";  // 输出 "This is a new line."，并移动到下一行的起始位置
    std::cout << "Overwriting...\rGoodbye!\n";  // 输出 "Goodbye!ing..."，覆盖之前的内容，并移动到下一行的起始位置
    return 0;
}