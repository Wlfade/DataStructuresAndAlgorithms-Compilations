//
//  main.c
//  NewQueue(顺序)
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include <stdio.h>
#include "NewQueue.h"
int main(int argc, const char * argv[]) {
    int a[max];
    int front,rear;
    //设置队头指针和队尾指针，当队列中没有元素时，队头和队尾指向同一块地址
    front=rear=0;
    //入队
    rear=enQueue(a,front,rear, 1);
    rear=enQueue(a,front,rear, 2);
    rear=enQueue(a,front,rear, 3);
    rear=enQueue(a,front,rear, 4);
    //出队
    front=deQueue(a, front, rear);
    //再入队
    rear=enQueue(a,front,rear, 5);
    //再出队
    front=deQueue(a, front, rear);
    //再入队
    rear=enQueue(a,front,rear, 6);
    //再出队
    front=deQueue(a, front, rear);
    front=deQueue(a, front, rear);
    front=deQueue(a, front, rear);
    front=deQueue(a, front, rear);
    return 0;
}
