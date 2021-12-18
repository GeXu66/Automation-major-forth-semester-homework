#include <stdio.h>
#include <stdlib.h>

#define MAX 0x3f3f3f3f


//请实现排序算法,可自定义参数
void resort(int *arr, int num) {
    for (int i = 0; i < n - 1; i++) {
        bool isSorted = true;
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                isSorted = false;
                int temp = a[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        if (isSorted) break;
    }
}//冒泡排序


//找到最邻近数字对,可自定义参数
void findClosestPair(int *arr, int num) {
    int i, temp;
    int minus[num - 1];//储存两数之差
    int n = 0;//计数
    for (i = 0; i < num - 1; i++) {
        minus[i] = abs(abs(arr[i + 1]) - abs(arr[i]));
    }
    temp = minus[0];
    for (i = 0; i < num - 1; i++) {
        if (temp > minus[i]) {
            temp = minus[i];
        }
    }//找出最小差
    for (i = 0; i < num - 1; i++) {
        if (temp == minus[i]) {
            printf("%d %d,", arr[i], arr[i + 1]);
        }
    }//找出所有最小差的组合
    printf("\n");
}


int main() {
    int num;
    int caseNum = 0;

    // 文件输入方式
    freopen("5_1_input.in", "r", stdin);
    while (scanf("%d", &num) != EOF) {
        caseNum++;
        printf("==== Case %d ====\n", caseNum);
        int arr[num];
        for (int i = 0; i < num; i++) {
            scanf("%d", &arr[i]);
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
