#ifndef _INCLUDE_STACK_
#define _INCLUDE_STACK_

#include<stdint.h>
#include<stddef.h>

typedef struct _stack_ Stack;
typedef struct _status_ Status;

#define MAX_SIZE 32

struct _stack_{
    int32_t size;
    int32_t top;
    float data[MAX_SIZE];
};

struct _status_{
    float top_ele;
    int32_t status;
};

#define STATUS_OK 2
#define STACK_FULL 1
#define STACK_EMPTY 0

Stack stack_new(int32_t size);
uint32_t stack_status(const Stack *stk);
Stack* push(Stack *stk,int32_t ele,Status *res);
Stack* pop(Stack *stk,Status *res);
float peek(const Stack *stk,const Status *res);



#endif

