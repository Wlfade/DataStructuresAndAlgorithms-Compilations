//
//  QuickSort.c
//  Sort_Pracetice
//
//  Created by 单车 on 2020/5/14.
//  Copyright © 2020 单车. All rights reserved.
//

#include "QuickSort.h"
#include "MathTool.h"
/**
 切分原理：
 把一个数组切分成两个子数组的基本思想：
 1.找一个基准值，用两个指针分别指向数组的头部和尾部；
 2.先从尾部向头部开始搜索一个比基准值小的元素，搜索到即停止，并记录指针的位置；
 3.再从头部向尾部开始搜索一个比基准值大的元素，搜索到即停止，并记录指针的位置；
 4.交换当前左边指针位置和右边指针位置的元素；
 5.重复2,3,4步骤，直到左边指针的值大于右边指针的值停止。
 快速排序 不需要归并操作
 而快速排序的
 方式则是当两个数组都有序时，整个数组自然就有序了
 */

int quickCount= 0;
int partition(int *arr,int lo,int hi){
    quickCount ++;
    printf("合并次数：%d\n",quickCount);
    

    //确定分界值
    int key = arr[lo];
    printf("key:%d\n",key);
    printf("开始：");
    for (int k = lo; k<=hi; k ++) {
        printf("%d,", arr[k]);
    }
    printf("\n");
    //定义2个指针，分别指向切分元素的最小索引处和最大索引处的下一个位置
    int left = lo;
    int right = hi+1;
    //切分
    while (left <= right) {
        //先从右往左扫描，移动指针right,找到一个值比分界值小的元素，停止
        while (less(key, arr[--right])) {
            if (right == lo) {
                break;
            }
        }
        //再从左往右扫描，移动指针left,找到一个比分界值大的元素停止
        while (less(arr[++left], key)) {
            if (left == hi) {
                break;
            }
        }
        //判断 left >= right，如果是，则证明元素扫描完毕，结束循环，如果不是则交换元素即可
        if (left >= right) {
            break;
        }else{
            exchange(arr, left, right);
            
            printf("交换：");
            for (int k = lo; k<=hi; k ++) {
                printf("%d,", arr[k]);
            }
            printf("\n------\n");
        }
        
    }
    //交换分界值
    exchange(arr, lo, right);
    
    
    printf("交换分界结果：");
    for (int k = lo; k<=hi; k ++) {
        printf("%d,", arr[k]);
    }
    printf("\n------\n");
    return right;
}
////对数组arr 中 从索引 lo 到索引 hi 之间元素进行排序
void quiSort(int *arr, int lo,int hi){
    if (hi<=lo) {
//        printf("arr:%d,", arr[lo]);
        return;
    }
    //需要对数组中lo 索引到hi索引处的元素进行分组（左子组和右子组）
    int par = partition(arr, lo, hi);
    //让左子组有序
    quiSort(arr, lo, par - 1);
    //让右子组有序
    quiSort(arr, par + 1, hi);
    
}
//对数组内的元素进行排序
void quickSort(int *arr, int length){
    int lo = 0;
    int hi = length - 1;
    quiSort(arr, lo, hi);
}
void quickSortTest(){
    int a[] = { 900, 3, -58, 34, 76, 32, 43, 56,10,22};
    int length = sizeof(a)/sizeof(a[0]);
    quickSort(a, length);
    
//    printf("结果：");
//    for (int k = 0; k< length; k ++) {
//        printf("%d,", a[k]);
//    }
//    printf("\n------\n");
}
