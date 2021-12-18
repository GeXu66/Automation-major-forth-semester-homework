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


/* ��ӡ�����ڵ�,isLastNode=1ʱ,����ýڵ��Ǳ��������һ���ڵ�.=0���������һ���ڵ� */
void printLinkedListNode(StudentLinkedListNode* node)
{
    printf("{id: %d,name: %s,body_temperature: %g}\n",node->student_id,node->name,node->body_temperature);
}

/* ����ð༶��������� */
void ouputStudentLinkedList(StudentLinkedListNode* head)
{
    // ���ڵ����ڵ�����ĺ���printLinkedListNode���ṩ
    //����ʵ�ֱ���������߼�
    StudentLinkedListNode* p=head;
    while(p!=NULL)
    {
        printLinkedListNode(p);
        p=p->next;
    }
}

/* ���ε���ouputStudentLinkedList ������������༶�����,�˺������ڷ���ͬѧ��debug�鿴��ǰ������� */
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

/* �½�һ������node������ */
StudentLinkedListNode* studentLinkedListCreate(int student_id,float body_temperature, const char* name)
{
    //tips:malloc��ʱ��ǵ�Ϊת��Ϊ�ṹ��ָ��
    //�����ַ����ĸ�ֵ����strcpy����,��strcpy(node->name,name)
    //�����˶��½��ڵ��е�nextĬ��ֵ��˼��
    StudentLinkedListNode* p=(StudentLinkedListNode*)malloc(sizeof(StudentLinkedListNode));
    p->student_id=student_id;
    p->body_temperature=body_temperature;
    strcpy(p->name,name);
    p->next=NULL;
    return p;
}

/*copyһ�����е�node */
StudentLinkedListNode* studentLinkedListCopy(StudentLinkedListNode* src)
{
    StudentLinkedListNode* tempNode = studentLinkedListCreate(src->student_id,src->body_temperature,src->name);
    return tempNode;
}

/* ���ս������ѧ�����������,����������ͷָ�� */
StudentLinkedListNode* studentLinkedListAdd(StudentLinkedListNode* head, StudentLinkedListNode* node)
{
    //�����ǿյ����
    //������ڵ�node���´���head��ָ��Ľڵ�����
    //������ڵ�node����С��head��ָ��Ľڵ������
    StudentLinkedListNode* temp = head;
    //�ж�����Ϊ�յ����
    if (temp == NULL)
    {
        head = node;
        return head;
    }
    //�����ͷ��
    if (temp->body_temperature <= node->body_temperature)
    {
        node->next = head;
        head = node;
        return head;
    }
    //��������
    while (temp->next != NULL)
    {
        //��ǰ�ж�temp����һλ֮���Ƿ���������������Ա����ڵ�
        if (temp->next->body_temperature <= node->body_temperature)
        {
            node->next = temp->next;
            temp->next = node;
            return head;
        }

        temp = temp->next;
    }
    //��С�Ļ���ŵ�ĩβ
    node->next=NULL;
    temp->next = node;
    return head;
}



/* ����������ѯĳ��ѧ�����������,���û��,�� printf("the linklist has no such node as name=%s",name) */
void searchByName(StudentLinkedListNode* head, char* name)
{
    //tips:�ַ����Ƚϲ�����node->name==name�ķ�ʽ,������strcmp(node->name,name)==0
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


/* �ϲ������༶���������,���������ӡ */
StudentLinkedListNode* mergeLinkedLists(StudentLinkedListNode* heads[])
{
    //ʵ��������ֻҪ��洢�����༶��Ϣ,���� ֻ��heads[0],heads[1] ����������Ҫ�ϲ�
    //tips:��Ϊ����Ķ���ָ��,Ϊ�˷�ֹ�ϲ�������Ӱ����ԭ������Ĵ洢,���Դ���һ���µ�����������ϲ���Ľڵ�
    //������node��ֵ��ʱ������������ṩ��studentLinkedListCopy����
    //�� node->next = temp_node ��Ϊ node->next = studentLinkedListCopy(temp_node)
    //��һ������Ϊ��ʱ��ֱ�ӷ�����һ������
    //ѭ��������������Ľڵ㿽�����뵽������ע�⣺��Ҫ�ж����£��������
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

/* �ϲ������༶���������,����ӡ����������ֵ��ͬѧ����Ϣ */
void checkLinkedLists(StudentLinkedListNode* heads[],float threshold)
{
    //ʵ��������ֻҪ��洢�����༶��Ϣ,���� ֻ��heads[0],heads[1] ����������Ҫ�ϲ�,����ѯ������Ϣ
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
            //���������
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
            //��all_data����ȫ������������Ŀ���Ա���������
            all_data=i;
            fflush(stdin);
            printf("input the %d row data format as:class_id,studentid,body temperature,name\n",i);
            while (i != 0)
            {
                data = scanf("%d,%d,%g,%s", &class_id, &studentid, &body_temperature, name);
                //��scanf����ֵ������4����˵���������,���������
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
                //�ж�Ѱ�������Ƿ�Ƿ�
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
                //�ж�Ѱ�ҵİ༶���Ƿ�Ϸ�
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
