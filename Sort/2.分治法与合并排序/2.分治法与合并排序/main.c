//
//  main.c
//  2.分治法与合并排序
//
//  Created by 王玲峰 on 5/2/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <time.h>

int main(int argc, const char * argv[])
{
    int A[8] = {2, 4, 5, 7, 1, 2, 3, 6};
    int n1 = 4;
    int n2 = 4;
    //哨兵
    int c = UINT8_MAX;
    //L和R两个数组
    int L[5] = {0};
    int R[5] = {0};

    for (int i = 0; i < n1; i ++) {
        L[i] = A[i];
    }
    L[4] = c;
    
    for (int i = n1; i < 8; i ++) {
        R[i - 4] = A[i];
    }
    R[4] = c;
    
    int i = 0;
    int j = 0;
    int k = 0;
    
    //将两边已经排序好的 两个小的数据以此比较 取出小的 赋值 给 新的数据中，已经取出小的数据先后取新的数据与另一个数据那个原先的数再次比较
    for (k = 0; k < 8; k ++) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i ++;
        }
        else {
            A[k] = R[j];
            j ++;
        }
        
        if (L[i] == c && R[j] == c) {
            break;
        }
    }
    
    for (int k = 0; k < 8; k++) {
        printf("%d\n",A[k]);
    }
    
    //由上可知，总的表达式就是cnlgn + cn，也就是O(nlgn)。
    //int A[8] = {1, 4, 5, 7, 1, 2, 3, 6};


}
