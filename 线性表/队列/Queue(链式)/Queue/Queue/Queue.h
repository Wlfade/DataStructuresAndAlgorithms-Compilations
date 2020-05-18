//
//  Queue.h
//  Queue
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#ifndef Queue_h
#define Queue_h

#include <stdio.h>
typedef struct QNode{
    int data;
    struct QNode * next;
}QNode;
QNode * initQueue(void);

QNode* enQueue(QNode * rear,int data);

QNode* DeQueue(QNode * top,QNode * rear);
#endif /* Queue_h */
