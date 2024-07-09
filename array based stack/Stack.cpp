// Stack.cpp

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "Stack.h"




void CreateStack(Stack *ps){
    /* Array-based Impelementation.*/
    // ps->top = 0;

    /* Linked-based Impelementation.*/
    ps->top = NULL;
    ps->size = 0;
    ps->max = 0;
}

void Push(StackEntry e, Stack *ps){
    /* Array-based Impelementation.*/
    // ps->entry[ps->top++] = e;

    /* Linked-based Impelementation.*/
    StackNode *pn = (StackNode*)malloc(sizeof(StackNode));
    pn->entry = e;
    pn->next = ps->top;
    ps->top = pn;
    ps->size++;
    if ((int) e > ps->max){
        ps->max = (int) e;
    } 
}

int StackFull(Stack *ps){
    /* Array-based Impelementation.*/
    // return ps->top == MAXSTACK;

    /* Linked-based Impelementation.*/
    return 0;
}

void Pop(StackEntry *pe, Stack *ps){
    /* Array-based Impelementation.*/
    // *pe = ps->entry[--ps->top];

    /* Linked-based Impelementation.*/
    StackNode *pn;
    *pe = ps->top->entry;
    pn = ps->top;
    ps->top = ps->top->next;
    free(pn);
    ps->size--;
    if ((int)*pe >= ps->max) {ps->max = (int)ps->top->entry;}
}

int StackEmpty(Stack *ps){
    /* Array-based Impelementation.*/
    // return !ps->top;

    /* Linked-based Impelementation.*/
    return !ps->top;
}

void StackTop(StackEntry *pe, Stack *ps){
    /* Array-based Impelementation.*/
    // *pe = ps->entry[ps->top-1];

    /* Linked-based Impelementation.*/
    *pe = ps->top->entry;
}

int StackSize(Stack *ps){
    /* Array-based Impelementation.*/
    // return ps->top;

    /* Linked-based Impelementation.*/
    return ps->size;
}

int StackMax(Stack *ps){
    /* Array-based Impelementation.*/
    // return ps->top;

    /* Linked-based Impelementation.*/
    return ps->max;
}

void ClearStack(Stack *ps){
    /* Array-based Impelementation.*/
    // ps->top = 0;

    /* Linked-based Impelementation.*/
    StackNode *pn = ps->top;
    while(pn){
        pn = pn->next;
        free(ps->top);
        ps->top = pn;
    }
    ps->max = 0;
}

void TraverseStack(Stack *ps, void(*pf) (StackEntry)){
    /* Array-based Impelementation.*/
    // for (int i=ps->top; i>0; i--)
    //     (*pf)(ps->entry[i-1]);

    /* Linked-based Impelementation.*/
    StackNode *pn = ps->top;
    while(pn){
        (*pf)(pn->entry);
        pn = pn->next;
    }
}