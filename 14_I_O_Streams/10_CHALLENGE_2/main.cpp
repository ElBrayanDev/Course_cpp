/*
# Automated Grader

Write a program that reads a file named 'responses.txt" that contains the answer key for a quiz
as well as student responses for the quiz.

The answer key is the first item in the file.
Student1 name
Student1 responses
Student2 name
Student2 responses
. . .

Here is a sample file.

ABCDE
Frank
ABCDE
Larry
ABCAC
Moe
BBCDE
Curly
BBAAE
Michael
BBCDE

You should read the file and display:
Each student's name and score (#correct out of 5)
At the end, the class average should be displayed
You may assume that the data in the file is properly formatted

Program should output to the console the following:
Student                Score
----------------------------
Frank                    5
Larry                    3
Moe                      4
Curly                    2
Michael                  4
---------------------------
Average score            3.6
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
    std::ifstream reader;
    string correct_answers{};
    vector<string> names{};
    vector<string> answers{};
    vector<int> scores{};
    string name{};
    string answer{};

    reader.open("responses.txt");
    if (!reader)
    {
        cerr << "Wasn't able to open file 'responses.txt'" << endl;
        return -1;
    }

    cout << endl
         << std::setw(23) << std::left << "Student" << std::setw(7) << std::right << "Score" << endl;
    cout << std::setfill('-') << std::setw(30) << "" << endl;
    cout << std::setfill(' ');

    reader >> correct_answers;

    while (reader >> name >> answer)
    {
        names.push_back(name);
        answers.push_back(answer);

        int grade{0};
        for (size_t i{0}; i < correct_answers.size(); i++)
        {
            if (correct_answers.at(i) == answer.at(i))
            {
                grade++;
            }
        }
        scores.push_back(grade);
        grade = 0;
    }

    int sum{};

    for (size_t i{0}; i < names.size(); i++)
    {
        cout << std::setw(23) << std::left << names.at(i)
             << std::setw(5) << std::right << scores.at(i) << endl;

        sum += scores.at(i);
    }

    cout << std::setfill('-') << std::setw(30) << "" << endl;
    cout << std::setfill(' ');

    cout << std::setw(23) << std::left << "Average score"
         << std::setw(6) << std::right << ((double)sum / scores.size()) << endl;

    reader.close();
    return 0;
}