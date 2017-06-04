/*
 * This file contains the functions for the rpn operators.
 */

#include "rpn.h"

extern int opACos(void)
// replace the top double on the stack with its arc cosine return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    doubleStack_push(acos(d));
    return 1;
}

extern int opAdd(void)
// replace the top two doubles on the stack with their sum, return status
{
    double x, y;

    if (!popBinaryOperands(&x, &y)) {
        return 0;
    }
    doubleStack_push(x + y);
    return 1;
}

extern int opASin(void)
// replace the top double on the stack with its arc sine return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    doubleStack_push(asin(d));
    return 1;
}

extern int opATan(void)
// replace the top double on the stack with its arc tangent return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    doubleStack_push(atan(d));
    return 1;
}

extern int opClr(void)
// clear the stack, return status (always successful)
{
    double d;

    while(1) {
        if(!doubleStack_pop(&d)) {
            break;
        }
    }
    return 1;
}

extern int opCos(void)
// replace the top double on the stack with its cosine return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    doubleStack_push(cos(d));
    return 1;
}

extern int opDiv(void)
// replace the top two doubles on the stack with their quotient, return status
{
    double x, y;

    if (!popBinaryOperands(&x, &y)) {
        return 0;
    }
    if(y == 0) {
        doubleStack_push(x);
        doubleStack_push(y);
        return 0;
    }
    doubleStack_push(x / y);
    return 1;
}

extern int opDrop(void)
// discard the top double on the stack, return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }

    return 1;
}

extern int opDup(void)
// duplicate the top double on the stack, return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }

    doubleStack_push(d);
    doubleStack_push(d);
    return 1;
}

extern int opE(void)
// push pi onto the stack return status
{
    doubleStack_push(M_E);
    return 1;
}

extern int opHelp(void)
// lists the operators supported returns status
{
    printf("\t\t+    -- Addition\n");
    printf("\t\t-    -- Subtraction\n");
    printf("\t\t*    -- Multiplication\n");
    printf("\t\t/    -- Division\n");
    printf("\t\t**   -- Exponentiation\n");
    printf("\t\tsqrt -- Square Root\n");
    printf("\t\tpi   -- Pi\n");
    printf("\t\te    -- Euler's Number\n");
    printf("\t\tln   -- Natural Log\n");
    printf("\t\tlog  -- Log base 10\n");
    printf("\t\tinv  -- Inverse\n");
    printf("\t\tsin  -- Sine\n");
    printf("\t\tcos  -- Cosine\n");
    printf("\t\ttan  -- Tangent\n");
    printf("\t\tasin -- Arc Sine\n");
    printf("\t\tacos -- Arc Cosine\n");
    printf("\t\tatan -- Arc Tangent\n");
    printf("\t\tswap -- Swap\n");
    printf("\t\tclr  -- Clear\n");
    printf("\t\tdrop -- Drop\n");
    printf("\t\tdup  -- Duplicate\n");
    printf("\t\thelp -- Print Help\n");
    printf("\t\tquit -- Quit\n");

    return 1;
}

extern int opInv(void)
// replace the top double on the stack with its inverse return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    if(d == 0) {
        return 0;
    }
    doubleStack_push(1/d);
    return 1;
}

extern int opLn(void)
// replace the top double on the stack with its natural log return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    if(d < 0) {
        return 0;
    }
    doubleStack_push(log(d));
    return 1;
}

extern int opLog(void)
// replace the top double on the stack with its log base 10 return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    if(d < 0) {
        return 0;
    }
    doubleStack_push(log10(d));
    return 1;
}

extern int opMul(void)
// replace the top two doubles on the stack with their product, return status
{
    double x, y;

    if (!popBinaryOperands(&x, &y)) {
        return 0;
    }
    doubleStack_push(x * y);
    return 1;
}

extern int opPi(void)
// push pi onto the stack return status
{
    doubleStack_push(M_PI);
    return 1;
}

extern int opPow(void)
// replace the top two doubles on the stack with their exponentiation,
// return status
{
    double x, y;

    if (!popBinaryOperands(&x, &y)) {
        return 0;
    }
    doubleStack_push(pow(x, y));
    return 1;
}

extern int opSin(void)
// replace the top double on the stack with its sine return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    doubleStack_push(sin(d));
    return 1;
}

extern int opSqrt(void)
// replace the top double on the stack with its square root, return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    if(d < 0) {
        return 0;
    }
    doubleStack_push(sqrt(d));
    return 1;
}

extern int opSub(void)
// replace the top two doubles on the stack with their difference, return status
{
    double x, y;

    if (!popBinaryOperands(&x, &y)) {
        return 0;
    }
    doubleStack_push(x - y);
    return 1;
}

extern int opSwap(void)
// swap the top two elements in the stack return status
{
    double x, y;

    if (!popBinaryOperands(&x, &y)) {
        return 0;
    }
    doubleStack_push(y);
    doubleStack_push(x);
    return 1;
}

extern int opTan(void)
// replace the top double on the stack with its tangent return status
{
    double d;

    if(!popUnaryOperand(&d)) {
        return 0;
    }
    doubleStack_push(tan(d));
    return 1;
}

// End of File
