#include<math.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 105

/**
 Preorder用于存放用户输入的前序遍历序列
 Inorder用于存放用户输入的中序遍历序列
 flag用于表示由前序遍历序列与中序遍历序列能否构建出一棵唯一二叉树.
 */
char Preorder[MAX];
char Inorder[MAX];
int flag = 1;
int mirror_or_not = 0;
int place=0;


// 定义树节点的结构体
typedef struct BtreeNode
{
    char data;
    struct BtreeNode *lchild;
    struct BtreeNode *rchild;
} Btree;


// 由特殊先序序列建立二叉树
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
    place++; //接受下一个data
    root->lchild = createBTree(parent);   //递归调用创建左孩子
    root->rchild = createBTree(parent);   //递归调用创建右孩子
    return root;
}


// 计算二叉树节点数
int nodesOfTree(Btree * T)
{
    int n;
    if(T==NULL)
        return 0;
    else
    {
        n = nodesOfTree(T->lchild) + nodesOfTree(T->rchild) + 1;  //递归调用直到T为NULL
        return n;
    }
}


// 由先序序列和中序序列构建二叉树
Btree* build (char *Preorder, char *Inorder, int len)
{
    Btree *branch;
    char *p;
    if(len <= 0)
        return NULL;
    branch = (Btree*)malloc(sizeof(Btree));
    branch->data = *Preorder;

    //在中序序列中找到根节点
    for(p=Inorder; p<Inorder+len; p++)
    {
        if(*p == *Preorder)
            break;
    }
    int left = p-Inorder;   //统计根节点的左子树节点数in=0,p=根节点下标
    branch->lchild = build(Preorder+1,Inorder,left);
    branch->rchild = build(Preorder+left+1,p+1,len-left-1);
    return branch;
}

// 判断二叉树是否镜像对称
int isSymmetric(Btree *t1, Btree *t2)
{
    //针对无法正确创建二叉树的情况
    if(mirror_or_not == 1)
        return 0;

    if(t1==NULL && t2==NULL)
        return 1;
    //比较t2左右孩子是否相同
    return ((*t1).data == (*t2).data) && (isSymmetric((*t1).rchild, (*t2).lchild)) && (isSymmetric((*t1).lchild, (*t2).rchild));
}


//判断两字符串含有的字符是否相同
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

//判断可否根据用户输入的前序和中序创建树
Btree* check()
{
    //
    memset(Preorder, 0, sizeof(Preorder));
    memset(Inorder, 0, sizeof(Inorder));
    Btree* p=NULL;
    int i,j;
    printf("Please input the PREORDER sequence:\n");
    //接收前序序列
    for(i=0; i<MAX; i++)
    {
        scanf("%c",Preorder+i);
        if(Preorder[i]=='\n')
            break;
    }
    //接收中序序列
    printf("Please input the INORDER sequence:\n");
    for(j=0; j<MAX; j++)
    {
        scanf("%c",Inorder+j);
        if(Inorder[j]=='\n')
            break;
    }
    //若两者长度不相等
    if(i != j)
    {
        printf("This pre-order traversal and mid-order traversal cannot construct a binary tree!\n");
        return NULL;
    }

    int len = i;
    //若长度为零
    if(!len)
        return NULL;
    //判断两个序列用到的字符是否相同
    int flag = isTheSame(len, Preorder, Inorder);

    if(flag)
        p = build(Preorder, Inorder, len); //创建树
    //针对长度，字符相同但是序列错误的情况
    if(nodesOfTree(p) != len)
    {
        printf("This pre-order traversal and mid-order traversal cannot construct a binary tree!\n");
        mirror_or_not = 1;
        return NULL;
    }
    return p;
}


// 计算二叉树深度
int depthOfTree(Btree * T)
{
    int left, right;
    if (T == NULL)
        return 0;
    else
    {
        left = depthOfTree(T->lchild);  //递归计算左子树的深度记为m
        right = depthOfTree(T->rchild);     //递归计算右子树的深度记为n
        return left>right?left+1:right+1;
    }
}


// 计算距离构造满二叉树还需多少节点
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


// 二叉树前序遍历
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


// 二叉树中序遍历
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

// 二叉树后序遍历
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

    scanf("%s",Preorder);   //接受用户输入的前序序列

    Btree * bt1 = createBTree(Preorder);
    printf("The inorder sequence of binary tree is: ");
    InOrderTravel(bt1);
    printf("\nThe postorder sequence of binary tree is: ");
    PostOrderTravel(bt1);
    printf("\nThe depth of bt1 is: %d.", depthOfTree(bt1));
    printf("\nThe nodes to complete binary tree are: %d.", nodesToCompleteBTree(bt1));
    getchar();
    //根据先序中序返回后序
    printf("\n\n******  Create binary tree by PREORDER sequence and INORDER sequence  ******\n");
    Btree* bt2 = check();

    printf("The postorder sequence of binary tree is: ");
    PostOrderTravel(bt2);

    // 返回二叉树的属性
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
    // 判断二叉树是否为镜像对称结构
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

    // 判断二叉树是否为镜像对称结构
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
