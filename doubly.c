#include<assert.h>
#include<stdbool.h>
#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>
#include "doubly.h"
// Welcome Anagha

Dlist dlist_new()
{
    Dlist s ={NULL,NULL,0};
    return s;
}

static d_Node* create_newnode(int32_t element)
{
    d_Node *new_node=(d_Node *)malloc(sizeof(d_Node));
    new_node->data=element;
    new_node->next=NULL;
    new_node->prev=NULL;

    return new_node;
}

Dlist* add_head(Dlist *list,int32_t ele)
{
    assert(list!=NULL);

    d_Node *temp=create_newnode(ele);
    if(list->length==0)
    {
        list->head=list->tail=temp;
    }
    else
    {
        list->head->prev=temp;
        temp->next=list->head;
        list->head=temp;
    }

    ++list->length;
    return list;
}

Dlist* add_tail(Dlist *list,int32_t ele)
{
    assert(list!=NULL);
    d_Node *temp=create_newnode(ele);
    if(list->length==0)
    {
        list->head=list->tail=temp;
    }
    else
    {
        list->tail->next=temp;
        temp->prev=list->tail;
        list->tail=temp;
    }
    ++list->length;
    return list;
}

Dlist* add_after(Dlist *list,int32_t ele,int32_t after)
{
  assert(list!=NULL);
  if(list->length>0)
  {
    if(list->tail->data==after) return add_tail(list,ele);
    d_Node *temp=create_newnode(ele);
    d_Node *cur;
    for(cur=list->head;cur!=NULL;cur=cur->next)
    {
        if(cur->data==after) break;
    }

    if(cur!=NULL) {
    temp->next=cur->next;
    cur->next->prev=temp;
    cur->next=temp;
    temp->prev=cur;
    ++list->length;
    }
  }
    return list;
}

Dlist* delete_element(Dlist *list,int32_t ele)
{
    assert(list!=NULL);
    if(list->length>0)
    {
        if(list->length==1 && list->head->data==ele)
        {
            list->head=list->tail=NULL;
            --list->length;
        }
        else
        {
            d_Node *cur;
            int32_t count=1;
            for(cur=list->head;cur!=NULL;cur=cur->next)
            {
                if(cur->data==ele) break;
                  count++;
            }

            if(cur!=NULL) {
                if(count==1)
                {
                    list->head=cur->next;
                    list->head->prev=NULL;
                }
                else if(count==list->length)
                {
                    list->tail=cur->prev;
                    list->tail->next=NULL;
                }
                else{
                cur->prev->next=cur->next;
                cur->next->prev=cur->prev;
                }
                 free(cur);
                --list->length;
            }
        }
    }
    return list;
}

uint32_t lookup(const Dlist *list ,int32_t key)
{
    assert(list!=NULL);
    d_Node *cur;
    int32_t count=0;
    for(cur=list->head;cur!=NULL;cur=cur->next){
        if(cur->data==key)
        {
            count++;
            break;
        }
    }
    return(cur!=NULL);
}

void display2(Dlist *list)
{
    assert(list!=NULL);
    if(list->length>0)
    {
        d_Node *cur=list->head;

        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur=cur->next;
        }
    }
    return ;
}
