/*
 * This is the external interface of the double_stack library. Note
 * that the stack itself is intentionally not externally visible.
 */
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
 #include <math.h>

 struct DoubleStack {
     struct DoubleStack *next_p;
     double d;
 };
 
extern int  doubleStack_pop(double *d_p);
// pops a double value off the stack -- returns 0 or 1 for success or failure

extern void doubleStack_push(double d);
// pushes a double value on the stack

extern void doubleStack_print(void);
// prints the stack on stdout, but does not alter it

extern int opACos(void);
// replace the top double on the stack with its arc cosine return status

extern int opAdd(void);
// replace the top two doubles on the stack with their sum, return status

extern int opASin(void);
// replace the top double on the stack with its arc sine return status

extern int opATan(void);
// replace the top double on the stack with its arc tangent return status

extern int opClr(void);
// clear the stack, return status (always successful)

extern int opCos(void);
// replace the top double on the stack with its cosine return status

extern int opDiv(void);
// replace the top two doubles on the stack with their quotient, return status

extern int opDrop(void);
// discard the top double on the stack, return status

extern int opDup(void);
// duplicate the top double on the stack, return status

extern int opHelp(void);
// lists the operators supported returns status

extern int opInv(void);
// replace the top double on the stack with its inverse return status

extern int opMul(void);
// replace the top two doubles on the stack with their product, return status

extern int parseToken(char *token_p);
// parse a single token, return status

extern int opE(void);
// push pi onto the stack return status

extern int opLn(void);
// replace the top double on the stack with its natural log return status

extern int opLog(void);
// replace the top double on the stack with its log base 10 return status

extern int opPi(void);
// push pi onto the stack return status

extern int parseDouble(char *token_p, double *d);
// parse a string token into a double, return status

extern int popUnaryOperand(double *x_p);
// pop a single double operand off the stack, return status

extern int popBinaryOperands(double *x_p, double *y_p);
// pop two double operands off the stack, return status

extern int opPow(void);
// replace the top two doubles on the stack with their exponentiation,
// return status

extern int opSin(void);
// replace the top double on the stack with its sine return status

extern int opSqrt(void);
// replace the top double on the stack with its square root, return status

extern int opSwap(void);
// swap the top two elements in the stack return status

extern int opSub(void);
// replace the top two doubles on the stack with their difference, return status

extern int opTan(void);
// replace the top double on the stack with its tangent return status

// End of File
