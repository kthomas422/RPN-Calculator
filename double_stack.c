/*
 * This file contains the functions for managing the stack.
 */

#include "rpn.h"

static struct DoubleStack *base_p = NULL;

static void doubleStack_delete(struct DoubleStack *doubleStack_p)
/* deallocate a `struct DoubleStack` node from the heap */
{
    free(doubleStack_p);
}

static struct DoubleStack *doubleStack_new(double d)
/* allocate and fill in a `struct DoubleStack` node from the heap */
{
    struct DoubleStack *doubleStack_p;
    doubleStack_p = malloc(sizeof(struct DoubleStack));
    doubleStack_p -> next_p = NULL;
    doubleStack_p -> d = d;

    return doubleStack_p;
}

void doubleStack_push(double d)
/* see header */
{
    struct DoubleStack *doubleStack_p;
    doubleStack_p = doubleStack_new(d);
    doubleStack_p->next_p = base_p;
    base_p = doubleStack_p;
}


int doubleStack_pop(double *d_p)
/* see header */
{
    struct DoubleStack *top_p;

    if(base_p == NULL){
        return 0;
    }
    top_p = base_p;
    *d_p = top_p->d;
    base_p = top_p->next_p;
    doubleStack_delete(top_p);
    return 1;
}

void doubleStack_print(void)
/* see header */
{
    double d;
    if(doubleStack_pop(&d)) {
        doubleStack_print();
        printf("%20.14lg\n", d);
        doubleStack_push(d);
    }
}

// End of File
