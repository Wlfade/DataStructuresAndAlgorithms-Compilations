//
//  LinkList.c
//  LinkList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include "LinkList.h"
link * initLink(){
    link * temp = (link*)malloc(sizeof(link));//创建首元节点
    //首元节点先初始化
    temp->elem = 1;
    temp->next = NULL;
    link *p = temp;//头指针指向首元节点
    for (int i=2; i<5; i++) {
        link *a=(link*)malloc(sizeof(link));
        a->elem=i;
        a->next=NULL;
        //建立新节点与直接前驱节点的逻辑关系
        temp->next=a;
        temp=temp->next;
    }
    return p;
}
void display(link *p){
    link* temp=p;//将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp) {
        printf("%d ",temp->elem);
        temp=temp->next;
    }
    printf("\n");
}

/**
 link * initLink(){
     link * p=(link*)malloc(sizeof(link));//创建一个头结点 且含头节点的链表
     link * temp=p;//声明一个指针指向头结点，
     //生成链表
     for (int i=1; i<5; i++) {
         link *a=(link*)malloc(sizeof(link));
         a->elem=i;
         a->next=NULL;
         temp->next=a;
         temp=temp->next;
     }
     return p;
 }

 void display(link *p){
     link* temp=p;//将temp指针重新指向头结点
     //只要temp指针指向的结点的next不是Null，就执行输出语句。
     while (temp->next) {
         temp=temp->next;
         printf("%d",temp->elem);
     }
     printf("\n");
 }
 */


//p为原链表，elem表示新数据元素，add表示新元素要插入的位置
link * insertElem(link * p,int elem,int add){
    link * temp=p;//创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i=1; i<add; i++) {
        if (temp==NULL) {
            printf("插入位置无效\n");
            return p;
        }
        temp=temp->next;
    }
    //创建插入结点c
    link * c=(link*)malloc(sizeof(link));
    c->elem=elem;
    //向链表中插入结点
    c->next=temp->next;
    temp->next=c;
    return  p;
}

//p为原链表，add为要删除元素的值
link * delElem(link * p,int add){
    link * temp=p;
    //temp指向被删除结点的上一个结点
    for (int i=1; i<add; i++) {
        temp=temp->next;
    }
    link * del=temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next=temp->next->next;//删除某个结点的方法就是更改前一个结点的指针域
    free(del);//手动释放该结点，防止内存泄漏
    return p;
}

//p为原链表，elem表示被查找元素、
int selectElem(link * p,int elem){
//新建一个指针t，初始化为头指针 p
    link * t=p;
    int i=1;
    //由于头节点的存在，因此while中的判断为t->next
    while (t->next) {
        t=t->next;
        if (t->elem==elem) {
            return i;
        }
        i++;
    }
    //程序执行至此处，表示查找失败
    return -1;
}
//更新函数，其中，add 表示更改结点在链表中的位置，newElem 为新的数据域的值
link *amendElem(link * p,int add,int newElem){
    link * temp=p;
    temp=temp->next;//在遍历之前，temp指向首元结点
    //遍历到被删除结点
    for (int i=1; i<add; i++) {
        temp=temp->next;
    }
    temp->elem=newElem;
    return p;
}
