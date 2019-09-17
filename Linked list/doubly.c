#include<assert.h>
#include<stdbool.h>
#include<stddef.h>
#include "doubly.h"

Dlist dlist_new()
{
    Dlist s ={NULL,NULL,0};
    return s;
}

static Node* create_newnode(int32_t element)
{
    Node *new_node=(Node *)malloc(sizeof(Node));
    new_node->data=element;
    new_node->next=NULL;
    new_node->prev=NULL;

    return new_node;
}


