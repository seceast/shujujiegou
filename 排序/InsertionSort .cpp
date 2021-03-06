/*
 * @Author: seceast
 * @Date: 2020-10-29 10:25:58
 * @LastEditors: seceast
 * @LastEditTime: 2020-10-29 10:54:51
 */ 

#include <stdio.h>

typedef int KeyType;
typedef int InfoType;

typedef struct{
    KeyType key;
    InfoType data;
}RecType;

//插入排序(下列算法为递增)
void InsertSort(RecType R[],int n){
    int i,j;
    RecType tmp;
    for (i=1;i<n;i++){
        if(R[i].key<R[i-1].key){
            tmp = R[i];
            j=i-1;
            do{                     //找位置
                R[j+1]=R[i];        //大于R[i]的记录后移
                j--;
            } while (j>=0 && R[j].key>tmp.key);
            R[j+1]=tmp;             //在j+1出插入R[i]
        }
    }
}

//折半插入
void BinInsertSort(RecType R[],int n){
    int i,j,low,high,mid;
    RecType tmp;
    for (i=1;i<n;i++){
        if(R[i].key<R[i-1].key){
            tmp = R[i];
            low=0;high=i-1;
            while (low<=high){          //在low到high中查找位置
                mid=(low+high)/2;       //取中间值
                if(tmp.key<R[mid].key)  
                    high=mid-1;
                else
                    low=mid+1;
            }
            for(j=i-1;j>high+1;j--)     //集中进行元素后移
                R[j+1]=R[j];
            R[high+1]=tmp;              //插入
        }
    }
}

//希尔排序
void ShellSort(RecType R[],int n){
    int i,j,d;
    RecType tmp;
    d=n/2;
    while (d>0){
        for (i=d;i<n;i++){
            tmp=R[i];
            j=i-d;
            while (j>=0 && tmp.key<R[j].key){
                R[j+d]=R[j];
                j=j-d;
            }
            R[j+d]=tmp;
        }
        d=d/2;
    }
}