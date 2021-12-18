#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10020
#define maxm 200020
//图的定义使用链式前向星方式构建图
//当然你也可以用自己的方法构建图,如临接矩阵或者临接表
#define INF 2147483647
int ans[maxn];
typedef struct Edge
{
    int start, end, weight;

    //该边，同一起点的上一边在edgs中存储的下标。以next作为链式寻找同一起点的所有边
    int next;
}edge;

typedef struct Graph
{
    edge edegs[maxm];

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


int Findout(int input, int output, graph *graph)
{
    if(graph->head[input]==-1)
    {
        if(input==output)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    int search=graph->head[input];
    int out=0;
    while(search!=-1)
    {
        out+=graph->edegs[search].weight*Findout(graph->edegs[search].end,output,graph);
        search=graph->edegs[search].next;
    }
    return out;
}

void forward_propagation(int n_total, int n_input, int n_output, int *input_array, graph *graph)
{
    //最终结果存储到全局变量ans中
    for (int i = n_total - n_output + 1; i <= n_total; i++)
    {
        ans[i]=0;
        for(int j=1;j<=n_input;j++)
        {
            ans[i]=ans[i]+input_array[j]*Findout(j,i,graph);
        }
    }
}

int main()
{
    int input[maxn];
    int n_total, m_total, n_input, n_output;
    freopen("4_2_input.in", "r", stdin);
    while (scanf("%d%d%d%d", &n_total, &m_total, &n_input, &n_output) != EOF)
    {
        graph *g = init_graph();
        int start, end, weight;

        for (int i = 1; i <= m_total; i++)
        {
            scanf("%d%d%d", &start, &end, &weight);
            add_edge(start, end, weight, g);
        }
        for (int i = 1; i <= n_input; i++)
        {
            scanf("%d", &input[i]);
        }
        //结果保存在全局变量ans数组中
        forward_propagation(n_total, n_input, n_output, input, g);

        for (int i = n_total - n_output + 1; i <= n_total; i++)
        {
            printf(i < n_total ? "%d " : "%d\n", ans[i]);
        }
    }
    fclose(stdin);
    return 0;
}
