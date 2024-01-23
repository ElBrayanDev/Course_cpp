/*  FUNCTIONS

! ABSTRACTION, MODULARIZATION, EASY TO DEBUG, REUSABLE

* Allow the modularization of a program
* Separate code into logical self-contained units
* These units can be reused
_________________________________________________________

# Document the functions
* Write your code to the function specification

Undestand:
* What the function DOES
* What information the function NEEDS
* What the function RETURNS
* Any ERRORS the function may produce
* Any performance CONSTRAINTS

Don't worry about HOW IT WORKS internally
unless you are the one writting it!
#Information hiding

!Must default every parameter if you default one

double function(int param1 = 100.0, double param2 = 0.06, string param3 = "Pedro"); //# PROTOTYPE

double calc_cost(double base_cost, double tax_rate, double shipping) { //# IMPLEMENTATION
    return base_cost += (base_cost * tax_rate) + shipping;
}

*/