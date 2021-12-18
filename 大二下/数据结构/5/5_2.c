#include <stdio.h>
#include <string.h>

// 以字符串的形式表示数字
typedef struct nString {
    char strNum[1002];
    int length;
} nString;
// 也可自行决定存储结构

// 比较两个字符串，可自定义参数或自定义函数
int cmpStr(nString fir, nString sec) {
    int i;
    //首先比较长度
    //长度大的数值大
    if (fir.length > sec.length) {
        return 1;
    }
    //长度小的数值小
    if (fir.length < sec.length) {
        return 0;
    }
    //长度相等逐位比较
    if (fir.length == sec.length) {
        for (i = 0; i < fir.length; i++) {
            if (fir.strNum[i] > sec.strNum[i]) {
                return 1;
            }
            if (fir.strNum[i] < sec.strNum[i]) {
                return 0;
            }
        }
    }
}

// 请实现排序算法,可自定义参数
void resort(nString *a, int num) {
    for (int i = 0; i < n - 1; i++) {
        bool isSorted = true;
        for (int j = 0; j < n - 1 - i; j++) {
            if (cmpStr(a[j], a[j + 1])) {
                isSorted = false;
                nString temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        if (isSorted) break;
    }
}//冒泡排序

int main(void) {
    int num;
    int caseNum = 0;

    // 文件输入方式
    freopen("5_2_input.in", "r", stdin);
    while (scanf("%d", &num) != EOF) {
        caseNum++;
        printf("==== Case %d ====\n", caseNum);
        nString arr[num];
        for (int i = 0; i < num; i++) {
            scanf("%s", arr[i].strNum);
            arr[i].length = strlen(arr[i].strNum);
        }
        resort(arr, num);
        for (int i = 0; i < num; i++) {
            printf("%s\n", arr[i].strNum);
        }
    }
    fclose(stdin);

    /* 终端输入方式
   while(scanf("%d",&num)!=EOF){
       caseNum++;
       printf("==== Case %d ====\n",caseNum);
       nString arr[num];
       for(int i = 0; i < num; i++){
           scanf("%s",arr[i].strNum);
           arr[i].length = strlen(arr[i].strNum);
       }
       resort(arr, num);
       for(int i = 0; i < num; i++){
           printf("%s\n",arr[i].strNum);
       }
   }
   */
}


