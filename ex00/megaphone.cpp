#include <iostream>
#include <string>
#include <cctype>

std::string toupper_string(const std::string& str)
{
    std::string result;
    for (size_t i = 0; i < str.length(); ++i)
    {
        result += std::toupper(str[i]);
    }
    return result;
}

int main(int argc, char** argv)
{
    std::string megaphone, word;
    if (argc < 2)
    {
        megaphone = "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    }
    else
    {
        for (int i = 1; i < argc; ++i)
        {
            word = argv[i];
            megaphone += toupper_string(word);
        }
    }

    std::cout << megaphone << std::endl;

    return 0;
}
