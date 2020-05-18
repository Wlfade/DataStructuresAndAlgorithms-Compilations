//
//  selectSort.c
//  Sort_Pracetice
//
//  Created by 单车 on 2020/5/12.
//  Copyright © 2020 单车. All rights reserved.
//
#include <string.h>
#include <time.h>
#include "selectSort.h"
/**
选择排序利用数组的下标将左边的数依次对比后面的数如果左边的数比右边的数大则换位置 。

选择排序
【选择排序】：依次取出对应下标的数如果这个数比后面数大调换位置，否则不变
  第1趟：取第一个数和第二个数比，比第二个数大 调换位置，否则不变，再与第三个数比较。。。最后一个比较
  第2趟：取第二个数与后面的数比较
   ……   ……
 第n-1趟：与最后的数比较
 
 【选择排序】：最值出现在起始端
 第1趟：在n个数中找到最小(大)数与第一个数交换位置
 第2趟：在剩下n-1个数中找到最小(大)数与第二个数交换位置
 重复这样的操作...依次与第三个、第四个...数交换位置
 第n-1趟，最终可实现数据的升序（降序）排列。

*/
int* selectSort(int *arr, int length)  {
    for (int i = 0; i < length - 1; i++) { //趟数
        for (int j = i + 1; j < length; j++) { //比较次数
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}
void selectSortTest(){
    int a[] = {900, 2, 3, -58, 34, 76, 32, 43, 56, -70, 35, -234, 532, 543, 2500};
    int length = sizeof(a)/sizeof(a[0]);
    clock_t startTime, endTime;

    startTime = clock();
    for (int i = 0; i< length; i ++) {
        printf("%d\n", selectSort(a, length)[i]);
    }
    endTime = clock();
    printf("运行时间为%ld毫秒\n", endTime - startTime);
}
