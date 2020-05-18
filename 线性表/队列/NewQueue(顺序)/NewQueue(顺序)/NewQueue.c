//
//  NewQueue.c
//  Queue
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include "NewQueue.h"
int enQueue(int *a,int front,int rear,int data){
    //添加判断语句，如果rear超过max，则直接将其从a[0]重新开始存储，如果rear+1和front重合，则表示数组已满
    if ((rear+1)%max==front) {
        printf("空间已满");
        return rear;
    }
    a[rear%max]=data;
    rear++;
    return rear;
}
int  deQueue(int *a,int front,int rear){
    //如果front==rear，表示队列为空
    if(front==rear%max) {
        printf("队列为空");
        return front;
    }
    printf("%d ",a[front]);
    //front不再直接 +1，而是+1后同max进行比较，如果=max，则直接跳转到 a[0]
    front=(front+1)%max;
    return front;
}
