#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node{
    int student_id;
    float body_temperature;
    char name[10] ;
    struct node *next;
}StudentLinkedListNode;


/* 打印单个节点,isLastNode=1时,代表该节点是本链表最后一个节点.=0代表不是最后一个节点 */
void printLinkedListNode(StudentLinkedListNode* node){
    printf("{id:%d,name:%s,body_temperature:%.1f}",node->student_id,node->name,node->body_temperature);
	if(node->next!=NULL){
        printf("->");
    }else
    {
        printf("\n");
    }

}

/* 输出该班级的体温情况 */
void ouputStudentLinkedList(StudentLinkedListNode* head){
    // 用于单个节点输出的函数printLinkedListNode已提供
    //请你实现遍历链表的逻辑
   
}

/* 依次调用ouputStudentLinkedList 函数输出两个班级的情况,此函数用于方便同学们debug查看当前链表情况 */
void ouputOneByOne(StudentLinkedListNode* heads[]){
    int i;
    for(i=0;i<2;i++){
        ouputStudentLinkedList(heads[i]);
    }
}

/** 新建一个链表node并返回 */
StudentLinkedListNode* studentLinkedListCreate(int student_id,float body_temperature, const char* name) {
    //tips:malloc的时候记得为转化为结构体指针
    //对于字符串的赋值请用strcpy函数,如strcpy(node->name,name)
    //别忘了对新建节点中的next默认值的思考
   
}

/*copy一个已有的node */
StudentLinkedListNode* studentLinkedListCopy(StudentLinkedListNode* src){
    
    StudentLinkedListNode* tempNode = studentLinkedListCreate(src->student_id,src->body_temperature,src->name);
    return tempNode;
}



/** 按照降序插入学生的体温情况,并返回链表头指针 */
StudentLinkedListNode* studentLinkedListAdd(StudentLinkedListNode* head, StudentLinkedListNode* node) {
   //链表是空的情况
   //待插入节点node体温大于head所指向的节点体温
   //待插入节点node体温小于head所指向的节点的体温

}



/* 根据姓名查询某个学生的体温情况,如果没有,请 printf("the linklist has no such node as name=%s",name) */
void seachByName(StudentLinkedListNode* head, char* name){
    //tips:字符串比较不能用node->name==name的方式,而是用strcmp(node->name,name)==0
    
}


/* 合并两个班级的体温情况,并按降序打印 */
StudentLinkedListNode* mergeLinkedLists(StudentLinkedListNode* heads[]){
    //实际中我们只要求存储两个班级信息,所以 只有heads[0],heads[1] 两个链表需要合并
    //tips:因为传入的都是指针,为了防止合并过程中影响了原来链表的存储,可以创建一个新的链表来保存合并后的节点
    //在链表node赋值的时候可以用上面提供的studentLinkedListCopy函数
    //如 node->next = temp_node 改为 node->next = studentLinkedListCopy(temp_node)
	
	//当一个链表为空时，直接返回另一个链表
	//循环把两个链表里的节点拷贝插入到新链表，注意：需要判断体温，降序插入
    
}

/* 合并两个班级的体温情况,并打印高于体温阈值的同学的信息 */
void checkLinkedLists(StudentLinkedListNode* heads[],float threshold){
     //实际中我们只要求存储两个班级信息,所以 只有heads[0],heads[1] 两个链表需要合并,并查询健康信息
    
    
}


int main(){
    StudentLinkedListNode* obj[3]={NULL};
    //StudentLinkedListNode* obj[3];
        printf("1.insert 2.search by name 3.merge 4.check 5.output the exists linkedlist \n");
        int op;
        int class;
        int index;
        int i;
        int studentid;
        float body_temperature;
        char name[10];
        StudentLinkedListNode *tempNode;
        while (scanf("%d", &op) != EOF) {
            switch (op) {
                case 1:
                    printf("How many rows of data do you need to input?\n");
                    scanf("%d",&i);
                    printf("input the i row data format as:class_id,studentid,body temperature,name\n");
                    while (i!=0){
                        scanf("%d,%d,%f,%s", &class, &studentid, &body_temperature, name);
                        tempNode = studentLinkedListCreate(studentid, body_temperature, name);
                        obj[class]=studentLinkedListAdd(obj[class], tempNode);
                        i--;
                    }
                    break;
                case 2:
                    printf("How many rows of data do you need to search by name?\n");
                    scanf("%d",&i);
                    printf("input the i row data format as:class_num,name\n");
                    while (i!=0){
                        scanf("%d,%s", &class, name);
                        seachByName(obj[class], name);
                        i--;
                    }
                    break;
                case 3:
                    tempNode = mergeLinkedLists(obj);
                    ouputStudentLinkedList(tempNode);
                    break;
                case 4:
                    printf("input the threshold \n");
                    scanf("%f", &body_temperature);
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
