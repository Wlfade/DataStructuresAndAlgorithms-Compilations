//
//  CircleLinkList.c
//  circleLinkList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include "CircleLinkList.h"
person * initLink(int n){
    person *head = (person *)malloc(sizeof(person));
    head->number = 1;
    head->next = NULL;
    person *cyclic = head;
    for (int i = 2; i <= n; i ++) {
        person *body = (person *)malloc(sizeof(person));
        body->number = i;
        body->next = NULL;
        
        cyclic->next = body;
        cyclic = cyclic->next;
    }
    cyclic->next = head; //首尾相连
    return head;
}
void findAndKillK(person *head,int k,int m){
    person *tail = head;
    //找到链表第一个结点的上一个结点，为删除操作做准备
    while (tail->next!= head) {
        tail = tail->next;
    }
    person *p = head;
    //找到编号为K的人
    while (p->number != k) {
        tail=p;
        p=p->next;
    }
    //从编号为k的人开始，只有符合p->next == p时，说明链表中除了p结点，所有编号都出列了
    while (p->next != p) {
        //找到从p报数1开始，报m的人，并且还要知道数m-1de人的位置tail，方便做删除操作。
        for (int i=1; i<m; i++) {
            tail=p;
            p=p->next;
        }
        tail->next=p->next;//从链表上将p结点摘下来
        printf("出列人的编号为:%d\n",p->number);
        free(p);
        p=tail->next;//继续使用p指针指向出列编号的下一个编号，游戏继续
    }
    printf("出列人的编号为:%d\n",p->number);
    free(p);
}
