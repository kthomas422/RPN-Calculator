/*
 * This file contains the function to determine which rpn function to use.
 */

#include "rpn.h"

extern int parseToken(char *token_p)
// parse a single token_p, return status
{
    double d;

    if(parseDouble(token_p, &d)) {
        doubleStack_push(d);
        return 1;
    }
    else if(!strcmp(token_p, "+")) {
        return (opAdd());
    }
    else if(!strcmp(token_p, "-")) {
        return (opSub());
    }
    else if(!strcmp(token_p, "*")) {
        return (opMul());
    }
    else if(!strcmp(token_p, "/")) {
        return (opDiv());
    }
    else if(!strcmp(token_p, "**")) {
        return (opPow());
    }
    else if(!strcmp(token_p, "clr")) {
        return (opClr());
    }
    else if(!strcmp(token_p, "drop")) {
        return (opDrop());
    }
    else if(!strcmp(token_p, "dup")) {
        return (opDup());
    }
    else if(!strcmp(token_p, "quit")) {
        exit(0);
    }
    else if(!strcmp(token_p, "sqrt")) {
        return (opSqrt());
    }
    else if(!strcmp(token_p, "pi")) {
        return (opPi());
    }
    else if(!strcmp(token_p, "e")) {
        return (opE());
    }
    else if(!strcmp(token_p, "ln")) {
        return (opLn());
    }
    else if(!strcmp(token_p, "log")) {
        return (opLog());
    }
    else if(!strcmp(token_p, "swap")) {
        return (opSwap());
    }
    else if(!strcmp(token_p, "inv")) {
        return (opInv());
    }
    else if(!strcmp(token_p, "help")) {
        return (opHelp());
    }
    else if(!strcmp(token_p, "cos")) {
        return (opCos());
    }
    else if(!strcmp(token_p, "sin")) {
        return (opSin());
    }
    else if(!strcmp(token_p, "tan")) {
        return (opTan());
    }
    else if(!strcmp(token_p, "acos")) {
        return (opACos());
    }
    else if(!strcmp(token_p, "asin")) {
        return (opASin());
    }
    else if(!strcmp(token_p, "atan")) {
        return (opATan());
    }
    else
        return 0;
}

// End of File
