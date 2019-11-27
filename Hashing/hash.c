#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<assert.h>
#include<String.h>
#include "hash.h"

static Node* create_node(char ele[])
{
    Node* temp;
    temp=(Node*)malloc(sizeof(Node));
    strcpy(temp->name,ele);
    temp->next=NULL;
    return temp;
}

int generate_hash(HashTable *ht,char ele[])
{
    int i=1;
    int temp=ele[0];
    while(ele[i]!='\0')
    {
        temp=ele[i];
        temp=temp+(ele[i]<<5);
        i++;
    }
    int hash = temp%ht->size;
    return hash;
}

HashTable hash_new(int size)
{
    int size1 = size>MAX_VALUE?MAX_VALUE:size;
    HashTable ht;
    ht.size=size1;
    ht.addrlist=(Node**)malloc(sizeof(Node*)*size1);
    int i=0;
    for(i=0;i<ht.size;i++)
    {
        ht.addrlist[i]=NULL;
    }
    return ht;
}

int lookup(HashTable *ht,char ele[])
{
    assert(ht!=NULL);
    int hash=generate_hash(ht,ele);
    Node *cur;
    cur=ht->addrlist[hash];
    while(cur!=NULL)
    {
        if(strcmp(cur->name,ele)==0) break;
        cur=cur->next;
    }

    if(cur==NULL) return 0;
    else return 1;

}

HashTable* add_to_hash(HashTable *ht,char ele[])
{
    assert(ht!=NULL);
    int hash=generate_hash(ht,ele);
    if(lookup(ht,ele)==0)
    {
        Node *temp=create_node(ele);
        if(ht->addrlist[hash]==NULL)
        {
            ht->addrlist[hash]=temp;
        }
        else
        {
            Node *cur=ht->addrlist[hash];
            ht->addrlist[hash]=temp;
            temp->next=cur;
        }
    }
    return ht;
}

HashTable* delete_from_hash(HashTable *ht,char ele[])
{
    assert(ht!=NULL);
    int hash=generate_hash(ht,ele);
    if(ht->addrlist[hash]!=NULL)
    {
        Node *cur=ht->addrlist[hash];
        Node *prev=cur;
        if(cur->next==NULL)
        {
            ht->addrlist[hash]=NULL;
            free(cur);
        }
        else
        {
            while(cur!=NULL)
            {
                prev=cur;
                if(strcmp(cur->name,ele)==0)
                {
                    prev->next=cur->next;
                    free(cur);
                }
                cur=cur->next;
            }
        }

    }
    return ht;
}

