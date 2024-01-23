/* Overload the following operators in the provided Mystring class.

To gain experience overloading operators, you should do this challenge twice.
First, overload the operators using member functions and then in another project overload the same operators
again using non-member functions.

Please do it once using member methods and then again using non-member functions.

Here is a list of some of the operators that you can overload for this class:

-       - unary minus. Returns the lowercase version of the object's string
           -s1
==    - returns true if the two strings are equal
           (s1 == s2)
!=     - returns true if the two strings are not equal
           (s1 != s2)
<      - returns true if the lhs string is lexically less than the rhs string
           (s1 < s2)
>      - returns true if the lhs string is lexically greater than the rhs string
          (s1 > s2)
+       - concatenation. Returns an object that concatenates the lhs and rhs
           s1 + s2
+=    - concatenate the rhs string to the lhs string and store the result in lhs object
          s1 += s2;      equivalent to s1 = s1 + s2;
*        - repeat -  results in a string that is copied n times
          s2 * 3;          ex). s2 = "abc";
                                   s1 = s2 * 3;
                                   s1 will result in "abcabcabc"
*=      - repeat the string on the lhs n times and store the result back in the lhs object
            s1 = "abc";
            s1 *= 4;        s1 = s1 will result in "abcabcabcabc"

If you wish to overlod the ++ and -- operators remember that they have pre and post versions.

The semantics should be as follows (this shows the member method version):

Mystring &operator++()   {  // pre-increment
   // do what ever you want increment do to - maybe make all characters uppercase?
   return *this;
}

// Note that post-increment returns a Mystring by value not by reference

Mystring operator++(int) {   // post-increment
   Mystring temp (*this);       // make a copy
   operator++();                    // call pre-increment - make sure you call pre-increment!
   return temp;                     // return the old value
}


Have fun! Think of some other operators that might be useful!
Don't worry if they all don't make sense -- this is an exercise about learning how
to overload operators.

Hints:
1. take advantage of the std::strcmp function for the equality operators!
2. the += and *= operators should return a Mystring &
3. rather than duplicate code in the += and *= functions, use the + and * operators which you have already overloaded!

*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include "Mystring.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/// @brief
/// @return
int main()
{

   cout << std::boolalpha << endl;

   Mystring a{"frank"};
   Mystring b{"frank"};

   cout << (a == b) << endl; // true
   cout << (a != b) << endl; // false

   cout << endl;
   b = "george";
   cout << (a == b) << endl; // false
   cout << (a != b) << endl; // true
   cout << (a < b) << endl;  // true
   cout << (a > b) << endl;  // false

   cout << endl;
   Mystring s1{"FRANK"};
   s1 = -s1;
   cout << s1 << endl; // frank

   s1 = s1 + "*****";
   cout << s1 << endl; // frank*****

   s1 += "-----"; // frank*****-----
   cout << s1 << endl;

   cout << endl;
   Mystring s2{"12345"};
   s1 = s2 * 3;
   cout << s1 << endl; // 123451234512345

   cout << endl;
   Mystring s3{"abcdef"};
   s3 *= 5;
   cout << s3 << endl; // abcdefabcdefabcdefabcdefabcdef

   cout << endl;
   Mystring s = "Frank";
   ++s;
   cout << s << endl; // FRANK

   s = -s;
   cout << s << endl; // frank

   cout << endl;
   cout << "Pre increment test" << endl;
   Mystring result;
   result = ++s;
   cout << s << endl;      // FRANK
   cout << result << endl; // FRANK

   cout << endl;
   s = "Frank";
   s++;
   cout << s << endl; // FRANK

   cout << endl;
   cout << "Post increment test" << endl;
   s = -s;
   cout << s << endl; // frank
   result = s++;
   cout << s << endl;      // FRANK
   cout << result << endl; // frank

   cout << endl;
   cout << "Input tests" << endl;
   Mystring repeat_string;
   int repeat_times;
   cout << "Enter a string to repeat: " << endl;
   cin >> repeat_string;
   cout << "How many times would you like it repeated? " << endl;
   cin >> repeat_times;
   repeat_string *= repeat_times;
   cout << "The resulting string is: " << repeat_string << endl;

   cout << (repeat_string * 12) << endl;

   cout << endl
        << "Repetition tests: " << endl;
   repeat_string = "RepeatMe";
   cout << (repeat_string + repeat_string + repeat_string) << endl;

   repeat_string += (repeat_string * 3);
   cout << repeat_string << endl;

   repeat_string = "RepeatMe";
   repeat_string += (repeat_string + repeat_string + repeat_string);

   return 0;
}