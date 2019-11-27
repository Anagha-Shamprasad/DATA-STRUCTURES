#include<assert.h>
#include<stddef.h>
#include<stdbool.h>
#include "graph.h"

int main()
{
    Graph gpp=graph_new(5);
    Graph *gp=&gpp;
    gp=adjacency_list(gp);
    gp=_dfs_(gp,0);

    return 0;
}
