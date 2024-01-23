/*
# Copy Romeo and Juliet with line numbers

This challenge should be pretty easy.
I have provided the text to Romeo and Juliet in a file named romeoandjuliet.txt

For this challenge you have to make copy of the Romeo and Juliet file and save it to another file.
This new copy should have line numbers at the beginning of each line in the play.
Please format the numbers nicely so everything lines up.

Feel free to extend this challenge in any way you like.
For example, you may want to provide line numbers only for lines that actually have text

Have fun!

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
    std::ifstream reader{"romeoandjuliet.txt"};
    std::ofstream writer{"romeoandjuliet_output.txt"};
    string line{};
    int counter{0};

    if (!reader)
    {
        cerr << "There was an error opening the file" << endl;
        return -1;
    }
    while (getline(reader, line))
    {
        counter++;
        writer << std::setw(7) << std::left << counter << line << endl;
    }

    cout << " done " << endl;

    return 0;
}