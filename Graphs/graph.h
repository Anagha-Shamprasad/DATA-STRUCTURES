#include<stddef.h>

typedef struct _node_ Node;
typedef struct _nei_ Graph;
#define MAX 5

struct _node_ {
    int data;
    Node* next;
};

struct _nei_{
    Node** adj_list;
    int size;
};

int visited[MAX];

Graph graph_new(int size);
Graph* adjacency_list(Graph *gp);
Graph* _dfs_(Graph *gp,int start);
void dfs(Graph *gp,int start);
