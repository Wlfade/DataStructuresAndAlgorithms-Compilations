//
//  NewQueue.h
//  Queue
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#ifndef NewQueue_h
#define NewQueue_h

#include <stdio.h>
#define max 5//表示顺序表申请的空间大小

int enQueue(int *a,int front,int rear,int data);
int deQueue(int *a,int front,int rear);
#endif /* NewQueue_h */
