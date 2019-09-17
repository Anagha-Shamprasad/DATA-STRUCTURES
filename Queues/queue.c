#include<assert.h>
#include<stdbool.h>
#include<stdio.h>
#include<stdint.h>
#include "queue.h"

Queue queue_new(uint32_t size)
{
    size=(size>MAX_DEPTH)?MAX_DEPTH:size;
    Queue q={0,0,size,0,{0}};
    return q;
}

uint32_t queue_status(Queue *q)
{
    assert(q!=NULL);
    if(q->count1==0) return 0;
    if(q->count1==q->size1) return 1;
    return 2;
}

Queue* q_add(Queue *q,Status *res,int32_t ele)
{
    assert(q!=NULL);
    if(q->count1!=q->size1)
    {
        q->data[q->head]=ele;
        q->head=(q->head+1)%q->size1;
        q->count1++;
        //res->data=ele;
        if(q->count1==q->size1) res->status=QUEUE_FULL;
    }
    return q;
}

Queue* q_delete(Queue *q,Status *res)
{
    assert(q!=NULL);
    if(q->count1!=0)
    {
        res->data=q->data[q->tail];
        q->data[q->tail]=false;
        q->tail=(q->tail+1)%q->size1;
        q->count1--;
        if(q->count1==0) res->status==QUEUE_EMPTY;
    }
    return q;
}
