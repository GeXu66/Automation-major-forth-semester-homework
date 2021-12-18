#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 10020
#define maxm 200020
//ͼ�Ķ���ʹ����ʽǰ���Ƿ�ʽ����ͼ
//��Ȼ��Ҳ�������Լ��ķ�������ͼ,���ٽӾ�������ٽӱ�
#define INF 2147483647
int ans[maxn];
typedef struct Edge
{
    int start, end, weight;

    //�ñߣ�ͬһ������һ����edgs�д洢���±ꡣ��next��Ϊ��ʽѰ��ͬһ�������б�
    int next;
}edge;

typedef struct Graph
{
    edge edegs[maxm];

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
    //���ս���洢��ȫ�ֱ���ans��
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
        //���������ȫ�ֱ���ans������
        forward_propagation(n_total, n_input, n_output, input, g);

        for (int i = n_total - n_output + 1; i <= n_total; i++)
        {
            printf(i < n_total ? "%d " : "%d\n", ans[i]);
        }
    }
    fclose(stdin);
    return 0;
}
