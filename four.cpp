#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node{
    char data ;
    struct node * lchild;
    struct node * rchild;
}BiTree;

BiTree * CreatTree();
int Count(BiTree * );
void Preorder(BiTree *);

int main(){
    BiTree * top = NULL;
    top = CreatTree();
    printf("遍历结果： ");
    Preorder(top);
    putchar('\n');
    printf("叶子节点的个数： %d\n",Count(top));

    system("pause");
    return 0;
}

 BiTree * CreatTree(){

    BiTree *t;
    char ch ;
    ch = getchar();
    if (ch != '#'){
            t = (BiTree *)malloc(sizeof(BiTree));
            t ->data = ch ;
            t->lchild = CreatTree();
            t->rchild = CreatTree();
        }
        else{
            t=NULL;
        }
        return t;
}
int Count(BiTree * top){
    if(top == NULL){
        return 0;
    }
    else if ((top->lchild==NULL) && (top->rchild==NULL)){
        return 1;
    }
    else{
        return Count(top->lchild)+Count(top->rchild);
    }
}

void Preorder(BiTree * top ){
    if(top != NULL){
        printf("%c ",top->data);
        Preorder(top->lchild);
        Preorder(top->rchild);
    }
}

int orderedList::BinarySearch(DataType x,int low,int high)
{
int low=0,high=n-1;
int mid=(low+high)/2;
while(Element[mid]!=x && low<=high)
  {
    if(x<Element[mid]) {
        high=mid-1;
    }else{
        low=mid+1;
        mid=(low+high)/2
    }     
   }
    if(Element[mid]==x) {
       return mid;
    } else {
       return -1;  
    } 
}

