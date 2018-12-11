#include<stdio.h>

int main(void)
  { 
    int i,n,x,y,t;
    int a[10];
    printf("enter n:\n");
    scanf("%d",&n);
    printf("enter %d numbers\n",n);
    for(i=0;i<n;i++) {
      scanf("%d",&a[i]);
    }

    int startPos = 0;  // 头位置
    int endPos = n;  // 尾位置
    int minPos = 0, maxPos = n - 1; //最小 最大
    int temp = 0; //标识量

while(endPos-startPos >= 1) {
    for(i=startPos;i<endPos;i++){

      if(a[i]<a[minPos]){
        minPos=i;
      }

      if(a[i]>a[maxPos]){
        maxPos=i;
      }
    }

    //将最小值放到startPos位置
    temp=a[startPos];
    a[startPos]=a[minPos];
    a[minPos]=temp;
    //将最大值放到endPos位置
    temp=a[endPos-1];
    a[endPos-1]=a[maxPos];
    a[maxPos]=temp;


    // 将最大值和最小值从排序区间中移出，进行下一轮排序
    startPos++;
    endPos--;
    minPos++;
    maxPos--;
}
    for(i=0;i<n;i++) {
      printf("%d-->",a[i]);
    }
    
    return 0;

  }
