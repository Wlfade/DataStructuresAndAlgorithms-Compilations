//
//  SequenceList.c
//  SequenceList
//
//  Created by 单车 on 2020/5/14.
//  Copyright © 2020 单车. All rights reserved.
//

#include "SequenceList.h"

void InitList(SeqList *L)
{
    L->length = 0;
}
int CreatList(SeqList *L, DataType a[], int n)
{
    if (n > MaxSize) { printf("顺序表的空间不够，无法建立顺序表\n"); return 0;
    }
    for (int i = 0; i < n; i++)
        L->data[i] = a[i];
    L->length = n;
    return 1;
}
int Clean(SeqList *L){
    L->length = 0;
    printf("清空顺序表\n");
    return 0;
}
int Empty(SeqList *L)
{
    if (L->length == 0)return 1;
    else return 0;
}
int Length(SeqList *L)
{
    return L->length;
}
void PrintList(SeqList *L)
{
    for (int i = 0; i < L->length; i++)
        printf("%d ", L->data[i]);       /*输出线性表的元素值，假设为int型*/
}
int Locate(SeqList *L, DataType x)
{
    for (int i = 0; i < L->length; i++)
        if (L->data[i] == x) return i + 1;           /*返回序号*/
    return 0;                               /*退出循环，说明查找失败*/
}
int Get(SeqList *L, int i, DataType *ptr)
{
    if (i<1 || i>L->length) { printf("查找位置非法，查找失败\n"); return 0;}
    else { *ptr = L->data[i - 1]; return 1;}
}
int Insert(SeqList *L, int i, DataType x)
{
    if (L->length >= MaxSize) { printf("上溢错误，插入失败\n"); return 0; }
    if (i < 1 || i > L->length + 1)
    {
        printf("位置错误，插入失败\n");
        return 0;
    }
    for (int j = L->length; j >= i; j--){                  /*j表示元素序号*/
        //先把i索引处的元素及其后面的元素一次向后移动一位
        L->data[j] = L->data[j - 1];
        /** 出入到第i个索引是 i-1 */
        L->data[i - 1] = x;
        
    }
    L->length++;
    return 1;
}
int Delete(SeqList *L, int i, DataType *ptr)
{
    if (L->length == 0) { printf("下溢错误，删除失败\n"); return 0; }
    if (i < 1 || i > L->length) { printf("位置错误，删除失败\n"); return 0; }
    *ptr = L->data[i - 1];                       /*取出位置i的元素*/
    for (int j = i; j < L->length; j++)              /* j表示元素所在数组下标*/
        L->data[j - 1] = L->data[j];
    L->length--;
    return 1;
}

