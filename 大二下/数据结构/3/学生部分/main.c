#include<math.h>
#include<stdio.h>
#include<stdlib.h>

#define MAX 105

/**
 Preorder���ڴ���û������ǰ���������
 Inorder���ڴ���û�����������������
 flag���ڱ�ʾ��ǰ�����������������������ܷ񹹽���һ��Ψһ������.
 */
char Preorder[MAX];
char Inorder[MAX];
int flag = 1;

// �������ڵ�Ľṹ��
typedef struct BtreeNode {
	char data;
	struct BtreeNode *lchild;
	struct BtreeNode *rchild;
	/* �����������Ҫ�õı��� **/
} Btree;

// �������������н���������
Btree * createBTree() {
    /**
	�������ܣ������û����������ǰ�����й��������
	����ʵ����ABDH##I##E##CF#J##G##
	�ڽ��й���ʵ��ʱ���ɸ����Լ�������ʵ��Ժ��������޸ġ�
	*/
    // Tips��
    // �ú������Բο�"��-�ڶ�����"PPT 13ҳ�ϵ�����ʵ��.
}

// ���������к��������й���������
Btree* build (char *Preorder, char *Inorder, int len) {
	/**
	�������ܣ������û������ǰ�����������������������������
	����˵����Preorderǰ�����������У�Inorder�������������У�len���г���
	�ڽ��й���ʵ��ʱ���ɸ����Լ�������ʵ��Ժ��������޸ġ�
	*/
	// Tips��
    // �ڵ��øú���֮ǰ���뿼��ǰ��������к�����������еĳ����Լ����������ַ��Ƿ�һ�¡�
    // ���⣬�ú�����Ҫ�ж�ǰ������������������Ƿ��ܹ������Ψһ�Ķ������������ɹ��죬�򷵻�NULL!!!
}

// ������������
int depthOfTree(Btree * T)
{
    /**
	�������ܣ�������������
	����˵����T ���������ڵ�
	�ڽ��й���ʵ��ʱ���ɸ����Լ�������ʵ��Ժ��������޸ġ�
	*/
}


// ����������ڵ���
int nodesOfTree(Btree * T)
{
    /**
	�������ܣ�����������ڵ���
	����˵����T ���������ڵ�
	�ڽ��й���ʵ��ʱ���ɸ����Լ�������ʵ��Ժ��������޸ġ�
	*/
}

// ������빹����������������ٽڵ�
int nodesToCompleteBTree(Btree * T)
{
    /**
	�������ܣ�������빹����������������ٽڵ�
	����˵����T ���������ڵ�
	�ڽ��й���ʵ��ʱ���ɸ����Լ�������ʵ��Ժ��������޸ġ�
	*/
    // Tips:
    // ��ʵ�ָú���ʱ,�����Ҫ����������ڵ���,������nodesOfTree()������ʵ��.
}

// ������ǰ�����
void PreOrderTravel(Btree *T)
{
    /**
    �������ܣ�ǰ�����������
    ����˵����T �������ڵ�ָ��
    �����ʽ��X X X X X .....��ÿ���ڵ�֮���Կո���Ϊ�����,��Ϊ�������������
    �ڽ��й���ʵ��ʱ���ɸ����Լ�������ʵ��Ժ��������޸ġ�
    */
}

// �������������
void InOrderTravel(Btree *T)
{
    /**
    �������ܣ��������������
    ����˵����T ���������ڵ�ָ��
    �����ʽ��X X X X X .....��ÿ���ڵ�֮���Կո���Ϊ���������Ϊ�������������
    �ڽ��й���ʵ��ʱ���ɸ����Լ�������ʵ��Ժ��������޸ġ�
    */
}

// �������������
void PostOrderTravel(Btree *T)
{
    /**
    �������ܣ��������������
    ����˵����T ���������ڵ�ָ��
    �����ʽ��X X X X X .....��ÿ���ڵ�֮���Կո���Ϊ���������Ϊ�������������
    �ڽ��й���ʵ��ʱ���ɸ����Լ�������ʵ��Ժ��������޸ġ�
    */
}


// �ж϶������Ƿ���Գ�
int isSymmetric(Btree *T)
{
    /**
    �������ܣ��ж϶������Ƿ�ṹ����
    ����˵����T ���������ڵ�ָ��
    ����ֵ�����ṹ���񷵻�1�����򷵻�0
    �ڽ��й���ʵ��ʱ���ɸ����Լ�������ʵ��Ժ��������޸ġ�
    */
}

void task_1()
{
    printf("Start task (1)\n");
    /* ʵ�ֺ���createBTree(),�����û����������ǰ�����й��������! */
    printf("************Create binary tree by special preorder sequence************\n");
    printf("Please input the special preorder sequence:\n");
    Btree * bt1 = createBTree();
    /* ʵ�ֺ���InOrderTravel(),���ض�������������. */
    printf("The inorder sequence of binary tree is: ");
    InOrderTravel(bt1);
    /* ʵ�ֺ���PostOrderTravel(),���ض�������������. */
    printf("\nThe postorder sequence of binary tree is: ");
    PostOrderTravel(bt1);
    /* ʵ�ֺ���depthOfTree(),���ض��������. */
    printf("\nThe depth of bt1 is: %d.", depthOfTree(bt1));
    /* ʵ�ֺ���nodesToCompleteBTree(),���ؽ���������ȫΪ������������ڵ���. */
    printf("\nThe nodes to complete binary tree are: %d.", nodesToCompleteBTree(bt1));
    getchar(); // ���д��밴��ע��,���ڴ������Ļس��ַ�!!!
    /* ʵ�ֺ���build(),�����û������������������к�����������й��������. */
    printf("\n******Create binary tree by preorder sequence and inorder sequence******\n");
    Btree * bt2;
    int len = 0; // ������ǰ��������г��� �� �����������������г���,���豣��!
    printf("Please input the preorder sequence:\n");
    /**
        ������룬�û����������ǰ����������
        �����������У�ÿ���ַ���ʾһ���������ڵ�����ŵ����ݣ������Preorder�����У�
        ����ʾ����ABDECF
        �ò�����Ҫ���û����������һ�����жϣ���֤�������ܹ���ȷ������
    */
    printf("Please input the inorder sequence:\n");
    /**
        ������룬�û����������������������
        �����������У�ÿ���ַ���ʾһ���������ڵ�����ŵ����ݣ������Inorder�����У�
        ����ʾ����DBEACF
        �ò�����Ҫ���û����������һ�����жϣ���֤�������ܹ���ȷ������
    */
    /**
        Tips��
        �ڸò�����Ҫ��ǰ��������к��������������г���ɸѡ�������������Ƿ�һ�£������ַ��Ƿ�һ�¡�
        ��ɸѡͨ���������build()�������������
            This pre-order traversal and mid-order traversal cannot construct a binary tree!
        ��Ϊbt2��ֵΪNULL��
    */
    bt2 = build(Preorder, Inorder, len);
    printf("The postorder sequence of binary tree is: ");
    PostOrderTravel(bt2);
    // ���ض�����������
    printf("\nThe depth of bt2 is: %d.", depthOfTree(bt2));
    printf("\nThe nodes to complete binary tree are: %d.\n", nodesToCompleteBTree(bt2));
}

void task_2()
{
    printf("Start task (2)\n");
    /* ʵ�ֺ���createBTree(),�����û����������ǰ�����й��������! */
    printf("************Create binary tree by special preorder sequence************\n");
    printf("Please input the special preorder sequence:\n");
    Btree * bt1 = createBTree();
    /* ʵ�ֺ���InOrderTravel(),���ض�������������. */
    printf("The inorder sequence of binary tree is: ");
    InOrderTravel(bt1);
    /* ʵ�ֺ���PostOrderTravel(),���ض�������������. */
    printf("\nThe postorder sequence of binary tree is: ");
    PostOrderTravel(bt1);
    getchar(); // ���д��밴��ע��,���ڴ������Ļس��ַ�!!!
    /*?ʵ�ֺ���isSymmetric(),�ж϶������Ƿ�Ϊ����Գƽṹ.?*/
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
    int len = 0; // ������ǰ��������г��� �� �����������������г��ȡ� ����Ҫ�ɱ���������Ҫ��ע�ͣ�
    printf("Please input the preorder sequence:\n");
    /**
        ������룬�û����������ǰ����������
        �����������У�ÿ���ַ���ʾһ���������ڵ�����ŵ����ݣ������Preorder�����У�
        ����ʾ����ABDECF
        �ò�����Ҫ���û����������һ�����жϣ���֤�������ܹ���ȷ������
    */
    printf("Please input the inorder sequence:\n");
    /**
        ������룬�û����������������������
        �����������У�ÿ���ַ���ʾһ���������ڵ�����ŵ����ݣ������Inorder�����У�
        ����ʾ����DBEACF
        �ò�����Ҫ���û����������һ�����жϣ���֤�������ܹ���ȷ������
    */
    /**
        Tips��
        �ڸò�����Ҫ��ǰ��������к��������������г���ɸѡ�������������Ƿ�һ�£������ַ��Ƿ�һ�¡�
        ��ɸѡͨ���������build()�������������
            This pre-order traversal and mid-order traversal cannot construct a binary tree!
        ��Ϊbt2��ֵΪNULL��
    */
    bt2 = build(Preorder, Inorder, len);
    printf("The postorder sequence of binary tree is: ");
    PostOrderTravel(bt2);
    // �ж϶������Ƿ�Ϊ����Գƽṹ
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
    /* ˵����
     * 1. �涨�ն�����Ϊ����Գƣ�
     * 2. ��������Գ�ʱ����������ǰ����������������У�
     * 3. ��������������ʾ����Ϊ��ȷ�������������Լ����������н��г���׳��������
     * 4. �������ĺ����޷��������󣬿������ʵ���Ӻ����ӿڣ�������ע��������;��δʹ�ú�������ע�͵���
     * */
     task_1();
     task_2();
     return 0;
}
