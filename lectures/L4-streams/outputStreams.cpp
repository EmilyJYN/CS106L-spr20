#include <iostream>
#include <fstream>

using std::cout;	using std::endl;

int main() {
   int bestNumber = 42;
   cout << "My favorite number is: " << bestNumber << endl;
   
   std::ofstream outputFile("out.txt");
   outputFile << "My favorite number is: " << bestNumber << endl;
   return 0;
}
/*这段代码在第二次运行时，会将新的内容覆盖写入 out.txt 文件，而不是追加到文件的末尾。
这是因为在创建 std::ofstream 对象时，默认情况下文件模式是截断模式（std::ios::trunc），
这意味着在打开文件时会清空文件内容，然后写入新的内容。
如果您希望将新的内容追加到文件的末尾，而不是覆盖原有内容，可以在打开文件时指定追加模式（std::ios::app）
*/