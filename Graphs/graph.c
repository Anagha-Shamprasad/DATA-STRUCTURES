#include<stddef.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>
#include<stdio.h>
#include "graph.h"

Graph graph_new(int size)
{
    Graph gp;
    gp.size=size;
    int i=0;
    gp.adj_list=(Node**)malloc(sizeof(Node*)*gp.size);
    for(i=0;i<gp.size;i++)
    {
        gp.adj_list[i]=NULL;
    }
    return gp;
}

static Node* get_node(int ele)
{
    Node *temp=(Node*)malloc(sizeof(Node));
    temp->data=ele;
    temp->next=NULL;
    return temp;
}

static int get_neighbour(int i)
{
    int n;
    printf("Enter the neighbour of %d  : ",i);
    scanf("%d",&n);
    return n;
}


Graph* adjacency_list(Graph *gp)
{
    assert(gp!=NULL);

    int i=0;
    int neighbour;
    Node *temp, *last_vertex;
    for(i=0;i<gp->size;i++)
    {
        gp->adj_list[i]=get_node(i);
        neighbour=get_neighbour(i);
        while(neighbour!=9999)
        {
            temp=get_node(neighbour);
            if(gp->adj_list[i]->next==NULL)
            {
                gp->adj_list[i]->next=temp;
            }
            else
            {
                last_vertex->next=temp;
            }
            last_vertex=temp;
            neighbour=get_neighbour(i);
        }
    }
    return gp;
}

static void make_null(Graph *gp)
{
    assert(gp!=NULL);
    int i=0;
    for(i=0;i<gp->size;i++)
    {
        visited[i]=false;
    }
}

Graph* _dfs_(Graph *gp,int start)
{
    assert(gp!=NULL);
    make_null(gp);
    dfs(gp,start);
    return gp;
}

void dfs(Graph *gp,int start)
{
    Node *vertex;
    visited[start]=true;
    printf("%d",start);
    for(vertex=gp->adj_list[start];vertex!=NULL;vertex=vertex->next)
    {
        if(visited[vertex->data]==false)
        {
            dfs(gp,vertex->data);
        }
    }
}

/*Graph* bfs(Graph *gp,int source)
{
    assert(gp!=NULL);
    Queue q=queue_new(gp->size);
    QueueResult res;
    printf("%d",source);
    visited[source]=true;
    queue_add(&q,gp->adj_list[source],&res); //gp->adj_list[source]->data
    while(!queue_empty(&q))
    {
        queue_delete(&q,&res);
        int id=res.data; //res.data->data
        Node *vertex;
        for(vertex=gp->adj_list[source];vertex!=NULL;vertex=vertex->next)
        {
            if(visited[vertex->data]==false)
            {
                printf("%d",vertex->data);
                visited[vertex->data]=true;
                queue_add(&q,vertex,&res);
            }
        }
    }
}*/
