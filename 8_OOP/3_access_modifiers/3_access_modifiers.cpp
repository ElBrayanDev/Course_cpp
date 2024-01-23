/* Class Member Access Modifiers

! public: accessible everywhere

* private: accessible only by members or friends of the class (information hiding)

? protected: used in inheritance

*/

#include <iostream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Player
{
private:
    //atributes
    string name;
    int health;
    int xp;

public:
    //methods
    void talk(string text_to_say){cout << name << " says " << text_to_say << endl; }
    bool is_dead;
};

int main()
{
    Player elbrayan;
    // elbrayan.name = "ElBrayan";  //private atributes
    // cout << elbrayan.health << endl; //private atribute
    elbrayan.talk("Hello World");
    return 0;
}
