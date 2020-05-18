//
//  Stack.c
//  Stack
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include "Stack.h"
//元素 elem 入栈
//代码中的 a[++top]=elem，等价于先执行 ++top，再执行 a[top]=elem。
int push(int *a,int top,int elem){
    a[++top] = elem;
    printf("入栈元素：%d\n",a[top]);
    return top;
}
//数据元素出栈
int pop(int * a,int top){
    if (top == -1) {
        printf("空栈");
        return -1;
    }
    printf("弹栈元素：%d\n",a[top]);
    top--;
    return top;
}
