#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<string.h>
#include "stack.h"
#include "../Queues/queue.h"

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
void test_balance()
{
    Stack s=stack_new(5);
    Stack *stk=&s;
    Status res;
    Status *r=&res;
    char c[]="[{()}][{}]()";
    assert(balanced(stk,r,c)==true);
}
void test_postfix()
{
    Stack s=stack_new(5);
    Stack *stk=&s;
    Status res;
    Status *r=&res;
    char d[]="6523+8*+3+*";
    int ce=postfix(stk,r,d);
    assert(288==ce); //returns a zero if both strings are same, and a non zero number otherwise
}

void test_queues_using_stacks()
{
    Stack s=stack_new(5);
    Stack *stk=&s;
    Status r;
    Status *res=&r;
    res->status=STACK_EMPTY;
    stk=push(stk,10,res);
    assert(peek(stk,res)==10);
     stk=push(stk,20,res);
      stk=push(stk,30,res);
    assert(res->status==STATUS_OK);
       stk=push(stk,40,res);
        stk=push(stk,50,res);
    assert(res->status==STACK_FULL);
    stk=q_pop(stk,res);
    assert(res->top_ele==10);
    assert(peek(stk,res)==50);
}

void test_pgm_5()
{
    Stack s=stack_new(5);
    Stack *stk=&s;
    Status re;
    Status *res=&re;
    res->status=STACK_EMPTY;
    Queue que=queue_new(5);
    Queue *q=&que;
    Result result;
    Result *r=&result;
    int ans;
    stk=push(stk,10,res);
    assert(peek(stk,res)==10);
     stk=push(stk,20,res);
      stk=push(stk,30,res);
       stk=push(stk,40,res);
        stk=push(stk,50,res);
    ans=check_stack_using_queue(stk,res,q,r,30);
    assert(ans==1 && peek(stk,res)==50);
    stk=pop(stk,res);
    ans=check_stack_using_queue(stk,res,q,r,30);
    assert(ans==1 && peek(stk,res)==40);
    ans=check_stack_using_queue(stk,res,q,r,50);
    assert(ans==0 && peek(stk,res)==40);
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
    //test_balance();
    test_postfix();
    test_queues_using_stacks();
    test_pgm_5();


    return 0;

}
