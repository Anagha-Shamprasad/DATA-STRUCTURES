#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include<stdbool.h>
#include "queue.h"

void test(Queue *q,Result *res)
{
    q=q_add(q,res,10);
    q=q_add(q,res,20);
    q=q_add(q,res,30);
    q=q_add(q,res,40);
    q=q_add(q,res,50);
    q=q_add(q,res,60);
    assert(q->count1==5);
    q=q_delete(q,res);
    assert(q->count1==4);
    assert(res->data==10);
    q=q_delete(q,res);
    assert(res->data==20);
    q=q_delete(q,res);
    q=q_delete(q,res);
    assert(res->data==40);
    assert(q->count1==1);
    q=q_delete(q,res);
    assert(q->count1==0 && res->data==50);
}

void test_stk_using_queue()
{
    Queue que=queue_new(5);
    Queue *q=&que;
    Result res;
    Result *r=&res;
    q=q_add(q,r,10);
    q=q_add(q,r,20);
    q=q_add(q,r,30);
    q=q_add(q,r,40);
    q=s_pop(q,r);
    assert(q_peek(q)==30);
    q=q_add(q,r,40);
    assert(q_peek(q)==40);
    q=q_add(q,r,50);
    q=q_add(q,r,60);
    assert(q_peek(q)==50);
    q=s_pop(q,r);
    assert(q_peek(q)==40);
    q=s_pop(q,r);
    q=s_pop(q,r);
    q=s_pop(q,r);
    q=s_pop(q,r);
    assert(q_peek(q)==false);
}
int main()
{
    Queue que=queue_new(5);
    Queue *q=&que;
    Result res;
    test(q,&res);
    test_stk_using_queue();
    return 0;
}
