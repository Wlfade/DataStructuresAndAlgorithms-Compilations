//
//  Queue.c
//  Queue
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include "Queue.h"
#include <stdlib.h>
QNode * initQueue(){
    //创建一个头节点
    QNode * queue=(QNode*)malloc(sizeof(QNode));
    //对头节点进行初始化
    queue->next=NULL;
    return queue;
}
QNode* enQueue(QNode * rear,int data){
    //1、用节点包裹入队元素
    QNode * enElem=(QNode*)malloc(sizeof(QNode));
    enElem->data=data;
    enElem->next=NULL;
    //2、新节点与rear节点建立逻辑关系
    rear->next=enElem;
    //3、rear指向新节点
    rear=enElem;
    //返回新的rear，为后续新元素入队做准备
    return rear;
}
QNode* DeQueue(QNode * top,QNode * rear){
    if (top->next==NULL) {
        printf("\n队列为空");
        return rear;
    }
    QNode * p=top->next;
    printf("%d ",p->data);
    top->next=p->next;
    if (rear==p) {
        rear=top;
    }
    free(p);
    return rear;
}
