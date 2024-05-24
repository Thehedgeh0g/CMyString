#include <iostream>
#include "Class/CMyString.h"

int main()
{
    const CMyString string1 = "Hello";
    CMyStringIterator it = string1.begin();
    //*it = 'a';
    char res1 = *it;
    it+2;
    char res2 = *it;
    it-2;
    char res3 = *it;
    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
    std::cout << res3 << std::endl;
}
