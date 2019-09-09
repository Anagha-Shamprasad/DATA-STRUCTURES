#ifndef _INCLUDED_DLIST_
#define _INCLUDED_DLIST_
#include<stdint.h>

typedef struct _node1_ d_Node;
typedef struct _dlist_ Dlist;

struct _node1_{
    int32_t data;
    d_Node* next;
    d_Node* prev;
};

struct _dlist_{
    d_Node* head;
    d_Node* tail;
    uint32_t length;
};

Dlist dlist_new();
Dlist* add_head(Dlist *list,int32_t ele);
Dlist* add_tail(Dlist *list,int32_t ele);
Dlist* add_after(Dlist *list,int32_t ele,int32_t after);
Dlist* delete_element(Dlist *list,int32_t ele);
uint32_t lookup(const Dlist *list ,int32_t key);
void display2(Dlist *list);


#endif
