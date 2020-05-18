//
//  MegerSort.c
//  Sort_Pracetice
//
//  Created by 单车 on 2020/5/12.
//  Copyright © 2020 单车. All rights reserved.
//

#include "MegerSort.h"
#include "MathTool.h"
/**
 三个指针
 1个辅助数组

     复杂度分析：

     我们来分析一下时间复杂度，一趟归并需要将1～n个相邻的元素进行两两归并，需要的时间为O(n)，整个归并排序需要进行log₂n次，因此总的时间复杂度为O(nlogn)。 这是该算法中最好、最坏和平均的时间性能。

     由于在归并过程中需要原始序列同样数量的存储空间n和递归时深度为logn的栈空间，因此空间复杂度为O(n+logn)。

     因为是两两比较，不存在跳跃，因此是一种稳定的排序算法。虽然占用内存比较多，但却是一种效率高的算法。

 */
int *temp;
int count= 0;
void merger(int *arr, int lo,int mid,int hi){
    count ++;
    printf("合并次数：%d\n",count);
    for (int k = lo; k<= hi; k ++) {
        printf("%d,", arr[k]);
    }
    printf("\n");
    //定义三个指针
    int i = lo;
    int p1 = lo;
    int p2 = mid + 1;
    //遍历：移动指针p1和指针p2，比较对应索引处的值，找出小的那个，放到辅助数据的对应索引处
    while (p1<=mid && p2<=hi) {
        printf("p1:%d,p2:%d",arr[p1],arr[p2]);
        printf("\n");
        if (less(arr[p1], arr[p2])) {
            temp[i++] = arr[p1++];
        }else{
            temp[i++] = arr[p2++];
        }
    }
    //遍历：如果指针p2没有走完，顺序移动p2指针把对应的数据放到辅助数据的对应索引处
    while (p1<=mid) {
        temp[i++]= arr[p1++];
    }
    while (p2<=hi) {
        temp[i++]= arr[p2++];

    }
    //把辅助数组中的元素拷贝到元数组中
    for (int index = 0; index <= hi; index ++) {
        arr[index] = temp[index];
    }

    printf("结果：");
    for (int k = lo; k<=hi; k ++) {
        printf("%d,", arr[k]);
    }
    printf("\n------\n");
}
void sort(int *arr, int lo,int hi){
    if (hi<=lo) {
//        printf("arr:%d,", arr[lo]);
        return;
    }
    //对lo 到 hi 数据分组
    int mid = lo+(hi - lo)/2; //
    //对每一组数据排序
    sort(arr, lo, mid);

    sort(arr,mid+1,hi);


    //数组数据归并
    merger(arr, lo, mid, hi);
}


void megerSort(int *arr, int length){
    temp = (int *)malloc(sizeof(int)*length);
    int lo = 0;
    int hi = length - 1;
    sort(arr, lo, hi);
    
}
void megerSortTest(void){
    int a[] = { 900, 3, -58, 34, 76, 32, 43, 56,10,22};
    int length = sizeof(a)/sizeof(a[0]);
    megerSort(a, length);
//    for (int i = 0; i< length; i ++) {
//        printf("%d,", a[i]);
//    }

}




