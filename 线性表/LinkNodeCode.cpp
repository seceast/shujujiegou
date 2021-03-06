/*
 * @Author: seceast
 * @Date: 2020-10-12 10:13:57
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-26 16:12:07
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef int ElemType;

//类型声明
typedef struct LNode
{
    ElemType data;
    struct LNode *next;
    
}LinkNode;

//建立单链表
//1头插法
void CreateListF(LinkNode *& L,ElemType a[],int n){
    LinkNode *s;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next=NULL;
    for (int i=0;i<n;i++){
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=a[i];
        s->next=L->next;
        L->next=s;
    }
}

//2尾插法
void CreateListR(LinkNode *& L,ElemType a[],int n)
{
    LinkNode *s ,*r;
    L=(LinkNode *)malloc(sizeof(LinkNode));
    r=L;
    for(int i=0;i<n;i++){
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data = a[i];
        r->next = s;
        r=s;
    }
    r->next = NULL;
}

//初始化
void InitList(LinkNode *& L){
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next =NULL;
}

//求某元素值
bool GetElem(LinkNode * L,int i,ElemType & e){
    int j=0;
    LinkNode *p=L;
    if(i<=0) return false;
    while (j<i&&p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL)
        return false;
    else
    {
        e=p->data;
        return true;
    }
}

//按元素值查找
int LocateElem(LinkNode *L,ElemType e){
    int i=1;
    LinkNode *p=L->next;
    while (p!=NULL && p->data!=e)
    {
        p=p->next;
        i++;
    }
    if(p=NULL)
        return (0);
    else
        return (i);
}

//插入元素
bool ListInsert(LinkNode *&L,int i,ElemType e){
    int j =0;
    LinkNode *p=L,*s;
    if(i<=0) return false;
    while (j<i-1 && p!=NULL)
    {
        j++;
        p=p->next;
    }
    if(p==NULL) return false;
    else
    {
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=e;
        s->next = p->next;
        p->next=s;
        return true;
    }
    
}

//单链表逆置
void Reverse(LinkNode *& L){
    LinkNode *p=L->next,*q;
    L->next=NULL;
    while (p!=NULL)
    {
        q=p->next;
        p->next = L->next;
        L->next=p;
        p=q;
    }
    
} 
//有一个带头结点的单链表L（至少有一个数据结点），
//设计一个算法使其元素递增有序排列
void sort(LinkNode *&L)
{
    LinkNode *p,*pre,*q;
    p=L->next->next;		//p指向L的第2个数据结点
    L->next->next=NULL;	//构造只含一个数据结点的有序表
    while (p!=NULL) {
        q=p->next;		//q保存*p结点后继结点的指针
        pre=L;  		//从有序表开头进行比较，pre指向插入*p的前驱结点
	    while (pre->next!=NULL && pre->next->data<p->data)
	        pre=pre->next;	//在有序表中找插入*p的前驱结点*pre
	p->next=pre->next;
	pre->next=p;
	p=q;			//扫描原单链表余下的结点
    }
}
