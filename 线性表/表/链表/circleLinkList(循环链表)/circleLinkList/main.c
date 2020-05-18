//
//  main.c
//  circleLinkList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include <stdio.h>
#include "CircleLinkList.h"
int main(int argc, const char * argv[]) {
    printf("输入圆桌上的人数n:");
    int n;
    scanf("%d",&n);
    person * head=initLink(n);
    printf("从第k人开始报数(k>1且k<%d)：",n);
    int k;
    scanf("%d",&k);
    printf("数到m的人出列：");
    int m;
    scanf("%d",&m);
    findAndKillK(head, k, m);
    return 0;
}
