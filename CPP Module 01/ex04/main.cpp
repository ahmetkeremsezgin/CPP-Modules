#include <iostream>
#include <fstream>

int usage(int argc)
{
    if (argc != 4)
    {
        std::cout << "Usage: <filename> 's1' 's2'" << std::endl;
        return (1);
    }
    return (0);
}

std::string searchAndReplace(std::string line, const std::string &compare, const std::string &change)
{
    size_t pos = 0;
    while ((pos = line.find(compare, pos)) != std::string::npos)
    {
        line.erase(pos, compare.length());
        line.insert(pos, change);
        pos += change.length();
    }
    return line;
}

int main(int argc, char **argv)
{
    if (usage(argc))
        return (1);

    std::ifstream read(argv[1]);
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    if (s1.empty())
    {
        std::cerr << "Error: s1 cannot be empty." << std::endl;
        return (1);
    }

    if (!read.is_open())
    {
        std::cerr << "Error: cannot open input file." << std::endl;
        return (1);
    }

    std::string filename = argv[1];

    std::ofstream write((filename + ".replace").c_str());
    if (!write.is_open())
    {
        std::cerr << "Error: cannot create output file." << std::endl;
        return (1);
    }    
    std::string line;
    while (std::getline(read, line))
    {
        line = searchAndReplace(line, s1, s2);
        write << line << "\n";
    }

    write.close();
    read.close();
    return (0);
}
