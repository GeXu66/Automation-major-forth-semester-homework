#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode
{
    /** ջ�д洢�Ľڵ� */
    int id;
    struct StackNode *Next;
    /** �����������Ҫ�õı��� */
} StackNode;

typedef struct LinkStack
{
    /** ջ */
    StackNode* top;
    int size;
    /** �����������Ҫ�ı��� */
} LinkStack;

LinkStack* InitStack()//��ʼ��ջ
{
    /** ��ʼ��ջ */
    LinkStack* linkStack = (LinkStack *)malloc(sizeof(LinkStack));
    linkStack->top = NULL;
    linkStack->size = 0;
    return linkStack;
}

int StackEmpty(LinkStack *linkStack)//�ж�ջ�Ƿ�Ϊ��
{
    /** �ж�ջ�Ƿ�Ϊ�� */
    return (linkStack->size == 0);
}

int Push(LinkStack *linkStack,int ele)//ѹջ
{
    /** ��һ���ڵ�ѹ��ջ */
    StackNode* stacknode=(StackNode*)malloc(sizeof(StackNode));
    stacknode->id=ele;
    stacknode->Next=linkStack->top;
    linkStack->top=stacknode;
    linkStack->size++;
    return 1; //��ɾ��
}

int Pop(LinkStack* linkStack)//����ջ��Ԫ��
{
    /** ��һ���ڵ㵯��ջ */
    StackNode* stacknode=NULL;
    if(StackEmpty(linkStack)) return -1;
    stacknode=linkStack->top;
    linkStack->top=stacknode->Next;
    linkStack->size--;
    free(stacknode);
    return 1; //��ɾ��
}

int GetTop(LinkStack* linkStack)//����ջ����Ԫ��
{
    /** ��ջ���գ�����ջ��ջ��Ԫ�� */
    if(!StackEmpty(linkStack))
    {
        return linkStack->top->id;
    }
    else return -1; //��ɾ��
}

int StackLength(LinkStack* linkStack)//����ջ�ĳ���
{
    /** ����ջ�ĳ��� */
    return linkStack->size;
}

int SeqLegal(int in[],int out[],int num)//�ж��Ƿ���������Ļ����еõ�����Ļ�����
{
    /** ʵ������1:�ж�����ĳ�վ�����Ƿ��������Ľ�վ����ͨ������ջ�õ�
     ���з���1�������з���0
     */
    int i,j;
    LinkStack* stack=InitStack();
    for(i=0,j=0; i<num; i++)
    {
        Push(stack,in[i]);
        while(stack->size!=0)
        {
            if(stack->top->id==out[j])
            {
                Pop(stack);
                j++;
            }
            else break;
        }

    }
    if(stack->size==0)
    {
        return 1;
    }
    else return 0; //��ɾ��
}

typedef struct QueueNode
{
    /** ���нڵ� */
    int id;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue
{
    /** ���� */
    QueueNode *front;
    QueueNode *rear;
    int size;
} LinkQueue;

LinkQueue* InitQueue()//��ʼ������
{
    /** ��ʼ������ */
    LinkQueue* linkQueue = (LinkQueue*) malloc(sizeof(LinkQueue));
    linkQueue->front = linkQueue->rear = (QueueNode *)malloc(sizeof(QueueNode));
    linkQueue->front->next = NULL;
    linkQueue -> size = 0;
    return linkQueue;
}

int QueueEmpty(LinkQueue* linkQueue)//�ж϶����Ƿ�Ϊ��
{
    /** �ж϶����Ƿ�Ϊ�� */
    return (linkQueue->front == linkQueue->rear);
}

int EnQueue(LinkQueue *linkQueue,int ele)//�������
{
    /** ��� */
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    linkQueue->rear->next  = newNode;
    newNode->next = NULL;
    linkQueue->rear = newNode;
    newNode->id = ele;
    linkQueue->size++;
    return 1;//��ɾ��
}

int DeQueue(LinkQueue *linkQueue)//������
{
    /** ���� */
    if (linkQueue->front == linkQueue->rear)
    {
        return 0;
    }
    linkQueue->front->next = linkQueue->front->next->next;
    linkQueue->size--;
    return 1;//��ɾ��
}

int QueueLength(LinkQueue *linkQueue)//���ض��г���
{
    /** ���г��� */
    int num = 0;
    QueueNode* temp = linkQueue->front->next;
    while (temp != linkQueue->rear)
    {
        num++;
        temp = temp->next;
    }
    return num;
}

int GetHead(LinkQueue *linkQueue,int* ele)//���ض���ͷ��Ԫ��
{
    /** ���ض�ͷ */
    if (linkQueue->front == linkQueue->rear)
    {
        return 0;
    }
    int p = linkQueue->front->next->id;
    return p;
}

int GetRear(LinkQueue *linkQueue)//���ض���β��Ԫ��
{
    /** ���ض�β */
    if (QueueEmpty(linkQueue))
    {
        return 0;
    }
    int p = linkQueue->rear->id;
    return p;
}

int findClosestQueue(LinkQueue *railQueue[],int usedQueue,int curTrain)//�ҵ����ʺϵĻ��峵��
{
    int closestIdx = -1;  //����ʵĹ����ʼ��Ϊ-1
    int rearId;  //��βԪ��
    int* diff = (int*)malloc(sizeof(int) * usedQueue);  //��¼��ǰ�������ÿ�������β����ŵĲ�ֵ
    for (int i = 0; i < usedQueue; i++)  //����ÿ��ʹ�ù��Ĺ��
    {
        if (curTrain > GetRear(railQueue[i]))  //��ǰ����Ŵ��ڶ�β�����
        {
            rearId = GetRear(railQueue[i]);
            diff[i] = curTrain - rearId;  //��¼��������Ų�ֵ
        }
        else
        {
            diff[i] = 0;  //����ֵ��¼Ϊ0�����������С��ֵ
        }
    }
    for (int i = 0; i < usedQueue; i++)  //������ֵ���飬��0���ֵ��¼��С�Ĺ��Ϊ���ʺϹ��
    {
        if(diff[i] > 0)  //�����ֵ��¼����0���ù��Ϊ��ѡ���
        {
            if(closestIdx < 0)  //֮ǰδ�ҵ����ʺϹ��
            {
                closestIdx = i;  //���ʺϹ����ֵΪ��ǰ��ѡ���
            }
            else   //֮ǰ���ҵ����ʺϹ��
            {
                if(diff[i] < diff[closestIdx])  //�Ƚ���������Ĳ�ֵ��¼�������ǰ��ѡ�����ֵ��С�������ʺϹ����ֵΪ��ǰ��ѡ���
                {
                    closestIdx = i;
                }
            }
        }
    }
    return closestIdx;
}

int minBufferQueue(int out[],int num)//�ҵ����ٵĻ��峵��
{
    /** ʵ������2:������軺��������Сֵ*/
    LinkQueue* railQueue[num]; //ָ�����飬��¼���������Ļ�
    for (int i = 0; i < num; i++)
    {
        railQueue[i] = InitQueue();
    }
    int usedQueue = 0;      //��ʹ�õĶ�����
    int option;             //ѡ��ĳ���
    //��Ϊ�������л�����Ϳ����»�����������
    for (int i = 0; i < num; i++)
    {
        option = findClosestQueue(railQueue, usedQueue, out[i]);
        //�������л������β
        if (option != -1)
        {
            EnQueue(railQueue[option], out[i]);
        }
        //�����»����
        else
        {
            EnQueue(railQueue[usedQueue], out[i]);
            usedQueue++;
        }
    }
    return usedQueue;
}

int main()
{

    int trainNum;
    int count = 0;
    freopen("Train.in", "r", stdin);

    while(scanf("%d",&trainNum)!=EOF)
    {
        count++;
        int trainIn[trainNum];
        int trainOut[trainNum];
        for(int i = 0; i < trainNum; i++)
        {
            scanf("%d",&trainIn[i]);
        }
        for(int i = 0; i < trainNum; i++)
        {
            scanf("%d",&trainOut[i]);
        }
        printf("====Case %d====\n",count);
        // ʵ������1
        if(SeqLegal(trainIn,trainOut,trainNum))
        {
            printf("The output train sequence is Possible\n");
        }
        else
        {
            printf("The output train sequence is impossible\n");
        }
        // ʵ������2
        printf("To recover the order, %d buffer queue is needed:\n",minBufferQueue(trainOut, trainNum));

    }
    fclose(stdin);
    return 0;
}
