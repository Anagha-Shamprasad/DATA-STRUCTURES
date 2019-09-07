#include <stdio.h>
#include <stdlib.h>
#include<assert.h>
#include<stdbool.h>
#include "slist.h"

Slist slist_new()
{
    Slist s ={NULL,NULL,0};
    return s;
}

static Node* slist_new_node(int32_t element)
{
Node *new_node=(Node *)malloc(sizeof(Node));
new_node->data=element;
new_node->next=NULL;
return new_node;
}

Slist* slist_add_head(Slist *list ,int32_t element)
{
    assert(list!=NULL);
    Node *new_node = slist_new_node(element);
    new_node->next=list->head;
    list->head=new_node;
    if(list->tail==NULL)
    {
        list->tail=new_node;
    }

    ++list->length;

assert((list->length==1 && list->head ==list->tail)||(list->length>0 && list->head!=list->tail));

return list;
}

Slist* slist_add_tail(Slist *list,int32_t element)
{
    assert(list!=NULL);
    Node *temp=slist_new_node(element);

    if(list->head==NULL)
    {
        list->head=list->tail=temp;
    }
    else
    {
        list->tail->next=temp;
        list->tail=temp;
    }

    ++list->length;
    return list;
}
Slist* delete_head(Slist *list)
{
  assert(list!=NULL);
  if(list->length>0)
  {
      Node *cur=list->head;
      if(list->length==1) list->head=list->tail=NULL;

      else list->head=cur->next;

        free(cur);
      --list->length;
  }
    return list;
}

Slist* delete_tail(Slist *list)
{
    assert(list!=NULL);
    if(list->tail!=NULL)
   {
     Node *cur=list->head;
     Node *prev;
        if(list->length==1)
        {
            list->tail=list->head=NULL;
        }
        else
        {
            while(cur->next!=NULL)
            {
                prev=cur;
                cur=cur->next;
            }
            list->tail=prev;
            prev->next=NULL;

        }
        free(cur);
        --list->length;
   }
   return list;

}

uint32_t slist_length(const Slist *list)
{

    assert(list!=NULL);
       return list->length;
}
uint32_t slist_lookup(const Slist *list ,int32_t key)
{
    assert(list!=NULL);
    Node *cur;
    int32_t count=0;
    for(cur=list->head;cur!=NULL;cur=cur->next){
        if(cur->data==key)
        {
            count++;
            break;
        }
    }
    return(cur!=NULL);
    //return count;
}

int32_t maximum(const Slist *list)
{
   assert(list!=NULL);
   if(list->length==0)
   {
       return false;
   }
   else{

    Node *cur=list->head;
    int32_t max=cur->data;
    while(cur!=NULL)
    {
        if(max<=cur->data)
        {
            max=cur->data;
        }
        cur=cur->next;
    }
    return max;
   }
}

int32_t minimum(const Slist *list)
{
   assert(list!=NULL);
   if(list->length==0)
   {
       return false;
   }
   else{

    Node *cur=list->head;
    int32_t min=cur->data;
    while(cur!=NULL)
    {
        if(min>=cur->data)
        {
            min=cur->data;
        }
        cur=cur->next;
    }
    return min;
   }
}

Slist* add_element_at_pos(Slist *list,int32_t element,int32_t loc)
{
    assert(list!=NULL);

    if(loc==1) return slist_add_head(list,element);
    else if(loc==list->length+1) return slist_add_tail(list,element);

     else if(loc>1&&loc<=list->length)
      {
          Node *temp=slist_new_node(element);
          Node *cur=list->head;
          int i;
          for(i=1;i<=loc-2;i++)
          {
              cur=cur->next;
          }
          temp->next=cur->next;
          cur->next=temp;
          ++list->length;

      }
     return list;
}

Slist* add_element_after_element(Slist *list,int32_t to_add,int32_t data)
{
    assert(list!=NULL);
    Node *temp=slist_new_node(to_add);
    Node *cur;
    if(list->length>0)
    {
        int32_t count=0;
        for(cur=list->head;cur!=NULL;cur=cur->next)
        {
            count++;
            if(data==cur->data) break;
        }
        if(cur==NULL)return list;
        else
        {
            if (count==list->length) list->tail=temp;
            else temp->next=cur->next;

            cur->next=temp;
            ++list->length;
        }
        assert(list->tail->next==NULL);
    }
    return list;
}

Slist* delete_an_element(Slist *list,int32_t element)
{
    assert(list!=NULL);
    if(list->length>0)
    {
        Node *cur;
        Node *prev;
        int32_t count=0;
        for(cur=list->head;cur!=NULL;cur=cur->next)
        {
            count++;
            if(cur->data==element) break;

            else prev=cur;
        }
        if(count==1) return delete_head(list);
        else if(count==list->length) return delete_tail(list);
        else
        {
            prev->next=cur->next;
            free(cur);
            --list->length;
        }
    }
    return list;
}

uint32_t same_or_not(Slist *list,Slist *list2)
{
    assert(list!=NULL && list2!=NULL);
    if(list->length!=list2->length) return false;
    else if((list->length==list2->length)==0) return true;
    else
    {
        Node *cur=list->head;
        Node *temp=list2->head;
        int i;
        for(i=1;i<=list->length;i++)
        {
            if((cur->data==temp->data)&&cur!=NULL)
            {
                cur=cur->next;
                temp=temp->next;
                continue;
            }
            else break;
        }

        if(i==(list->length+1)) return true;
        else return false;
    }
}

Slist* union_list(Slist *list,Slist *list2,Slist *list3)
{
    assert(list!=NULL && list2!=NULL);
    Node *cur;

    if(list->length==0 && list2->length!=0) return list2;
    else if(list2->length==0 && list->length!=0) return list;
    else
    {
        for(cur=list->head;cur!=NULL;cur=cur->next)   slist_add_tail(list3,cur->data);

        for(cur=list2->head;cur!=NULL;cur=cur->next)   slist_add_tail(list3,cur->data);

        return list3;
    }
}

Slist* intersection(Slist *list,Slist *list2,Slist *list3)
{
    assert(list!=NULL && list2!=NULL);

    if(list->length!=0 && list2->length!=0)
    {

        Node *cur;
        for(cur=list->head;cur!=NULL;cur=cur->next)
        {
                if(slist_lookup(list2,cur->data))
                {
                    if(slist_lookup(list3,cur->data)==0) list3=slist_add_tail(list3,cur->data);
                }
        }
    }
    return list3;
}


Slist* slist_add_unique_head(Slist *list ,int32_t element)
{
    assert(list!=NULL);

    if(slist_lookup(list,element)==0)
    {
       Node *new_node = slist_new_node(element);
        new_node->next=list->head;
        list->head=new_node;
        if(list->tail==NULL)
        {
            list->tail=new_node;
        }
        ++list->length;
    }

    assert((list->length==1 && list->head ==list->tail)||(list->length>0 && list->head!=list->tail));

    return list;
}

Slist* slist_add_unique_tail(Slist *list,int32_t element)
{
    assert(list!=NULL);
if(slist_lookup(list,element)==0)
{
    Node *temp=slist_new_node(element);

    if(list->head==NULL)
    {
        list->head=list->tail=temp;
    }
    else
    {
        list->tail->next=temp;
        list->tail=temp;
    }

    ++list->length;
}
    return list;
}

Slist* add_unique_element_after_element(Slist *list,int32_t to_add,int32_t data)
{
    assert(list!=NULL);
    if(slist_lookup(list,to_add)==0)
    {
        Node *temp=slist_new_node(to_add);
        Node *cur;
        if(list->length>0)
        {
            int32_t count=0;
            for(cur=list->head;cur!=NULL;cur=cur->next)
            {
                count++;
                if(data==cur->data) break;
            }
            if(cur==NULL)return list;
            else
            {
                if (count==list->length) list->tail=temp;
                else temp->next=cur->next;

                cur->next=temp;
                ++list->length;
            }
            assert(list->tail->next==NULL);
        }
    }
    return list;
}

Slist* reverse_list(Slist *list)
{
    assert(list!=NULL);
    if(list->length>1)
    {
        Node *cur,*temp,*nxt;
        cur=NULL;
        nxt=list->head;
        temp=nxt->next;
        while(temp!=NULL)
        {
            nxt->next=cur;
            cur=nxt;
            nxt=temp;
            temp=temp->next;
        }

        list->tail=list->head;
        list->head=nxt;
        cur=list->head;

        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur=cur->next;
        }

    }

    return list;

}


void display(Slist *list)
{
    assert(list!=NULL);
    if(list->length>0)
    {
        Node *cur=list->head;

        while(cur!=NULL)
        {
            printf("%d ",cur->data);
            cur=cur->next;
        }
    }
    return ;
}


