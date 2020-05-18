//
//  MathTool.c
//  Sort_Pracetice
//
//  Created by 单车 on 2020/5/12.
//  Copyright © 2020 单车. All rights reserved.
//

#include "MathTool.h"
int less(int v,int w){
    if (v<w) {
        return 1;
    }else{
        return 0;
    }
}
int greater(int v,int w){
    if (v>w) {
        return 1;
    }else{
        return 0;
    }
}


void exchange(int *a, int i,int j)
{
    int t;
    t=a[i];
    a[i]=a[j];
    a[j]=t;
}
