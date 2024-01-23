/*
# POINTERS TO CONSTANTS
? The data pointed to by the pointers is constant and cannot be changed.
? The pointer itself can change and point somewhere else.

 int high_score {100};
 int low score { 65};
! const int *score_ptr { &high_score };

*score_ptr = 86;    //ERROR, value is constant
score_ptr = &low score; // OK

# CONSTANT POINTERS

? The data pointed to by the pointers can be changed.
? The pointer itself cannot change and point somewhere else

int high_score {100};
int low_score { 65};
! int *const score_ptr { &high_score };

*score_ptr = 86;    // OK
score_ptr = & low-score; //! ERROR, pointer reference cannot change

# CONSTANT POINTERS TO CONSTANTS

? The data pointed to by the pointer is constant and cannot be changed.
? The pointer itself cannot change and point somewhere else.

int high_score {100};
int low score { 65};
! const int *const score_ptr { &high_score };
*score_ptr = 86;    //ERROR
score_ptr = &low_score; // ERROR

*/