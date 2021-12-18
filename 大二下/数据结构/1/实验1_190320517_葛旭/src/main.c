#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct node
{
    int student_id;
    float body_temperature;
    char name[10] ;
    struct node *next;
} StudentLinkedListNode;


/* 打印单个节点,isLastNode=1时,代表该节点是本链表最后一个节点.=0代表不是最后一个节点 */
void printLinkedListNode(StudentLinkedListNode* node)
{
    printf("{id: %d,name: %s,body_temperature: %g}\n",node->student_id,node->name,node->body_temperature);
}

/* 输出该班级的体温情况 */
void ouputStudentLinkedList(StudentLinkedListNode* head)
{
    // 用于单个节点输出的函数printLinkedListNode已提供
    //请你实现遍历链表的逻辑
    StudentLinkedListNode* p=head;
    while(p!=NULL)
    {
        printLinkedListNode(p);
        p=p->next;
    }
}

/* 依次调用ouputStudentLinkedList 函数输出两个班级的情况,此函数用于方便同学们debug查看当前链表情况 */
void ouputOneByOne(StudentLinkedListNode* heads[])
{
    int i;
    for (i = 0; i < 2; i++)
    {
        printf("Class%d :", i);
        ouputStudentLinkedList(heads[i]);
        printf("\n");
    }
}

/* 新建一个链表node并返回 */
StudentLinkedListNode* studentLinkedListCreate(int student_id,float body_temperature, const char* name)
{
    //tips:malloc的时候记得为转化为结构体指针
    //对于字符串的赋值请用strcpy函数,如strcpy(node->name,name)
    //别忘了对新建节点中的next默认值的思考
    StudentLinkedListNode* p=(StudentLinkedListNode*)malloc(sizeof(StudentLinkedListNode));
    p->student_id=student_id;
    p->body_temperature=body_temperature;
    strcpy(p->name,name);
    p->next=NULL;
    return p;
}

/*copy一个已有的node */
StudentLinkedListNode* studentLinkedListCopy(StudentLinkedListNode* src)
{
    StudentLinkedListNode* tempNode = studentLinkedListCreate(src->student_id,src->body_temperature,src->name);
    return tempNode;
}

/* 按照降序插入学生的体温情况,并返回链表头指针 */
StudentLinkedListNode* studentLinkedListAdd(StudentLinkedListNode* head, StudentLinkedListNode* node)
{
    //链表是空的情况
    //待插入节点node体温大于head所指向的节点体温
    //待插入节点node体温小于head所指向的节点的体温
    StudentLinkedListNode* temp = head;
    //判断链表为空的情况
    if (temp == NULL)
    {
        head = node;
        return head;
    }
    //如果是头插
    if (temp->body_temperature <= node->body_temperature)
    {
        node->next = head;
        head = node;
        return head;
    }
    //遍历链表
    while (temp->next != NULL)
    {
        //提前判断temp后移一位之后是否满足插入条件，以便插入节点
        if (temp->next->body_temperature <= node->body_temperature)
        {
            node->next = temp->next;
            temp->next = node;
            return head;
        }

        temp = temp->next;
    }
    //最小的话则放到末尾
    node->next=NULL;
    temp->next = node;
    return head;
}



/* 根据姓名查询某个学生的体温情况,如果没有,请 printf("the linklist has no such node as name=%s",name) */
void searchByName(StudentLinkedListNode* head, char* name)
{
    //tips:字符串比较不能用node->name==name的方式,而是用strcmp(node->name,name)==0
    StudentLinkedListNode* p;
    for(p=head; p->next!=NULL;)
    {
        if(strcmp(p->name,name)==0)
        {
            printf("this student's body temperature is %g \n",p->body_temperature);
            break;
        }
        else
        {
            p=p->next;
            if(p->next==NULL)
            {
                printf("the linklist has no such node as name=%s \n",name);
                break;
            }
        }
    }
}


/* 合并两个班级的体温情况,并按降序打印 */
StudentLinkedListNode* mergeLinkedLists(StudentLinkedListNode* heads[])
{
    //实际中我们只要求存储两个班级信息,所以 只有heads[0],heads[1] 两个链表需要合并
    //tips:因为传入的都是指针,为了防止合并过程中影响了原来链表的存储,可以创建一个新的链表来保存合并后的节点
    //在链表node赋值的时候可以用上面提供的studentLinkedListCopy函数
    //如 node->next = temp_node 改为 node->next = studentLinkedListCopy(temp_node)
    //当一个链表为空时，直接返回另一个链表
    //循环把两个链表里的节点拷贝插入到新链表，注意：需要判断体温，降序插入
    StudentLinkedListNode *p1=heads[0],*p2=heads[1],*p3=heads[2];
    while(p1&&p2)
    {
        if(p1->body_temperature>=p2->body_temperature)
        {
            p3->next=studentLinkedListCopy(p1);
            p3=p3->next;
            p1=p1->next;
        }
        else
        {
            p3->next=studentLinkedListCopy(p2);
            p3=p3->next;
            p2=p2->next;
        }
    }
    if (p1 == NULL)
    {
        p3->next = p2;
    }
    else if (p2 == NULL)
    {
        p3->next = p1;
    }
    return heads[2]->next;
}

/* 合并两个班级的体温情况,并打印高于体温阈值的同学的信息 */
void checkLinkedLists(StudentLinkedListNode* heads[],float threshold)
{
    //实际中我们只要求存储两个班级信息,所以 只有heads[0],heads[1] 两个链表需要合并,并查询健康信息
    StudentLinkedListNode *temp=mergeLinkedLists(heads);
    while (temp->next != NULL)
    {
        if (temp->body_temperature >= threshold)
        {
            printf("{Id : %d , Name : %s , Body_temperature : %g}\n", temp->student_id, temp->name, temp->body_temperature);
        }
        temp = temp->next;
    }
    printf("\n");
}


int main()
{
    StudentLinkedListNode* obj[3]= {NULL};
    obj[2]=(StudentLinkedListNode*)malloc(sizeof(StudentLinkedListNode));
    printf("1.insert 2.search by name 3.merge 4.check 5.output the exists linkedlist \n");
    int op;
    int all_data=0;
    int class_id;
    int i,ret;
    int data=0;
    int studentid;
    float body_temperature;
    char name[10];
    StudentLinkedListNode *tempNode;
    while (scanf("%d", &op) != EOF)
    {
        switch (op)
        {
        case 1:
            //清除缓冲区
            fflush(stdin);
            printf("How many rows of data do you need to input?\n");
            while(1)
            {
                ret=scanf("%d",&i);
                if(i<=0||ret!=1)
                {
                    printf("input wrong!please input again!");
                    continue;
                }
                else break;
            }
            //用all_data保存全部的数据项数目，以便做输入检测
            all_data=i;
            fflush(stdin);
            printf("input the %d row data format as:class_id,studentid,body temperature,name\n",i);
            while (i != 0)
            {
                data = scanf("%d,%d,%g,%s", &class_id, &studentid, &body_temperature, name);
                //若scanf返回值不等于4，则说明输入错误,清除缓冲区
                if (data != 4)
                {
                    printf("Input Wrong!!Please input again\n");
                    fflush(stdin);
                    i++;
                }
                tempNode = studentLinkedListCreate(studentid, body_temperature, name);
                obj[class_id] = studentLinkedListAdd(obj[class_id], tempNode);
                i--;
            }
            break;
        case 2:
            printf("How many rows of data do you need to search by name?\n");
            while(1)
            {
                scanf("%d",&i);
                fflush(stdin);
                //判断寻找索引是否非法
                if(i>all_data||i<=0)
                {
                    printf("invalid search!please input again!");
                    fflush(stdin);
                }
                else break;
            }

            printf("input the %d row data format as:class_num,name\n",i);
            while (i!=0)
            {
                scanf("%d,%s", &class_id, name);
                fflush(stdin);
                //判断寻找的班级号是否合法
                if(class_id>1||class_id<0)
                {
                    printf("input class_id is invalid!please input again!\n");
                    continue;
                }
                searchByName(obj[class_id], name);
                i--;
            }
            break;
        case 3:
            tempNode = mergeLinkedLists(obj);
            ouputStudentLinkedList(tempNode);
            break;
        case 4:
            printf("input the threshold \n");
            scanf("%g", &body_temperature);
            checkLinkedLists(obj, body_temperature);
            break;
        case 5:
            ouputOneByOne(obj);
            break;
        default:
            return 0;
        }
        printf("###################################\n");
        printf("1.insert 2.search by name 3.merge 4.check 5.output the exists linkedlist \n");
    }
}
