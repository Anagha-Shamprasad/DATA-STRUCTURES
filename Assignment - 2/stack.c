#include<assert.h>
#include<stddef.h>
#include<stdint.h>
#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include "stack.h"
#include "../Queues/queue.h"

Stack stack_new(int32_t size)
{
    size=(size>MAX_SIZE)?MAX_SIZE:size;

    Stack s={size,-1,{0}};
    return s;
}

uint32_t stack_status(const Stack *stk)
{
    assert(stk!=NULL);
    if(stk->top==-1) return STACK_EMPTY;
    if(stk->top+1==stk->size) return STACK_FULL;
    return STATUS_OK;
}

Stack* push(Stack *stk,D_Type ele,Status *res)
{
    assert(stk!=NULL);
    if(stack_status(stk)!=1)
    {
        stk->data[++stk->top]=ele;
        //res->top_ele=ele;
        if(stack_status(stk)==1) res->status=STACK_FULL;
        else res->status=STATUS_OK;
    }
    return stk;
}

Stack* pop(Stack *stk,Status *res)
{
    assert(stk!=NULL);
    if(stack_status(stk)!=0)
    {
        res->top_ele=stk->data[stk->top];
        stk->data[stk->top]=false;
        stk->top--;
    }
    if(stack_status(stk)==0) res->status=STACK_EMPTY;

    return stk;
}

int32_t peek(const Stack *stk,const Status *res)
{
    assert(stk!=NULL);
    if(stack_status(stk)!=0) return stk->data[stk->top];
    return false;
}
//___________________________________________________________________________________________________
                                    /*PROBLEM 1*/

uint32_t balanced(Stack *stk,Status *res,char c[])
{
    assert(stk!=NULL);

    int i=0;
    while(c[i]!='\0')
    {
        if(c[i]=='['||c[i]=='{'||c[i]=='(') stk=push(stk,c[i],res);

        else if(c[i]==']' && res->top_ele=='[') stk=pop(stk,res);

        else if(c[i]=='}' && res->top_ele=='{') stk=pop(stk,res);
        else if(c[i]==')' && res->top_ele == '(') stk=pop(stk,res);
        else return 0;
        i++;
    }

    if(res->status==STACK_EMPTY) return 1;
    else return 0;
}
//____________________________________________________________________________________________________

                                        /*PROBLEM 2*/

int postfix(Stack *stk,Status *res,char c[])
{
    assert(stk!=NULL);
    int i;
    char a,b;
    int ans=0;
    if(c!=NULL)
    {
        for(i=0;i<strlen(c);i++)
        {
            if(isdigit(c[i])) push(stk,c[i]-'0',res);

            else
            {
                switch(c[i])
                {
                    case '+': a=peek(stk,res);
                              stk=pop(stk,res);
                              b=peek(stk,res);
                              stk=pop(stk,res);
                              ans=b+a;
                              stk=push(stk,ans,res);
                              break;

                    case '-': a=peek(stk,res);
                              stk=pop(stk,res);
                              b=peek(stk,res);
                              stk=pop(stk,res);
                              ans=b-a;
                              stk=push(stk,ans,res);
                              break;

                    case '*': a=peek(stk,res);
                              stk=pop(stk,res);
                              b=peek(stk,res);
                              stk=pop(stk,res);
                              ans=b*a;
                              stk=push(stk,ans,res);
                              break;

                    case '/': a=peek(stk,res);
                              stk=pop(stk,res);
                              b=peek(stk,res);
                              stk=pop(stk,res);
                              ans=b/a;
                              stk=push(stk,ans,res);
                              break;
                }
            }
        }
    }
    return stk->data[stk->top];
}

//__________________________________________________________________________________________________
                                    /*PROBLEM 6*/

Stack* q_pop(Stack *stk,Status *res)
{
    assert(stk!=NULL);
    Stack sta=stack_new(stk->size);
    Stack *s=&sta;
    Status resu;
    Status *r=&resu;
    if(stack_status(stk)!=STACK_EMPTY)
    {
        int temp,i,count=0;
        while(stk->top!=0)
        {
            count++;
            temp=peek(stk,res);
            stk=pop(stk,res);
            s=push(s,temp,r);
        }
        stk=pop(stk,res);
        for(i=0;i<count;i++)
        {
            temp=peek(s,r);
            s=pop(s,r);
            stk=push(stk,temp,res);
        }
    }
    return stk;
}

//___________________________________________________________________________________________________
                                        /*PROBLEM 5*/
int32_t check_stack_using_queue(Stack *stk,Status *res,Queue *q,Result *r,int32_t key)
{
    assert(stk!=NULL && q!=NULL);
    int flag=0;
    if(stk->top!=-1)
    {
        int temp;
        while(stk->top!=-1)
        {
            if(key!=stk->data[stk->top])
            {
                stk=pop(stk,res);
                temp=res->top_ele;
                q=q_add(q,r,temp);
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1 || q->count1!=0)
        {
            int temp_count=0;
           while(q->count1!=0)
           {
                temp_count++;
                q=q_delete(q,r);
                temp=r->data ;
                stk=push(stk,temp,res);
           }
           int i;
           for(i=1;i<=temp_count;i++)
           {
               stk=pop(stk,res);
               temp=res->top_ele;
               q=q_add(q,r,temp);
           }
           while(q->count1!=0)
           {
                temp_count++;
                q=q_delete(q,r);
                temp=r->data ;
                stk=push(stk,temp,res);
           }


        }
    }

    return flag;
}


