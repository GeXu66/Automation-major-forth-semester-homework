#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 105

/**
 Preorder用于存放用户输入的前序遍历序列
 Inorder用于存放用户输入的中序遍历序列
 flag用于表示由前序遍历序列与中序遍历序列能否构建出一棵唯一二叉树.
 */
char Preorder[MAX];
char Inorder[MAX];
int flag = 1;

// 定义树节点的结构体
typedef struct BtreeNode {
	char data;
	struct BtreeNode *lchild;
	struct BtreeNode *rchild;
	/* 可自由添加需要用的变量 **/
} Btree;

// 由特殊先序序列建立二叉树
Btree * createBTree() {
    /**
	函数功能：根据用户输入的特殊前序序列构造二叉树
	输入实例：ABDH##I##E##CF#J##G##
	在进行功能实现时，可根据自己的理解适当对函数进行修改。
	*/
    // Tips：
    // 该函数可以参考"树-第二部分"PPT 13页上的内容实现.
}

// 由先序序列和中序序列构建二叉树
Btree* build (char *Preorder, char *Inorder, int len) {
	/**
	函数功能：根据用户输入的前序遍历结果和中序遍历结果构造二叉树
	参数说明：Preorder前序遍历结果序列，Inorder中序遍历结果序列，len序列长度
	在进行功能实现时，可根据自己的理解适当对函数进行修改。
	*/
	// Tips：
    // 在调用该函数之前，请考虑前序遍历序列和中序遍历序列的长度以及所包含的字符是否一致。
    // 此外，该函数需要判断前序遍历与中序遍历结果是否能够构造出唯一的二叉树，若不可构造，则返回NULL!!!
}

// 计算二叉树深度
int depthOfTree(Btree * T)
{
    /**
	函数功能：计算二叉树深度
	参数说明：T 二叉树根节点
	在进行功能实现时，可根据自己的理解适当对函数进行修改。
	*/
}


// 计算二叉树节点数
int nodesOfTree(Btree * T)
{
    /**
	函数功能：计算二叉树节点数
	参数说明：T 二叉树根节点
	在进行功能实现时，可根据自己的理解适当对函数进行修改。
	*/
}

// 计算距离构造满二叉树还需多少节点
int nodesToCompleteBTree(Btree * T)
{
    /**
	函数功能：计算距离构造满二叉树还需多少节点
	参数说明：T 二叉树根节点
	在进行功能实现时，可根据自己的理解适当对函数进行修改。
	*/
    // Tips:
    // 在实现该函数时,如果需要计算二叉树节点数,可以在nodesOfTree()函数中实现.
}

// 二叉树前序遍历
void PreOrderTravel(Btree *T)
{
    /**
    函数功能：前序遍历二叉树
    参数说明：T 二叉树节点指针
    输出格式：X X X X X .....（每个节点之间以空格作为间隔）,若为空树则无需输出
    在进行功能实现时，可根据自己的理解适当对函数进行修改。
    */
}

// 二叉树中序遍历
void InOrderTravel(Btree *T)
{
    /**
    函数功能：中序遍历二叉树
    参数说明：T 二叉树根节点指针
    输出格式：X X X X X .....（每个节点之间以空格作为间隔），若为空树则无需输出
    在进行功能实现时，可根据自己的理解适当对函数进行修改。
    */
}

// 二叉树后序遍历
void PostOrderTravel(Btree *T)
{
    /**
    函数功能：后序遍历二叉树
    参数说明：T 二叉树根节点指针
    输出格式：X X X X X .....（每个节点之间以空格作为间隔），若为空树则无需输出
    在进行功能实现时，可根据自己的理解适当对函数进行修改。
    */
}


// 判断二叉树是否镜像对称
int isSymmetric(Btree *T)
{
    /**
    函数功能：判断二叉树是否结构镜像
    参数说明：T 二叉树根节点指针
    返回值：若结构镜像返回1，否则返回0
    在进行功能实现时，可根据自己的理解适当对函数进行修改。
    */
}

void task_1()
{
    printf("Start task (1)\n");
    /* 实现函数createBTree(),利用用户输入的特殊前序序列构造二叉树! */
    printf("************Create binary tree by special preorder sequence************\n");
    printf("Please input the special preorder sequence:\n");
    Btree * bt1 = createBTree();
    /* 实现函数InOrderTravel(),返回二叉树中序序列. */
    printf("The inorder sequence of binary tree is: ");
    InOrderTravel(bt1);
    /* 实现函数PostOrderTravel(),返回二叉树后序序列. */
    printf("\nThe postorder sequence of binary tree is: ");
    PostOrderTravel(bt1);
    /* 实现函数depthOfTree(),返回二叉树深度. */
    printf("\nThe depth of bt1 is: %d.", depthOfTree(bt1));
    /* 实现函数nodesToCompleteBTree(),返回将二叉树补全为满二叉树所需节点数. */
    printf("\nThe nodes to complete binary tree are: %d.", nodesToCompleteBTree(bt1));
    getchar(); // 该行代码按需注释,用于处理键入的回车字符!!!
    /* 实现函数build(),利用用户输入的由先序遍历序列和中序遍历序列构造二叉树. */
    printf("\n******Create binary tree by preorder sequence and inorder sequence******\n");
    Btree * bt2;
    int len = 0; // 二叉树前序遍历序列长度 或 二叉树后续遍历序列长度,按需保留!
    printf("Please input the preorder sequence:\n");
    /**
        补充代码，用户输入二叉树前序遍历结果！
        在输入序列中，每个字符表示一个二叉树节点所存放的数据，存放在Preorder变量中！
        输入示例：ABDECF
        该部分需要对用户的输入进行一定的判断，保证二叉树能够正确建立！
    */
    printf("Please input the inorder sequence:\n");
    /**
        补充代码，用户输入二叉树中序遍历结果！
        在输入序列中，每个字符表示一个二叉树节点所存放的数据，存放在Inorder变量中！
        输入示例：DBEACF
        该部分需要对用户的输入进行一定的判断，保证二叉树能够正确建立！
    */
    /**
        Tips：
        在该部分需要对前序遍历序列和中序遍历结果进行初步筛选，包括：长度是否一致，所含字符是否一致。
        若筛选通过，则调用build()函数；否则输出
            This pre-order traversal and mid-order traversal cannot construct a binary tree!
        并为bt2赋值为NULL。
    */
    bt2 = build(Preorder, Inorder, len);
    printf("The postorder sequence of binary tree is: ");
    PostOrderTravel(bt2);
    // 返回二叉树的属性
    printf("\nThe depth of bt2 is: %d.", depthOfTree(bt2));
    printf("\nThe nodes to complete binary tree are: %d.\n", nodesToCompleteBTree(bt2));
}

void task_2()
{
    printf("Start task (2)\n");
    /* 实现函数createBTree(),利用用户输入的特殊前序序列构造二叉树! */
    printf("************Create binary tree by special preorder sequence************\n");
    printf("Please input the special preorder sequence:\n");
    Btree * bt1 = createBTree();
    /* 实现函数InOrderTravel(),返回二叉树中序序列. */
    printf("The inorder sequence of binary tree is: ");
    InOrderTravel(bt1);
    /* 实现函数PostOrderTravel(),返回二叉树后序序列. */
    printf("\nThe postorder sequence of binary tree is: ");
    PostOrderTravel(bt1);
    getchar(); // 该行代码按需注释,用于处理键入的回车字符!!!
    /*?实现函数isSymmetric(),判断二叉树是否为镜像对称结构.?*/
    if(isSymmetric(bt1))
    {
        printf("\nIt's mirror symmetrical.\n");
    }
    else
    {
        printf("\nNot mirror symmetrical.\n");
    }
    printf("******Create binary tree by preorder sequence and inorder sequence******\n");
    Btree * bt2;
    int len = 0; // 二叉树前序遍历序列长度 或 二叉树后续遍历序列长度。 若需要可保留，不需要则注释！
    printf("Please input the preorder sequence:\n");
    /**
        补充代码，用户输入二叉树前序遍历结果！
        在输入序列中，每个字符表示一个二叉树节点所存放的数据，存放在Preorder变量中！
        输入示例：ABDECF
        该部分需要对用户的输入进行一定的判断，保证二叉树能够正确建立！
    */
    printf("Please input the inorder sequence:\n");
    /**
        补充代码，用户输入二叉树中序遍历结果！
        在输入序列中，每个字符表示一个二叉树节点所存放的数据，存放在Inorder变量中！
        输入示例：DBEACF
        该部分需要对用户的输入进行一定的判断，保证二叉树能够正确建立！
    */
    /**
        Tips：
        在该部分需要对前序遍历序列和中序遍历结果进行初步筛选，包括：长度是否一致，所含字符是否一致。
        若筛选通过，则调用build()函数；否则输出
            This pre-order traversal and mid-order traversal cannot construct a binary tree!
        并为bt2赋值为NULL。
    */
    bt2 = build(Preorder, Inorder, len);
    printf("The postorder sequence of binary tree is: ");
    PostOrderTravel(bt2);
    // 判断二叉树是否为镜像对称结构
    if(isSymmetric(bt2))
    {
        printf("\nIt's mirror symmetrical.");
    }
    else
    {
        printf("\nNot mirror symmetrical.");
    }
}

int main () {
    /* 说明：
     * 1. 规定空二叉树为镜像对称；
     * 2. 在做镜像对称时，不能利用前序、中序或后序遍历序列；
     * 3. 给出的所有输入示例均为正确的情况，请根据自己的能力自行进行程序健壮性提升；
     * 4. 若给出的函数无法满足需求，可自行适当添加函数接口，但必须注明函数用途，未使用函数可以注释掉；
     * */
     task_1();
     task_2();
     return 0;
}
