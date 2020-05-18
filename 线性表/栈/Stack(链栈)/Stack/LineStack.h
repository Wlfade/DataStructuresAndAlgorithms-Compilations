//
//  LineStack.h
//  Stack
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#ifndef LineStack_h
#define LineStack_h

#include <stdio.h>
#include <stdlib.h>
typedef struct lineStack{
    int data;
    struct lineStack *next;
}lineStack;
//stack为当前的链栈，a表示入栈元素
lineStack* push(lineStack * stack,int a);
//栈顶元素出链栈的实现函数
lineStack * pop(lineStack * stack);
#endif /* LineStack_h */
