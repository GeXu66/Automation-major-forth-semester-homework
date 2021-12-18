#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StackNode
{
    /** 栈中存储的节点 */
    int id;
    struct StackNode *Next;
    /** 可自由添加需要用的变量 */
} StackNode;

typedef struct LinkStack
{
    /** 栈 */
    StackNode* top;
    int size;
    /** 可自由添加需要的变量 */
} LinkStack;

LinkStack* InitStack()//初始化栈
{
    /** 初始化栈 */
    LinkStack* linkStack = (LinkStack *)malloc(sizeof(LinkStack));
    linkStack->top = NULL;
    linkStack->size = 0;
    return linkStack;
}

int StackEmpty(LinkStack *linkStack)//判断栈是否为空
{
    /** 判断栈是否为空 */
    return (linkStack->size == 0);
}

int Push(LinkStack *linkStack,int ele)//压栈
{
    /** 将一个节点压入栈 */
    StackNode* stacknode=(StackNode*)malloc(sizeof(StackNode));
    stacknode->id=ele;
    stacknode->Next=linkStack->top;
    linkStack->top=stacknode;
    linkStack->size++;
    return 1; //可删除
}

int Pop(LinkStack* linkStack)//弹出栈首元素
{
    /** 将一个节点弹出栈 */
    StackNode* stacknode=NULL;
    if(StackEmpty(linkStack)) return -1;
    stacknode=linkStack->top;
    linkStack->top=stacknode->Next;
    linkStack->size--;
    free(stacknode);
    return 1; //可删除
}

int GetTop(LinkStack* linkStack)//返回栈顶端元素
{
    /** 若栈不空，返回栈的栈顶元素 */
    if(!StackEmpty(linkStack))
    {
        return linkStack->top->id;
    }
    else return -1; //可删除
}

int StackLength(LinkStack* linkStack)//返回栈的长度
{
    /** 返回栈的长度 */
    return linkStack->size;
}

int SeqLegal(int in[],int out[],int num)//判断是否能由输入的火车序列得到输出的火车序列
{
    /** 实验内容1:判断输入的出站序列是否可由输入的进站序列通过进出栈得到
     可行返回1，不可行返回0
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
    else return 0; //可删除
}

typedef struct QueueNode
{
    /** 队列节点 */
    int id;
    struct QueueNode* next;
} QueueNode;

typedef struct Queue
{
    /** 队列 */
    QueueNode *front;
    QueueNode *rear;
    int size;
} LinkQueue;

LinkQueue* InitQueue()//初始化队列
{
    /** 初始化队列 */
    LinkQueue* linkQueue = (LinkQueue*) malloc(sizeof(LinkQueue));
    linkQueue->front = linkQueue->rear = (QueueNode *)malloc(sizeof(QueueNode));
    linkQueue->front->next = NULL;
    linkQueue -> size = 0;
    return linkQueue;
}

int QueueEmpty(LinkQueue* linkQueue)//判断队列是否为空
{
    /** 判断队列是否为空 */
    return (linkQueue->front == linkQueue->rear);
}

int EnQueue(LinkQueue *linkQueue,int ele)//进入队列
{
    /** 入队 */
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    linkQueue->rear->next  = newNode;
    newNode->next = NULL;
    linkQueue->rear = newNode;
    newNode->id = ele;
    linkQueue->size++;
    return 1;//可删除
}

int DeQueue(LinkQueue *linkQueue)//出队列
{
    /** 出队 */
    if (linkQueue->front == linkQueue->rear)
    {
        return 0;
    }
    linkQueue->front->next = linkQueue->front->next->next;
    linkQueue->size--;
    return 1;//可删除
}

int QueueLength(LinkQueue *linkQueue)//返回队列长度
{
    /** 队列长度 */
    int num = 0;
    QueueNode* temp = linkQueue->front->next;
    while (temp != linkQueue->rear)
    {
        num++;
        temp = temp->next;
    }
    return num;
}

int GetHead(LinkQueue *linkQueue,int* ele)//返回队列头部元素
{
    /** 返回队头 */
    if (linkQueue->front == linkQueue->rear)
    {
        return 0;
    }
    int p = linkQueue->front->next->id;
    return p;
}

int GetRear(LinkQueue *linkQueue)//返回队列尾部元素
{
    /** 返回队尾 */
    if (QueueEmpty(linkQueue))
    {
        return 0;
    }
    int p = linkQueue->rear->id;
    return p;
}

int findClosestQueue(LinkQueue *railQueue[],int usedQueue,int curTrain)//找到最适合的缓冲车道
{
    int closestIdx = -1;  //最合适的轨道初始化为-1
    int rearId;  //队尾元素
    int* diff = (int*)malloc(sizeof(int) * usedQueue);  //记录当前火车序号与每个轨道队尾火车序号的差值
    for (int i = 0; i < usedQueue; i++)  //遍历每个使用过的轨道
    {
        if (curTrain > GetRear(railQueue[i]))  //当前火车序号大于队尾火车序号
        {
            rearId = GetRear(railQueue[i]);
            diff[i] = curTrain - rearId;  //记录两车的序号差值
        }
        else
        {
            diff[i] = 0;  //将差值记录为0，便于求得最小差值
        }
    }
    for (int i = 0; i < usedQueue; i++)  //遍历差值数组，除0外差值记录最小的轨道为最适合轨道
    {
        if(diff[i] > 0)  //如果差值记录大于0，该轨道为候选轨道
        {
            if(closestIdx < 0)  //之前未找到最适合轨道
            {
                closestIdx = i;  //最适合轨道赋值为当前候选轨道
            }
            else   //之前已找到最适合轨道
            {
                if(diff[i] < diff[closestIdx])  //比较两个轨道的差值记录，如果当前候选轨道差值较小，将最适合轨道赋值为当前候选轨道
                {
                    closestIdx = i;
                }
            }
        }
    }
    return closestIdx;
}

int minBufferQueue(int out[],int num)//找到最少的缓冲车道
{
    /** 实验内容2:求解所需缓冲轨道的最小值*/
    LinkQueue* railQueue[num]; //指针数组，记录各缓存轨道的火车
    for (int i = 0; i < num; i++)
    {
        railQueue[i] = InitQueue();
    }
    int usedQueue = 0;      //已使用的队列数
    int option;             //选择的车道
    //分为插在现有缓冲道和开辟新缓冲道两种情况
    for (int i = 0; i < num; i++)
    {
        option = findClosestQueue(railQueue, usedQueue, out[i]);
        //加在现有缓冲道队尾
        if (option != -1)
        {
            EnQueue(railQueue[option], out[i]);
        }
        //开辟新缓冲道
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
        // 实验内容1
        if(SeqLegal(trainIn,trainOut,trainNum))
        {
            printf("The output train sequence is Possible\n");
        }
        else
        {
            printf("The output train sequence is impossible\n");
        }
        // 实验内容2
        printf("To recover the order, %d buffer queue is needed:\n",minBufferQueue(trainOut, trainNum));

    }
    fclose(stdin);
    return 0;
}
