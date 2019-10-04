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

Queue* q_add(Queue *q,Result *res,int32_t ele)
{
    assert(q!=NULL);
    res->status=QUEUE_EMPTY;
    if(q->count1!=q->size1)
    {
        q->data[q->head]=ele;
        q->head=(q->head+1)%q->size1;
        q->count1++;
        //res->data=ele;
    }
    if(q->count1==q->size1) res->status=QUEUE_FULL;
    return q;
}

Queue* q_delete(Queue *q,Result *res)
{
    assert(q!=NULL);
    if(q->count1!=0)
    {
        res->data=q->data[q->tail];
        q->data[q->tail]=false;
        q->tail=(q->tail+1)%q->size1;
        q->count1--;
    }
    if(q->count1==0) res->status==QUEUE_EMPTY;
    return q;
}

Queue* s_pop(Queue *q,Result *res)
{
    assert(q!=NULL);
    if(queue_status(q)!=QUEUE_EMPTY)
    {
        int i;
        if(q->count1==1)
        {
            q_delete(q,res);
            return q;
        }
        int temp;
        for(i=1;i<q->count1;i++)
        {
            q=q_delete(q,res);
            temp=res->data;
            q=q_add(q,res,temp);
        }
        q=q_delete(q,res);

    }
    return q;
}

int32_t q_peek(Queue *q)
{
    assert(q!=NULL);
    return q->data[q->head-1];
}
