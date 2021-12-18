#include <stdio.h>
#include <stdlib.h>

#define MAX 0x3f3f3f3f


//请实现排序算法,可自定义参数
void resort(int* arr,int num){
    int i,j,temp;
	for (i = 1; i < num; i++)
	{
		temp = arr[i];
		for (j = i - 1; j >= 0 && abs(arr[j]) >abs( temp); j--)
		{
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
	}
}//直接插入排序

//找到最邻近数字对,可自定义参数
void findClosestPair(int *arr, int num){


    int i,temp;
    int c[num-1];//储存两个数的差值
    int n=0;//计数
    for(i=0;i<num-1;i++)
    {
        c[i]=abs(abs(arr[i+1])-abs(arr[i]));
    }
    temp=c[0];
    for(i=0;i<num-1;i++)
    {
        if(temp>c[i])
        {
            temp=c[i];
        }
    }
    for(i=0;i<num-1;i++)
    {
        if(temp==c[i])
        {
            printf("%d %d,",arr[i],arr[i+1]);
        }
    }
    printf("\n");
}


int main(){
    int num;
    int caseNum = 0;

    // 文件输入方式
    freopen("5_1_input.in", "r", stdin);
    while(scanf("%d",&num)!=EOF){
        caseNum++;
        printf("==== Case %d ====\n",caseNum);
        int arr[num];
        for(int i = 0; i < num; i++){
            scanf("%d",&arr[i]);
        }
        resort(arr, num);
        findClosestPair(arr, num);
    }
    fclose(stdin);

    /*
     终端输入方式
    while(scanf("%d",&num)!=EOF){
        caseNum++;
        printf("==== Case %d ====\n",caseNum);
        int arr[num];
        for(int i = 0; i < num; i++){
            scanf("%d",&arr[i]);
        }
        resort(arr, num);
        findClosestPair(arr, num);
    }
     */

    return 0;
}
