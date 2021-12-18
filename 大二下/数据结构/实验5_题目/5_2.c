#include <stdio.h>
#include <string.h>

// 以字符串的形式表示数字
typedef struct nString{
   char strNum[1002];
   int length;
}nString;
// 也可自行决定存储结构

// 比较两个字符串，可自定义参数或自定义函数
int cmpStr(nString fir,nString sec){
    int i;
    if(fir.length>sec.length)
    {
        return 1;
    }
    if(fir.length<sec.length)
    {
        return 0;
    }
    if(fir.length==sec.length)
    {
        for(i=0;i<fir.length;i++)
        {
            if(fir.strNum[i]>sec.strNum[i])
            {
                return 1;
            }
            if(fir.strNum[i]<sec.strNum[i])
            {
                return 0;
            }
        }
    }
}

// 请实现排序算法,可自定义参数
void resort(nString* arr,int num){
    int i,j;
    nString temp;
    for(i=0;i<num;i++)
    {
        temp=arr[i];
        for(j=i-1;j>=0&&0==cmpStr(temp,arr[j]);j--)
        {
            arr[j + 1] = arr[j];
		}
		arr[j + 1] = temp;
    }

}

int main(void){
   int num;
   int caseNum = 0;

   // 文件输入方式
   freopen("5_2_input.in", "r", stdin);
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


