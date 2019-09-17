#ifndef _INCLUDED_DLIST_
#define _INCLUDED_DLIST_
#include<stdint.h>

typedef struct _node1_ Node;
typedef struct _dlist_ Dlist;

struct _node1_{
    int32_t data;
    Node* next;
    Node* prev;
};

struct _dlist_{
    Node* head;
    Node* tail;
    uint32_t length;
};

Dlist* add_head(Dlist *list,int32_t ele)
{

}

#endif
