#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 105

/**
 Preorder���ڴ���û������ǰ���������
 Inorder���ڴ���û�����������������
 flag���ڱ�ʾ��ǰ�����������������������ܷ񹹽���һ��Ψһ������.
 */
char Preorder[MAX];
char Inorder[MAX];
int flag = 1;
int mirror_or_not = 0;
int place=0;


// �������ڵ�Ľṹ��
typedef struct BtreeNode
{
    char data;
    struct BtreeNode *lchild;
    struct BtreeNode *rchild;
} Btree;


// �������������н���������
Btree * createBTree(char *parent)
{
    Btree *root;
    if(*(parent+place) == '#')
    {
        place++;
        return NULL;
    }
    root=(Btree *)malloc(sizeof(Btree));
    root->data = *(parent+place);
    place++; //������һ��data
    root->lchild = createBTree(parent);   //�ݹ���ô�������
    root->rchild = createBTree(parent);   //�ݹ���ô����Һ���
    return root;
}


// ����������ڵ���
int nodesOfTree(Btree * T)
{
    int n;
    if(T==NULL)
        return 0;
    else
    {
        n = nodesOfTree(T->lchild) + nodesOfTree(T->rchild) + 1;  //�ݹ����ֱ��TΪNULL
        return n;
    }
}


// ���������к��������й���������
Btree* build (char *Preorder, char *Inorder, int len)
{
    Btree *branch;
    char *p;
    if(len <= 0)
        return NULL;
    branch = (Btree*)malloc(sizeof(Btree));
    branch->data = *Preorder;

    //�������������ҵ����ڵ�
    for(p=Inorder; p<Inorder+len; p++)
    {
        if(*p == *Preorder)
            break;
    }
    int left = p-Inorder;   //ͳ�Ƹ��ڵ���������ڵ���in=0,p=���ڵ��±�
    branch->lchild = build(Preorder+1,Inorder,left);
    branch->rchild = build(Preorder+left+1,p+1,len-left-1);
    return branch;
}

// �ж϶������Ƿ���Գ�
int isSymmetric(Btree *t1, Btree *t2)
{
    //����޷���ȷ���������������
    if(mirror_or_not == 1)
        return 0;

    if(t1==NULL && t2==NULL)
        return 1;
    //�Ƚ�t2���Һ����Ƿ���ͬ
    return ((*t1).data == (*t2).data) && (isSymmetric((*t1).rchild, (*t2).lchild)) && (isSymmetric((*t1).lchild, (*t2).rchild));
}


//�ж����ַ������е��ַ��Ƿ���ͬ
int isTheSame(int len, char Preorder[MAX], char Inorder[MAX])
{
    int flag = 0;
    if(len != 0)
    {
        for(int i=0 ; i<len ; i++)
        {
            for(int j=0 ; j<len ; j++)
            {
                if(Preorder[i] == Inorder[j])
                    flag = 1;
                if (flag == 1)
                    break;
            }
            if(!flag)
            {
                printf("This pre-order traversal and mid-order traversal cannot construct a binary tree!\n");
                return NULL;
            }
        }
    }
    return 0;
}

//�жϿɷ�����û������ǰ������򴴽���
Btree* check()
{
    //
    memset(Preorder, 0, sizeof(Preorder));
    memset(Inorder, 0, sizeof(Inorder));
    Btree* p=NULL;
    int i,j;
    printf("Please input the PREORDER sequence:\n");
    //����ǰ������
    for(i=0; i<MAX; i++)
    {
        scanf("%c",Preorder+i);
        if(Preorder[i]=='\n')
            break;
    }
    //������������
    printf("Please input the INORDER sequence:\n");
    for(j=0; j<MAX; j++)
    {
        scanf("%c",Inorder+j);
        if(Inorder[j]=='\n')
            break;
    }
    //�����߳��Ȳ����
    if(i != j)
    {
        printf("This pre-order traversal and mid-order traversal cannot construct a binary tree!\n");
        return NULL;
    }

    int len = i;
    //������Ϊ��
    if(!len)
        return NULL;
    //�ж����������õ����ַ��Ƿ���ͬ
    int flag = isTheSame(len, Preorder, Inorder);

    if(flag)
        p = build(Preorder, Inorder, len); //������
    //��Գ��ȣ��ַ���ͬ�������д�������
    if(nodesOfTree(p) != len)
    {
        printf("This pre-order traversal and mid-order traversal cannot construct a binary tree!\n");
        mirror_or_not = 1;
        return NULL;
    }
    return p;
}


// ������������
int depthOfTree(Btree * T)
{
    int left, right;
    if (T == NULL)
        return 0;
    else
    {
        left = depthOfTree(T->lchild);  //�ݹ��������������ȼ�Ϊm
        right = depthOfTree(T->rchild);     //�ݹ��������������ȼ�Ϊn
        return left>right?left+1:right+1;
    }
}


// ������빹����������������ٽڵ�
int nodesToCompleteBTree(Btree * T)
{
    int k=1;
    int nodes=nodesOfTree(T);
    int depth=depthOfTree(T);
    for(int i=0; i<depth; i++)
    {
        k=k*2;
    }
    return k-nodes-1;
}


// ������ǰ�����
int PreOrderTravel(Btree *T)
{

    if(T==NULL)
    {
        return 0;
    }
    printf("%c",T->data);
    PreOrderTravel(T->lchild);
    PreOrderTravel(T->rchild);
    return 0;
}


// �������������
int InOrderTravel(Btree *T)
{
    if(T==NULL)
    {
        return 0;
    }
    InOrderTravel(T->lchild);
    printf("%c",T->data);
    InOrderTravel(T->rchild);
    return 0;
}

// �������������
int PostOrderTravel(Btree *T)
{
    if(T==NULL)
    {
        return 0;
    }
    PostOrderTravel(T->lchild);
    PostOrderTravel(T->rchild);
    printf("%c",T->data);
    return 0;
}



void task_1()
{
    printf("\t\t\t\tStart task (1)\n\n");
    printf("************  Create binary tree by SPECIAL PREORDER sequence  ************\n\n");
    printf("Please input the SPECIAL PREORDER sequence:\n");

    scanf("%s",Preorder);   //�����û������ǰ������

    Btree * bt1 = createBTree(Preorder);
    printf("The inorder sequence of binary tree is: ");
    InOrderTravel(bt1);
    printf("\nThe postorder sequence of binary tree is: ");
    PostOrderTravel(bt1);
    printf("\nThe depth of bt1 is: %d.", depthOfTree(bt1));
    printf("\nThe nodes to complete binary tree are: %d.", nodesToCompleteBTree(bt1));
    getchar();
    //�����������򷵻غ���
    printf("\n\n******  Create binary tree by PREORDER sequence and INORDER sequence  ******\n");
    Btree* bt2 = check();

    printf("The postorder sequence of binary tree is: ");
    PostOrderTravel(bt2);

    // ���ض�����������
    printf("\nThe depth of bt2 is: %d.", depthOfTree(bt2));
    printf("\nThe nodes to complete binary tree are: %d.\n", nodesToCompleteBTree(bt2));

    memset(Preorder, 0, sizeof(Preorder));
    memset(Inorder, 0, sizeof(Inorder));
}

void task_2()
{
    place=0;
    printf("\t\t\t\tStart task (2)\n\n");
    printf("************  Create binary tree by SPECIAL PREORDER sequence  ************\n\n");
    printf("Please input the SPECIAL PREORDER sequence:\n");

    scanf("%s",Preorder);
    Btree * bt1 = createBTree(Preorder);
    printf("The inorder sequence of binary tree is: ");
    InOrderTravel(bt1);
    printf("\nThe postorder sequence of binary tree is: ");
    PostOrderTravel(bt1);
    getchar();
    // �ж϶������Ƿ�Ϊ����Գƽṹ
    if(isSymmetric(bt1, bt1))
    {
        printf("\nIt's mirror symmetrical.\n");
    }
    else
    {
        printf("\nNot mirror symmetrical.\n");
    }
    printf("\n\n******  Create binary tree by PREORDER sequence and INORDER sequence  ******\n");

    Btree* bt2 = check();
    printf("The postorder sequence of binary tree is: ");
    PostOrderTravel(bt2);

    // �ж϶������Ƿ�Ϊ����Գƽṹ
    if(isSymmetric(bt2, bt2))
    {
        printf("\nIt's mirror symmetrical.");
    }
    else
    {
        printf("\nNot mirror symmetrical.");
    }

    memset(Preorder, 0, sizeof(Preorder));
    memset(Inorder, 0, sizeof(Inorder));
}

int main ()
{
    task_1();
    task_2();
    return 0;
}
