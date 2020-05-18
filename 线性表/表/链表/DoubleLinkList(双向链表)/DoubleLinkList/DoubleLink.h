//
//  DoubleLink.h
//  DoubleLinkList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#ifndef DoubleLink_h
#define DoubleLink_h

#include <stdio.h>
typedef struct line{
    struct line * prior; //指向直接前趋
    int data;
    struct line * next; //指向直接后继
}line;
//双链表的创建
line* initLine(line * head);
//双链表插入元素，add表示插入位置
line * insertLine(line * head,int data,int add);
//双链表删除指定元素
line * delLine(line * head,int data);
//双链表中查找指定元素
int selectElem(line * head,int elem);
//双链表中更改指定位置节点中存储的数据，add表示更改位置
line *amendElem(line * p,int add,int newElem);
//输出双链表的实现函数
void display(line * head);
#endif /* DoubleLink_h */
