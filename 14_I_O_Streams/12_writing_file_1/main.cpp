/*
#Output files (fstream and ofstream)

fstream and ofstream are commonly used for output files

1. #include <fstream>
2. Declare an fstream or ofstream object
3. Connect it to a file on your file system (opens it for writing)
4. Write data to the file via the stream
5. Close the stream

fstream and of stream are commonly used for output files
    - Output files will be created if they don't exist
    - Output files will be overwritten (truncated) by default
    - Can be opened so that new writes append
    - Can be open in text or binary modes

std::ofstream writer {"name.txt", std::ios::out | std::ios::binary};

std::ofstream writer {"name.txt", std::ios::trunc}; //# discards contents

std::ofstream writer {"name.txt", std::ios::app}; //# append content on each write

std::ofstream writer {"name.txt", std::ios::ate}; //# seek to end of stream when opening


*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <cctype>
#include <string>
#include <vector>
#include <cmath>
#include <memory>
#include <fstream>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{
    std::ofstream out_file{"output.txt", std::ios::app};
    if (!out_file)
    {
        std::cerr << "Error creating file" << std::endl;
        return 1;
    }
    std::string line;
    std::cout << "Enter something to write to the file: ";
    std::getline(std::cin, line);
    out_file << line << std::endl;

    out_file.close();

    return 0;
}