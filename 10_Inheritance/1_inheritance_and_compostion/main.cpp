/*
# INHERITANCE

What is it and why is it used?
• Provides a method for creating new classes from existing classes
• The new class contains the data and behaviors of the existing class
• Allow for reuse of existing classes
• Allows us to focus on the common attributes among a set of classes
• Allows new classes to modify behaviors of existing classes to make it unique
    - Without actually modifying the original class

# Terminology

• Inheritance
   • Process of creating new classes from existing classes
   • Reuse mechanism

• Single Inheritance
    • A new class is created from another 'single' class

• Multiple Inheritance
   • A new class is created from two (or more) other classes

!• Base class (parent class, super class)
       • The class being extended or inherited from

!• Derived class (child class, sub class)
           • The class being created from the Base class
           • Will inherit attributes and operations from Base class


! INHERITANCE
#"Is-A" relationship
• Employee 'is-a' Person
• Checking Account 'is-a' Account
• Circle "is-a" Shape

   • Public inheritance
   • Derived classes are sub-types of their Base classes
   • Can use a derived class object wherever we use a base class object

• Generalization
   • Combining similar classes into a single, more general class based on common attributes

• Specialization
   • Creating new classes from existing classes proving more specialized attributes or operations

• Inheritance or Class Hierarchies
    • Organization of our inheritance relationships

! COMPOSITION
# "has-a" relationship
• Person "has a" Account
• Player "has-a" Special Attack
• Circle "has-a" Location


*/

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <cmath>
#include <cctype>
#include "Account.h"
#include "Saving_Account.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main()
{

   // Use the Account class
   cout << "\n=== Account ==================================" << endl;
   Account acc{};
   acc.deposit(2000.0);
   acc.withdraw(500.0);

   cout << endl;

   Account *p_acc{nullptr};
   p_acc = new Account();
   p_acc->deposit(1000.0);
   p_acc->withdraw(500.0);
   delete p_acc;

   // Use the Savings Account class

   cout << "\n=== Savings Account ==========================" << endl;
   Savings_Account sav_acc{};
   sav_acc.deposit(2000.0);
   sav_acc.withdraw(500.0);

   cout << endl;

   Savings_Account *p_sav_acc{nullptr};
   p_sav_acc = new Savings_Account();
   p_sav_acc->deposit(1000.0);
   p_sav_acc->withdraw(500.0);
   delete p_sav_acc;

   cout << "\n==============================================" << endl;
   return 0;
}