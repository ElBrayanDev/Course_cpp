#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main()
{
    vector<int> vector1;
    vector<int> vector2;

    vector1.push_back(10);
    vector1.push_back(20);

    cout << "\n";
    cout << vector1.at(0) << " - " << vector1.at(1);
    cout << " Size of vector1 is: " << vector1.size() << endl;

    vector2.push_back(100);
    vector2.push_back(200);

    cout << vector2.at(0) << " - " << vector2.at(1);
    cout << " Size of vector2 is: " << vector2.size() << endl;

    vector<vector<int>> vector_2d;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "\nVector 2d" << endl;
    cout << vector_2d.at(0).at(0) << " - " << vector_2d.at(0).at(1) << " - " << vector_2d.at(1).at(0) << " - " << vector_2d.at(1).at(1) << endl;

    cout << "\n";
    vector1.at(0) = 1000;

    // vector_2d = 0;

    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "Vector 2d modified: " << endl;
    cout << vector_2d.at(2).at(0) << " - " << vector_2d.at(2).at(1) << " - " << vector_2d.at(3).at(0) << " - " << vector_2d.at(3).at(1) << endl;

    cout << "\nVector 1 modified: " << endl;
    cout << vector1.at(0) << " - " << vector1.at(1);

    return 0;
}