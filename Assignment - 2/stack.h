#ifndef _INCLUDE_STACK_
#define _INCLUDE_STACK_
#define D_Type int
#include<stdint.h>
#include<stddef.h> 
#include "../Queues/queue.h"

typedef struct _stack_ Stack;
typedef struct _status_ Status;

#define MAX_SIZE 30

struct _stack_{
    int32_t size;
    int32_t top;
    D_Type data[MAX_SIZE];
};

struct _status_{
    D_Type top_ele;
    int32_t status;
};

#define STATUS_OK 2
#define STACK_FULL 1
#define STACK_EMPTY 0

Stack stack_new(int32_t size);
uint32_t stack_status(const Stack *stk);
Stack* push(Stack *stk,D_Type ele,Status *res);
Stack* pop(Stack *stk,Status *res);
int32_t peek(const Stack *stk,const Status *res);
uint32_t balanced(Stack *stk,Status *res,char c[]);
int postfix(Stack *stk,Status *res,char c[]);
Stack* q_pop(Stack *stk,Status *res);
int32_t check_stack_using_queue(Stack *stk,Status *res,Queue *q,Result *r,int32_t key);

#endif

