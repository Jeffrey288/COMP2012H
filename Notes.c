

/**
 * Literal constants: fixed / permanant values that cannot be modified.
 * Symbolic constant: named constant (with an identifier name)
 * 
 * Rationale: improve READABILITY
 */
int i = 23; // 23 is a literal constant
const char BACKSPACE = '\b'; // BACKSPACE is a symbolic constant

/**
 * Variable declaration -> allocates memory
 */
int i;

/**
 * Modulo Arithmetic 
 * 
 * define
 * a = (a/b) * b + a%b
 * a/b: integral part (truncation) of a/b
 * a%b: remainder of integer division a/b
 * 
 * a%b = a - (a/b) * b
 * 
 * (-17)%5 = -2
 * 
 * 17%(-5) = -17/5 = -3
 * 17 = (-3) * (5) + a%b
 * a%b = 2
 * 
 * (-17)/(-5) = 17/5 = 3
 * -17 = 3 * (-5) + a%b
 * a%b = -2
 * 
 */


/**
 * Pre and Post Incrment
 * ++x: increment x in memory, and return the value of x
 * -> returns the reference (lvalue)
 * x++: returns the value of x, then increment x in memory
 * -> returns the value only (rvalue)
 * 
 * ++++++x is well defined
 * x++++++ is not well defined
 * (cuz x++ returns the old value)
 */