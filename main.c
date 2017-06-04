/*
 * Kyle Thomas
 * Washington State University
 * Computer Science 121 Homework 9
 * Special thanks to Dr. Robert Lewis for the template
 */

#include "rpn.h"

extern int popUnaryOperand(double *x_p)
/* pop a single double operand off the stack, return status */
{
    return(doubleStack_pop(x_p));
}

extern int popBinaryOperands(double *x_p, double *y_p)
/* pop two double operands off the stack, return status */
{
    if(!doubleStack_pop(y_p)) {
        return 0;
    }

    if(!doubleStack_pop(x_p)) {
        doubleStack_push(*y_p);
        return 0;
    }
    return 1;
}

extern int parseDouble(char *token_p, double *d)
/* parse a string token into a double, return status */
{
    char *end_p;

    (*d) = strtod(token_p, &end_p);
    if (end_p != token_p || *end_p == '\0')
    {
        return 1;
    }
    return 0;
}

static void evaluateLine(char *line_p)
// break `line_p` into operands and operators and apply them to the
// stack
{

    char *token_p;

    for (token_p = strtok(line_p, " \n\t");
         token_p != NULL;
         token_p = strtok(NULL, " \n\t")) {
        if (!parseToken(token_p)) {
            printf("     %*s^--error... type help for a list of operations\n",
                (int) (token_p - line_p), "");
            return; /* stop processing this line at the first error */
        }
    }
}


int main(int argc, char *argv[])
{
    if(argc > 1) {
        for(int i = 1; i < argc; ++i) {
            if(!parseToken(argv[i])) {
                fprintf(stderr, "Error");
                exit(1);
            }
        }
        doubleStack_print();
    }
    else {
        char line[1024];

        while(1) {
            doubleStack_print();
            printf("rpn: ");
            if(fgets(line, 1024, stdin) == NULL) {
                break;
            }
            evaluateLine(line);
        }
    }
    return 0;
}

// End of File
