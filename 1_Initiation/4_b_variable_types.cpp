#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main()
{
    /*
    !CHARACTER TYPE
    ******************************************/

    char middle_initial{'Y'}; // *single quotes for single char
    cout << "My middle initial is: " << middle_initial << endl;

    /*
     !INTEGER TYPE
     ******************************************/

    unsigned short int exam_score{55}; // same as unsinged short exam_score{55};
    cout << "My exam score was: " << exam_score << endl;

    int countries_represented{65};
    cout << "There were " << countries_represented << " countries represented in my meeting." << endl;

    long people_in_florida{20'610'000};
    cout << "There are about " << people_in_florida << " people in florida. " << endl;

    long long people_on_earth{7'600'000'000};
    cout << "There are about " << people_on_earth << " people on the earth." << endl;

    long long distance_to_alpha_centauri{9'461'000'000'000};
    cout << "The distance to alpha centauri is: " << distance_to_alpha_centauri << " kilometers" << endl;

    /*
     !FLOATING POINT TYPE
     ******************************************/

    float car_payment{401.23};
    cout << "My car payment is: " << car_payment << endl;

    double pi{3.14159};
    cout << "PI is: " << pi << endl;

    long double large_number{2.7e120};
    cout << large_number << " is a very big number" << endl;

    /*
     !BOOLEAN TYPE
     ******************************************/

    bool game_over{false};
    cout << "The value of game over is: " << game_over << endl;

    /*
     !OVERFLOW EXAMPLE
     ******************************************/

    short value1{30'000};
    short value2{1000};
    /*short*/ int product{value1 * value2}; //* should use int, the number doesn't fit on the var size.

    cout << "The product of " << value1 << " and " << value2 << " is: " << product << endl;

    return 0;
}