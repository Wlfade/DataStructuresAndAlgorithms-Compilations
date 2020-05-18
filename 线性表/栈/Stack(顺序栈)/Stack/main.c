//
//  main.c
//  Stack
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include <stdio.h>
#include "Stack.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int a[100];
    int top=-1;
    top=push(a, top, 1);
    top=push(a, top, 2);
    top=push(a, top, 3);
    top=push(a, top, 4);
    top=pop(a, top);
    top=pop(a, top);
    top=pop(a, top);
    top=pop(a, top);
    top=pop(a, top);
    return 0;
}
