//
//  main.c
//  SequenceList
//
//  Created by 单车 on 2020/5/14.
//  Copyright © 2020 单车. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "SequenceList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int r[5] = { 1, 2, 3, 4, 5 }, i, x;
    SeqList L;                         /*定义变量L为顺序表类型*/
    CreatList(&L, r, 5);                     /*建立具有5个元素的顺序表*/
    printf("当前线性表的数据为：");
    PrintList(&L); /*输出当前线性表1 2 3 4 5*/

    Insert(&L, 2, 8);                    /*在第2个位置插入值为8的元素*/
    printf("执行插入操作后数据为：");
    PrintList(&L);                     /*输出插入后的线性表1 8 2 3 4 5*/
    printf("当前线性表的长度为：%d\n", Length(&L));    /*输出线性表的长度6*/
    printf("请输入查找的元素值：");
    scanf("%d", &x);
    i = Locate(&L, x);
    if (0 == i) printf("查找失败\n");
    else printf("元素%d的位置为：%d\n", x, i);
    printf("请输入查找第几个元素值：", &i);
    scanf("%d", &i);
    if (Get(&L, i, &x) == 1) printf("第%d个元素值是%d\n", i, x);
    else printf("线性表中没有第%d个元素\n", i);
    printf("请输入要删除第几个元素：");
    scanf("%d", &i);
    if (Delete(&L, i, &x) == 1) {                /*删除第i个元素*/
        printf("删除第%d个元素是%d，删除后数据为：", i, x);
        PrintList(&L);                         /*输出删除后的线性表*/
    }
    else printf("删除操作失败\n");


    system("pause");

    return 0;
}
