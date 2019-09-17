#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include "stack.h"

void test_push(Stack *stk,Status *res)
{
    assert(peek(stk,res)==false);
    assert(stack_status(stk)==0);
    stk=push(stk,10,res);
    assert(peek(stk,res)==10);
     stk=push(stk,20,res);
      stk=push(stk,30,res);
       stk=push(stk,40,res);
        stk=push(stk,50,res);
         stk=push(stk,60,res);
         assert(res->status==1);
    assert(peek(stk,res)==50);
}

void test_pop(Stack *stk,Status *res)
{
    assert(peek(stk,res)==50);
    stk=pop(stk,res);
    assert(peek(stk,res)==40);
    stk=pop(stk,res);
    stk=pop(stk,res);
    stk=pop(stk,res);
    assert(peek(stk,res)==10);
    assert(stack_status(stk)==2);
    stk=pop(stk,res);
    assert(peek(stk,res)==false);
    assert(stack_status(stk)==0);
}
int main()
{
    Stack s=stack_new(5);
    Stack *stk=&s;
    Status res;
    Status *r=&res;
    r->status=STACK_EMPTY;
    test_push(stk,r);
    test_pop(stk,r);

    return 0;
}
