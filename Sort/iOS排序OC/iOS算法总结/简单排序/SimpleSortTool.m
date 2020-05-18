//
//  SimpleSortTool.m
//  iOS算法总结
//
//  Created by 王玲峰 on 5/4/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#import "SimpleSortTool.h"

@implementation SimpleSortTool
//冒泡排序
+(NSMutableArray *)bubbleSortWithArr:(NSMutableArray *)mutArr{
    int count  = 0;
    int forcount  = 0;
    
    for (int i = 0; i < mutArr.count; i++) {
        forcount++;
        // 依次定位左边的
        for (int j = (int)mutArr.count-2; j >= i; j--) {
            count++;
            if ([mutArr[j] intValue]< [mutArr[j+1] intValue]) {
                [mutArr exchangeObjectAtIndex:j withObjectAtIndex:j+1];
            }
        }
    }
    NSLog(@"冒泡排序总的时间复杂度为O(n²)。");
    NSLog(@"循环次数：%d",forcount);
    NSLog(@"共%d次比较",count);

    return mutArr;
}

void  bublleSort(int *arr, int length)  {
    for(int i = 0; i < length - 1; i++) { //趟数
        for(int j = 0; j < length - i - 1; j++) { //比较次数
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
//选择排序


+ (NSMutableArray *)simpleSelectionSortWithArr:(NSMutableArray *)arr{
    int min = 0, arrCount = (int)arr.count;
    for (int i = 0; i < arrCount-1; i++) {
        min = i;
        for (int j = i + 1; j < arrCount; j++) {
            if (arr[min] > arr[j]) {  /*如果有小于当前的最小值的关键字*/
                min = j;  /*将此关键字的下标赋值给min*/
            }
        }
        if (i != min) {  /*若min不等于i，说明找到最小值，交换*/
            [arr exchangeObjectAtIndex:i withObjectAtIndex:min];
        }
    }
    NSLog(@"选择排序总的时间复杂度为O(n²)。");

    return arr;
}

void  selectSort(int *arr, int length)  {
for (int i = 0; i < length - 1; i++) { //趟数
    for (int j = i + 1; j < length; j++) { //比较次数
        if (arr[i] > arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            }
        }
    }
}

//插入排序
+ (NSMutableArray *)straightInsertionSortWithArr:(NSMutableArray *)arr{
    for (int i = 1; i < arr.count; i++) {
        int j = i;  /* j是一个坑， 确定坑的位置，再把数从坑里取出来，注意顺序*/
        id temp = arr[i]; /* temp 是从坑里取数*/
        if ([arr[i] intValue]< [arr[i-1] intValue]) {  /* j > 0 防止越界。写&&前面效率更高*/
            while (j > 0 && [temp intValue] < [arr[j-1] intValue]) {
                arr[j] = arr[j-1];
                j--;
            }
            arr[j] = temp;
        }
    }
    return arr;
}
void  insertSort(int *arr, int length)  {
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
}
@end
