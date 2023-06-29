#include <iostream>
#include <string>
#include <cctype>

int main()
{
    std::string str = "hello";
    std::string result;

    for (char c : str)
    {
        result.push_back(std::toupper(c));
    }

    std::cout << result << std::endl; // Output: HELLO

    return 0;
}
