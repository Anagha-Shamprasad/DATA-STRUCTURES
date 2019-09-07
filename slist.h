#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_
#include<stdint.h>

typedef struct _node_ Node;
typedef struct _slist_ Slist;

struct _node_{
    int32_t data;
    Node* next;
};

struct _slist_{
    Node* head;
    Node* tail;
    uint32_t length;
};

Slist slist_new();

Slist* slist_add_head(Slist *list,int32_t element);
Slist* slist_add_tail(Slist *list,int32_t element);
Slist* delete_head(Slist *list);
Slist* delete_tail(Slist *list);
//Slist* slist_delete_head(Slist *list);
uint32_t slist_length(const Slist *list);
uint32_t slist_lookup(const Slist *list,int32_t key);

int32_t maximum(const Slist *list);
int32_t minimum(const Slist *list);
Slist* add_element_at_pos(Slist *list,int32_t element,int32_t loc);
Slist* add_element_after_element(Slist *list,int32_t to_add,int32_t data);
Slist* delete_an_element(Slist *list,int32_t element);
uint32_t same_or_not(Slist *list,Slist *list2);
Slist* union_list(Slist *list,Slist *list2,Slist *list3);
Slist* intersection(Slist *list,Slist *list2,Slist *list3);
Slist* slist_add_unique_tail(Slist *list,int32_t element);
Slist* slist_add_unique_head(Slist *list ,int32_t element);
Slist* add_unique_element_after_element(Slist *list,int32_t to_add,int32_t data);
Slist* reverse_list(Slist *list);

void display(Slist *list);

#endif // SLIST_H_INCLUDED
