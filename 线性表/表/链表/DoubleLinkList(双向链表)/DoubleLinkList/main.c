//
//  main.c
//  DoubleLinkList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include <stdio.h>
#include "DoubleLink.h"
int main(int argc, const char * argv[]) {
    line * head=NULL;
    //创建双链表
    head=initLine(head);
    display(head);
//    //在表中第 3 的位置插入元素 7
    head=insertLine(head, 7, 3);
    display(head);
//    //表中删除元素 2
    head=delLine(head, 2);
    display(head);
    printf("元素 3 的位置是：%d\n",selectElem(head,3));
    //表中第 3 个节点中的数据改为存储 6
    head = amendElem(head,3,6);
    display(head);
    return 0;
}
