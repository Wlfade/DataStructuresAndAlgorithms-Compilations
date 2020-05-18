//
//  Queue(顺序).c
//  Queue
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include "Queue(顺序).h"
//入队
int enQueue(int *a,int rear,int data){
    a[rear]=data;
    rear++;
    return rear;
}
//出队
void deQueue(int *a,int front,int rear){
    //如果 front==rear，表示队列为空
    while (front!=rear) {
        printf("出队元素：%d\n",a[front]);
        front++;
    }
}
