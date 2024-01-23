// Section 10
// Challenge -
// Substitution Cipher

/*
A simple and very old method of sending secret messages is the substitution cipher.
You might have used this cipher with your friends when you were a kid.
Basically, each letter of the alphabet gets replaced by another letter of the alphabet.
For example, every 'a' get replaced with an 'X', and every 'b' gets replaced with a 'Z', etc.

Write a program thats ask a user to enter a secret message.

Encrypt this message using the substitution cipher and display the encrypted message.
Then decryped the encrypted message back to the original message.

You may use the 2 strings below for  your subsitition.
For example, to encrypt you can replace the character at position n in alphabet
with the character at position n in key.

To decrypt you can replace the character at position n in key
with the character at position n in alphabet.

Have fun! And make the cipher stronger if you wish!
Currently the cipher only substitutes letters - you could easily add digits, puncuation, whitespace and so
forth. Also, currently the cipher always substitues a lowercase letter with an uppercase letter and vice-versa.
This could also be improved.

Remember, the less code you write the less code you have to test!
Reuse existing functionality in libraries and in the std::string class!
*/

#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int main()
{
    string encrypted_message{};
    string decrypted_message{};
    string alphabet{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789^#!*%)@(&$"};
    string key{"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr^#!*%)@(&$0123456789"};

    size_t choice;
    size_t amount_characters{72};

    /// @brief Menu for encrypting and decrypting message
    /// @return 1 for encrypt, 2 for decrypt, 3 for closing
    do
    {
        cout << endl;
        cout << "Type 1 for encrypting a message, 2 for decrypting, 3 to close program" << endl;
        cin >> choice;
        switch (choice)
        {
        /// @brief gets the user decrypted message
        /// @return outputs the encrypted message
        case 1:

            decrypted_message.clear();
            encrypted_message.clear();

            cout << "" << endl;
            cout << "Write the message to encrypt: " << endl;
            cin.ignore(); //! Cleans buffer
            getline(cin, decrypted_message);
            cout << endl;

            /// @brief for goes through decrypted (user message) and finds each character on alphabet string
            //  and stores its position, if char isn't registered keeps original char.
            /// @return encrypted message for each position will get the key.at(position) char, means the equivalent for the encrypting system

            for (char c : decrypted_message)
            {
                size_t position = alphabet.find(c);
                if (position != string::npos)
                {
                    char new_char{key.at(position)};
                    encrypted_message += new_char;
                }
                else
                {
                    encrypted_message += c;
                }
            }
            cout << "Encrypted message: " << encrypted_message << endl;
            cout << endl;
            break;

        /// @brief gets the user encrypted message
        /// @return outputs the decrypted message
        case 2:
            decrypted_message.clear();
            encrypted_message.clear();
            cout << "" << endl;
            cout << "Write the message to decrypt: " << endl;
            cin.ignore(); //! Cleans buffer
            getline(cin, encrypted_message);
            cout << endl;

            /// @brief for goes through encrypted (user message) and finds each character on key string
            //  and stores its position, if char isn't registered keeps original char. ! inverse of method 1
            /// @return decrypted message for each position will get the alphabet.at(position) char, means the equivalent for the encrypting system
            for (char c : encrypted_message)
            {
                size_t position = key.find(c);
                if (position != string::npos)
                {
                    char new_char{alphabet.at(position)};
                    decrypted_message += new_char;
                }
                else
                {
                    decrypted_message += c;
                }
            }
            cout << "Decrypted message: " << decrypted_message << endl;
            cout << endl;
            break;

        case 3:
            cout << "\tYou choose to quit, have a good day!" << endl;
            break;

        default:
            cout << endl;
            cout << "\tMake sure your choice is either 1, 2 or 3 and try again" << endl;
        }

    } while (choice != 3);

    return 0;
}