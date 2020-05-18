//
//  ShellSort.c
//  Sort_Pracetice
//
//  Created by 单车 on 2020/5/12.
//  Copyright © 2020 单车. All rights reserved.
//

#include "ShellSort.h"
#include "MathTool.h"
/**
 时间复杂度
   希尔排序的时间复杂度依赖于增量序列的函数，有人在大量的实验后得出的结论：当n在某个特定的范围后，在最优的情况下，希尔排序的时间复杂度为O(n^1.3)，在最差的情况下，希尔排序的时间复杂度为：O(n^2).
 空间复杂度
   希尔排序的空间复杂度：O(1).
 */
/**
 增长量h的确定：增长量h的值每一个固定的规则
 int h = 1;
 while (h<sizeof(arr)/2) {
     h = 2*h + 1;
 }
 循环结束后：
 h = h / 2;
 
 */
void shellSort(int *arr, int length){
    int h = 1;
    while (h<length/2) {
        h = 2*h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < length; i ++) {
            printf("h:%d/i:%d\n",h,i);

            for (int j = i; j>=h; j -= h) {
                if (greater(arr[j-h], arr[j])) {
                    exchange(arr, j-h, j);
                    printf("change:(j-h):%d/j:%d\n",j-h,j);
                }
                else{
//                    break;
                    printf("break:(j-h):%d/j:%d\n",j-h,j);
//                    break;
                }
                printf("j:%d/h:%d/i:%d\n",j,h,i);
                for (int k = 0; k< length; k ++) {
                    printf("%d,", arr[k]);
                }
                printf("\n----------\n");
            }
        }
        h = h / 2;
    }
}
void shellSortTest(void){
    int a[] = { 900, 3, -58, 34, 76, 32, 43, 56, -70, 35,};
    int length = sizeof(a)/sizeof(a[0]);
//    for (int i = 0; i< length; i ++) {
//        printf("%d", shellSort(a, length)[i]);
//    }
    shellSort(a, length);
    
}

