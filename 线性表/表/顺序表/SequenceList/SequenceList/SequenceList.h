//
//  SequenceList.h
//  SequenceList
//
//  Created by 单车 on 2020/5/14.
//  Copyright © 2020 单车. All rights reserved.
//

#ifndef SequenceList_h
#define SequenceList_h

#include <stdio.h>
#define MaxSize 100 /*假设顺序表最多存放100个元素*/

typedef int DataType; /*定义线性表的数据类型，假设为int型*/

typedef struct
{
    DataType data[MaxSize];     /*存放数据元素的数组*/
    int length;                 /*线性表的长度*/
}SeqList;

void InitList(SeqList *L);
int CreatList(SeqList *L, DataType a[], int n);
int Clean(SeqList *L);
int Empty(SeqList *L);
int Length(SeqList *L);
void PrintList(SeqList *L);
int Locate(SeqList *L, DataType x);
int Get(SeqList *L, int i, DataType *ptr);
int Insert(SeqList *L, int i, DataType x);
int Delete(SeqList *L, int i, DataType *ptr);
#endif /* SequenceList_h */
