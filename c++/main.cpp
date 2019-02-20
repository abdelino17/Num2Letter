#include <iostream>
#include "Num2Letter.h"

string trim(const string& str)
{
    size_t first = str.find_first_not_of(' ');
    if (string::npos == first)
    {
        return str;
    }
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last - first + 1));
}

int main() {

    std::cout << trim(Num2Letter::enter("1200350450")) << std::endl;
    return 0;
}

