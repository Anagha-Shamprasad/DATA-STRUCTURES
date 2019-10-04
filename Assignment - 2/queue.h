#ifndef _INCLUDE_QUEUE_
#define _INCLUDE_QUEUE_
#include<stdint.h>
#include<stddef.h>

typedef struct _queue_ Queue;
typedef struct _result_ Result;

#define MAX_DEPTH 32

struct _queue_{
    uint32_t head;
    uint32_t tail;
    uint32_t size1;
    uint32_t count1;
    int32_t data[MAX_DEPTH];
};

struct _result_ {
    int32_t data;
    uint32_t status;
};

#define QUEUE_OK 2
#define QUEUE_FULL 1
#define QUEUE_EMPTY 0

Queue queue_new(uint32_t size);
uint32_t queue_status(Queue *q);
Queue* q_add(Queue *q,Result *res,int32_t ele);
Queue* q_delete(Queue *q,Result *res);
Queue* s_pop(Queue *q,Result *res);
int32_t q_peek(Queue *q);
#endif // _INCLUDE_QUEUE_
