//
//  InsertSort.c
//  1.插入排序
//
//  Created by 单车 on 2020/5/12.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#include "InsertSort.h"
#include <string.h>
#include <time.h>


/**
 插入排序将已排序部分定义在左端，将未排序部分元的第一个元素插入到已排序部分合适的位置。

 插入排序第一种
 【插入排序】：初值出现在起始端 + 1
  第一趟：假设第一个数是已经排序好的 从第二个开始取值 如果第一个数比第二个数小 则换位置 否则不换
  第二趟：前两个数已经排序好了，从第三个开始取值（下标为2）如果第三个数比第二个小，换位置，否则不换， 再比较第二个数和第一个数，如果小换位置，否则不换
  ...
  第n-1趟：将最后一个数插入到前面已经排序好的数据中的合适的位置

 */

void insertSort(){
    int a[6] = {5, 2, 4, 6, 1, 3}; //乱序
//    int a[6] = {1, 2, 3, 4, 5, 6}; //正序
//    int a[6] = {6, 5, 4, 3, 2, 1}; //倒序

    int length = sizeof(a)/sizeof(a[0]);
    clock_t startTime, endTime;

    startTime = clock();
    
    for (int j = 1; j <= length - 1; j++) {
        int i = j - 1;
        int key = a[j];
        while (i >= 0 && a[i] > key) {
            a[i + 1] = a[i];
            i --;
            a[i + 1] = key;
        }
    }
    
    endTime = clock();
    
    for (int k = 0; k < length; k++) {
        printf("%d\n",a[k]);
    }
    
    printf("运行时间为%ld\n", endTime - startTime);
}


int *nsertSort(int *arr, int length)  {
    for (int i = 1; i < length; i++) { //趟数
        int j = i;
        int temp = arr[i];
        if (arr[i]<arr[i-1]) {
            while (j>0 && temp < arr[j-1]) {
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = temp;
        }
    }
    return arr;
}
void insertSortTest(){
    int a[6] = {5, 2, 4, 6, 1, 3}; //乱序
    int length = sizeof(a)/sizeof(a[0]);
    clock_t startTime, endTime;

    startTime = clock();
    for (int i = 0; i< length; i ++) {
        printf("%d\n", nsertSort(a, length)[i]);
    }
    endTime = clock();
    printf("运行时间为%ld毫秒\n", endTime - startTime);

}

