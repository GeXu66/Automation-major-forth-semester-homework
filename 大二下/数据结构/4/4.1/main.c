#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10020
#define maxm 200020
//ͼ�Ķ���ʹ����ʽǰ���Ƿ�ʽ����ͼ
//��Ȼ��Ҳ�������Լ��ķ�������ͼ,���ٽӾ�������ٽӱ�
#define INF 2147483630
int ans[maxn];
typedef struct Edge
{
    int start, end, weight;
    //�ñߣ�ͬһ������һ����edgs�д洢���±ꡣ��next��Ϊ��ʽѰ��ͬһ�������б�
    int next;
}edge;

typedef struct Graph
{
    struct Edge edegs[maxm];
    //head[i] ��¼������iΪ���ı߼��е�һ������edges�е�index,
    int head[maxn];
    //��ǰ�ڼ�����
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
    //�ṩ���ִ洢�ӱ߷�ʽ
    graph->edegs[++graph->tot].start = start;
    graph->edegs[graph->tot].end = end;
    graph->edegs[graph->tot].weight = weight;

    //��ʽǰ���Ǵ洢��ÿ��һ���ߵ�ʱ��ͬһ���ı���next������ʽ�洢
    graph->edegs[graph->tot].next = graph->head[start];
    graph->head[start] = graph->tot;
}

void visit_graph(int n, graph *graph)
{
    //debug �������ṩ���ִ洢��ʽ�ı������̣�����ͬѧ��debug
    for (int i = 1; i <= n; i++) //n�����
    {
        printf("start with %d\n", i);
        for (int j = graph->head[i]; j != -1; j = graph->edegs[j].next) //������iΪ���ı�
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
        else if(graph->edegs[search].end!=final_end)//��������Ӱ��
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
    //TODO��
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
