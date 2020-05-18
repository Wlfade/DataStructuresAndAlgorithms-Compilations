//
//  LinkList.h
//  LinkList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#ifndef LinkList_h
#define LinkList_h

#include <stdio.h>
#include <stdlib.h>

//声明节点结构
typedef struct Link{
    int  elem;//存储整形元素
    struct Link *next;//指向直接后继元素的指针
}link;
//初始化链表的函数
link * initLink(void);
//用于输出链表的函数
void display(link *p);
//链表插入的函数，p是链表，elem是插入的结点的数据域，add是插入的位置
link * insertElem(link * p,int elem,int add);
//删除结点的函数，p代表操作链表，add代表删除节点的位置
link * delElem(link * p,int add);
//查找结点的函数，elem为目标结点的数据域的值
int selectElem(link * p,int elem);
//更新结点的函数，newElem为新的数据域的值
link *amendElem(link * p,int add,int newElem);

#endif /* LinkList_h */
