#include<stdio.h>
#include<stdlib.h>
#define MAX 80
typedef struct node
{
int data;
struct node *next;
}N;
N *head=(N *)malloc(sizeof(N));//创建头结点




void Creat()
{
N *p;//用于插入新节点
N *r=head;//尾指针 开始指向头结点
printf("请输入任意个数据(用回车结束输入、空格间隔:1 2 3……)\n:");
do{
p=(N *)malloc(sizeof(N));
scanf("%d",&p->data);
r->next=p;
r=p;
}while(getchar()!='\n');
r->next=NULL;
}




void Disp()//实现顺序输出
{
N *p=head->next;//用于遍历单链表
int a[MAX];
int i=0,j;
printf("顺序输出:\n");
while(p)
{
printf("%d-->",p->data);
a[i]=p->data;
p=p->next;
i++;
}
}
int main()
{
Creat();
Disp();
}