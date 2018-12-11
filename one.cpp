#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define SIZE sizeof(struct _LNODE)

typedef struct _LNODE
{
int data;
struct _LNODE *next;
}LinkList;


void Init_List(LinkList **L);
LinkList *Create_List(LinkList *L, int len);
void Disp_List(LinkList *L);
void Disp_List1(LinkList *L);
LinkList *Reverse_List(LinkList *L);
void Remove_memory(LinkList *L);

int main()
{
LinkList *LA = NULL;
int length = 0;

printf("Input the length of list you created: ");
scanf("%d", &length);
printf("Please input the data of the list:\n");
LA = Create_List(LA, length);

printf("\nThe list you created is :\n");
Disp_List(LA);

LA = Reverse_List(LA);
printf("\nThe list after reverse  is :\n");
Disp_List1(LA);

Remove_memory(LA);
puts("");
return 0;
}

void Init_List(LinkList **L)
{
*L = (LinkList *)malloc(SIZE);
        if((*L) == NULL)
        {
            printf("Memory assign failure!!");
            exit(1);
        }
(*L)->next = NULL;
}

LinkList *Create_List(LinkList *L, int len)
{
LinkList *p = NULL, *q = NULL;
int i = 0;

Init_List(&L);
Init_List(&p);
p = L;

for(i = 0; i < len; ++i)
{
q = (LinkList *)malloc(SIZE);
printf("Input the %dth data: ", i + 1);
scanf("%d", &q->data);

p->next  = q;
q->next = NULL;
p = q;
}
p->next = NULL;
return L;
}

void Disp_List(LinkList *L)
{
int n = 0;
LinkList *p = NULL;

p = L->next;
while(p != NULL)
{
printf("The %dth node's data is :   %d\n", n + 1, p->data);
n++;
p = p->next;
}
}

void Disp_List1(LinkList *L)
{
int n = 0;
LinkList *p = NULL;

p = L;
while(p->next  != NULL)
{
printf("The %dth node's data is :   %d\n", n + 1, p->data);
n++;
p = p->next;
}
}

LinkList *Reverse_List(LinkList *L)
{
LinkList *p1 = NULL, *p2 = NULL, *p3 = NULL;

if(L == NULL || L->next == NULL)
{
return L;
}

p1 = L;
p2 = p1->next;
while(p2)
{
p3 = p2->next;
p2->next = p1;
p1 = p2;
p2 = p3;
}
L->next = NULL;
L = p1;
return L;
}

void Remove_memory(LinkList *L)
{
LinkList *q = NULL;
q = L;

while(q != NULL)
{
LinkList *p = NULL;
p = q;
q = q->next;
free(p);
p = NULL;
}
}