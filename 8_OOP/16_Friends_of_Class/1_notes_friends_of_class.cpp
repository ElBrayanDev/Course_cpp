/*
    FRIENDS OF A CLASS (operator overloading expands on this)

! GET direct access of private attributes

! Friends have unlimited access to public and private data members, but they are not members of that class

? For classes ussing classes, we shouldn't use setters and getters, we can work directly with the data

@FRIEND
    - A function or class that has access to private class member
    - And, that function of or class is NOT a member of the class it is accessing

@FUNCTION
    - Can be regular non-member functions
    - Can be member methods of another class

@CLASS
    - Another class can have access to private class members

#HOW C++ IMPLEMENTS IT:

@ Friendship MUST BE GRANTED, //!NOT TAKEN
    - Declared explicitly in the class that is granting frienship
    - Declared in the function prototypye with the keyword "friend"

@ Friendship is NOT SYMMETRIC
    ! Must be explicitly granted
    - if A is a friend of B
    ? B is NOT a friend of A

@ Friendship is not TRANSITIVE
    ! Must be explicitly granted
    - If A is a friend of B, AND
    B is a friend of C
    ? then A is NOT a friend of C

*/
