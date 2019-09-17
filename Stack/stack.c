#include<assert.h>
#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
#include "stack.h"

Stack stack_new(int32_t size)
{
    size=(size>MAX_SIZE)?MAX_SIZE:size;

    Stack s={size,-1,{0}};
    return s;
}

uint32_t stack_status(const Stack *stk)
{
    assert(stk!=NULL);
    if(stk->top==-1) return STACK_EMPTY;
    if(stk->top+1==stk->size) return STACK_FULL;
    return STATUS_OK;
}

Stack* push(Stack *stk,int32_t ele,Status *res)
{
    assert(stk!=NULL);
    if(stack_status(stk)!=1)
    {
        stk->data[++stk->top]=ele;
        res->top_ele=ele;
        if(stack_status(stk)==1) res->status=STACK_FULL;
        else res->status=STATUS_OK;
    }
    return stk;
}

Stack* pop(Stack *stk,Status *res)
{
    assert(stk!=NULL);
    if(stack_status(stk)!=0)
    {
        stk->top--;
        if(stack_status(stk)==0)
        {
            res->status=STACK_EMPTY;
            res->top_ele=false;
        }
        else res->top_ele=stk->data[stk->top];
    }
    return stk;
}

float peek(const Stack *stk,const Status *res)
{
    assert(stk!=NULL);
    if(stack_status(stk)!=0) return res->top_ele;
    return false;
}


