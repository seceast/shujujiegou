/*
 * @Author: seceast 
 * @Date: 2020-09-29 09:34:53 
 * @Last Modified by: seceast
 * @Last Modified time: 2020-09-29 09:47:19
 */
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


//函数结果状态代码
#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
//Status 是函数的类型，其值是函数结果状态代码
typedef int Status;
typedef char ElemType;

#define LIST_INIT_SIZE 100
#define Maxsize 50

typedef struct 
{
    ElemType data[LIST_INIT_SIZE];
    int length;
}SqList;

//创建顺序表
void CreateList(SqList * &L,ElemType a[],int n)     //由a中的n个元素建立顺序表
{
    int i = 0,k = 0;
    L=(SqList*)malloc(sizeof(SqList));              //分配空间
    while (i<n)
    {
        L->data[k]=a[i];
        k++;i++;
    }
    L->length=k;
}

//初始化线性表
Status InitList(SqList * &L){                      
    L= (SqList*)malloc(sizeof(SqList));
    L->length = 0;
}

//线性表逆序
void Inversion(SqList *L)                          
{
    int a,b,i;
    a = L->length;
    for (i = 1;i <= a/2;i++){
        b = L->data[i-1];
        L->data[i-1] = L->data[a-i];
        L->data[a-i] = b;
    }
} 

//销毁线性表
void DestroyList(SqList * & L)
{
    free(L);
}

//判断是否为空
bool ListEmpty(SqList * L)
{
    return (L->length==0);
}

//求长度
int ListLength(SqList * L)
{
    return (L->length);
}

//输出线性表
void DispList(SqList * L)
{
    for (int i = 0;i<L->length;i++){
        printf("%d",L->data[i]);
    }
    printf("\n");
}

//求某个元素的值
bool GetElem(SqList * L,int i,ElemType &e){
    if(i<1|| i>L->length)
        return false;
    e = L->data[i-1];
    return true;
}

//按元素值查找
int LocateElem(SqList * L,ElemType e){
    int i=0;
    while (i<L->length && L->data[i]!=e)
        i++;
    if(i>=L->length)
        return 0;
    else
        return i+1;    
}

//插入
bool ListInsert(SqList * &L,int i,ElemType e){
    int j;
    if(i<1 || i>L->length || L->length==Maxsize)
        return false;
    i--;
    for(j=L->length;j>i;j--)
        L->data[j]=L->data[j-1];
    L->data[i]=e;
    L->length++;
    return true;
}

//删除顺序表中所有值为x的元素
void delnode1(SqList *&A, ElemType x)
{   int k=0,i;	  //k记录值不等于x的元素个数
    for (i=0;i<A->length;i++){
        if (A->data[i]!=x){    //若当前元素不为x，将其插入A中
                A->data[k]=A->data[i];
	            k++;		 //不等于x的元素增1
        }
    }
    A->length=k;		 //顺序表A的长度等于k
}

