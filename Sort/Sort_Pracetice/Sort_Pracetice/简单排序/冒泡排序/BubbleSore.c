//
//  BubbleSore.c
//  Sort_Pracetice
//
//  Created by 单车 on 2020/5/12.
//  Copyright © 2020 单车. All rights reserved.
//

#include "BubbleSore.h"
#include <string.h>
#include <time.h>
/**
 冒泡排序将已排序部分定义在右端，在遍历未排序部分的过程执行交换，将最大元素交换到最右端。

 冒泡排序
 【冒泡排序】：相邻元素两两比较，比较完一趟，最值出现在末尾
   第1趟：依次比较相邻的两个数，不断交换（小数放前，大数放后）逐个推进，最值最后出现在第n个元素位置
   第2趟：依次比较相邻的两个数，不断交换（小数放前，大数放后）逐个推进，最值最后出现在第n-1个元素位置
    ……   ……
  第n-1趟：依次比较相邻的两个数，不断交换（小数放前，大数放后）逐个推进，最值最后出现在第2个元素位置

 */

void bubbleSort(){
    int a[] = {900, 2, 3, -58, 34, 76, 32, 43, 56, -70, 35, -234, 532, 543, 2500};
    int n;  //存放数组a中元素的个数
    int i;  //比较的轮数
    int j;  //每轮比较的次数
    int buf;  //交换数据时用于存放中间数据
    n = sizeof(a) / sizeof(a[0]);  /*a[0]是int型, 占4字节, 所以总的字节数除以4等于元素的个数*/
    for (i=0; i<n-1; ++i)  //比较n-1轮
    {
        for (j=0; j<n-1-i; ++j)  //每轮比较n-1-i次,
        {
            if (a[j] < a[j+1])
            {
                buf = a[j];
                a[j] = a[j+1];
                a[j+1] = buf;
            }
        }
    }
    for (i=0; i<n; ++i)
    {
        printf("%d\x20", a[i]);
    }
    printf("\n");
}

int* bublle_Sort(int *arr, int length)  {
    for(int i = 0; i < length - 1; i++) { //趟数
        for(int j = 0; j < length - i - 1; j++) { //比较次数
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    return arr;
}

void bubbleSortTest(){
    int a[] = {900, 2, 3, -58, 34, 76, 32, 43, 56, -70, 35, -234, 532, 543, 2500};
    int length = sizeof(a)/sizeof(a[0]);
    clock_t startTime, endTime;

    startTime = clock();
    for (int i = 0; i< length; i ++) {
        printf("%d\n", bublle_Sort(a, length)[i]);
    }
    endTime = clock();
    printf("运行时间为%ld毫秒\n", endTime - startTime);
}
