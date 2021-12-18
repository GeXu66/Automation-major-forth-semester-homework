#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10020
#define maxm 200020
//图的定义使用链式前向星方式构建图
//当然你也可以用自己的方法构建图,如临接矩阵或者临接表
#define INF 2147483630
int ans[maxn];
typedef struct Edge
{
    int start, end, weight;
    //该边，同一起点的上一边在edgs中存储的下标。以next作为链式寻找同一起点的所有边
    int next;
}edge;

typedef struct Graph
{
    struct Edge edegs[maxm];
    //head[i] 记录的是以i为起点的边集中第一条边在edges中的index,
    int head[maxn];
    //当前第几条边
    int tot;
}graph;

graph *init_graph()
{
    graph *new_graph = (graph *)malloc(sizeof(graph));
    new_graph->tot = 0;
    memset(new_graph->head, -1, sizeof(new_graph->head));
    return new_graph;
}

void add_edge(int start, int end, int weight, graph *graph)
{
    //提供这种存储加边方式
    graph->edegs[++graph->tot].start = start;
    graph->edegs[graph->tot].end = end;
    graph->edegs[graph->tot].weight = weight;

    //链式前向星存储，每加一条边的时候，同一起点的边用next来做链式存储
    graph->edegs[graph->tot].next = graph->head[start];
    graph->head[start] = graph->tot;
}

void visit_graph(int n, graph *graph)
{
    //debug 函数，提供这种存储方式的遍历过程，方便同学们debug
    for (int i = 1; i <= n; i++) //n个起点
    {
        printf("start with %d\n", i);
        for (int j = graph->head[i]; j != -1; j = graph->edegs[j].next) //遍历以i为起点的边
        {
            printf("edgs i is start:%d,end:%d,weight is:%d\n", graph->edegs[j].start, graph->edegs[j].end, graph->edegs[j].weight);
        }
    }
}

int pointTopoint(int startpoint,int endpoint,int final_end, graph *graph)
{
    int search=graph->head[startpoint];
    int min=-1;
    while(search!=-1)
    {
        if(graph->edegs[search].end==endpoint)
        {
            if(min>graph->edegs[search].weight||min==-1)
            {
                min=graph->edegs[search].weight;
            }
        }
        else if(graph->edegs[search].end!=final_end)//消除环的影响
        {
            if((min>graph->edegs[search].weight+pointTopoint(graph->edegs[search].end,endpoint,final_end,graph)||min==-1)&&pointTopoint(graph->edegs[search].end,endpoint,final_end,graph)!=-1)
            {
                min=graph->edegs[search].weight+pointTopoint(graph->edegs[search].end,endpoint,final_end,graph);
            }
        }
        search=graph->edegs[search].next;
    }
    return min;
}

int get_min_time(int n, int startpoint, graph *graph)
{
    //TODO：
    int max=-1;
    for(int i=1;i<=n;i++)
    {
        if(i!=startpoint)
        {
            if(pointTopoint(startpoint,i,startpoint,graph)==-1)
            {
                max=-1;
                break;
            }
            if(max<pointTopoint(startpoint,i,startpoint,graph))
            {
                max=pointTopoint(startpoint,i,startpoint,graph);
            }
        }
    }
    return max;
}

int main()
{
    int n, m, startpoint, min_time;
    freopen("4_1_input.in", "r", stdin);
    while (scanf("%d%d%d", &n, &m, &startpoint) != EOF)
    {
        graph *g = init_graph();
        int start, end, weight;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &start, &end, &weight);
            add_edge(start, end, weight, g);
        }
        min_time = get_min_time(n, startpoint, g);
        printf("%d\n", min_time);
    }
    fclose(stdin);

}
