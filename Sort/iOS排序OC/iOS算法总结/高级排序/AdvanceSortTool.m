//
//  AdvanceSortTool.m
//  iOS算法总结
//
//  Created by 王玲峰 on 5/4/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#import "AdvanceSortTool.h"

@implementation AdvanceSortTool
+(NSMutableArray *)shellSort:(NSMutableArray *)arr{
    int gap = (int)arr.count / 2;
    while (gap >= 1) {
        for(int i = gap ; i < [arr count]; i++){
            NSInteger temp = [[arr objectAtIndex:i] intValue];
            int j = i;
            while (j >= gap && temp < [[arr objectAtIndex:(j - gap)] intValue]) {
                [arr replaceObjectAtIndex:j withObject:[arr objectAtIndex:j-gap]];
                j -= gap;
            }
            [arr replaceObjectAtIndex:j withObject:[NSNumber numberWithInteger:temp]];
        }
        gap = gap / 2;
    }
    /**
     希尔排序复杂度分析：
     在最坏的情况下时间复杂度仍为O(n²),而使用最优的增量在最坏的情况下却为O(n²⁄³)。需要注意的是，增量序列的最后一个增量值必须等于1才行。另外由于记录是跳跃式的移动，希尔排序并不是一种稳定的排序算法。
     */

    return arr;
}

+ (NSMutableArray *)heapSort:(NSMutableArray *)arr
{
    NSInteger i ,size;
    size = arr.count;
    //找出最大的元素放到堆顶
    for (i= arr.count/2-1; i>=0; i--) {
        [self createBiggesHeap:arr withSize:size beIndex:i];
    }
    
    while(size > 0){
        [arr exchangeObjectAtIndex:size-1 withObjectAtIndex:0]; //将根(最大) 与数组最末交换
        size -- ;//树大小减小
        [self createBiggesHeap:arr withSize:size beIndex:0];
    }
    NSLog(@"%@",arr);
    return arr;
    
    /**
     堆排序复杂度分析：

     堆排序运行时间主要是消耗在初始构建堆和在重建堆时的反复筛选上。在构建堆的过程中，对每个终端节点最多进行两次比较操作，因此整个排序堆的时间复杂度为O(n)。

     在正式排序时，第i次取堆顶记录重建堆需要用O(logi)的时间，并需要取n-1次堆顶记录，因此总体来说，堆排序的时间复杂度为O(nlogn)。由于堆排序对原始数据的排序状态并不敏感，因此它无论是最好、最坏和平均时间复杂度均为O(nlogn)。在这性能上显然要远远好过于冒泡、选择、插入的O(n²)的时间复杂度了。

     空间复杂度上，它只有一个用来交换的暂存单元，也是非常不错。不过由于记录的比较和交换是跳跃式进行，因此堆排序也是一种不稳定的排序方法。

     另外，由于初始构建堆排序需要的比较次数较多，因此，它不适合待排序序列个数较少的情况。
     */
}

+ (void)createBiggesHeap:(NSMutableArray *)list withSize:(NSInteger) size beIndex:(NSInteger)element
{
    NSInteger lchild = element *2 + 1,rchild = lchild+1; //左右子树
    while (rchild < size) { //子树均在范围内
        if ([list[element] integerValue] >= [list[lchild] integerValue] && [list[element] integerValue] >= [list[rchild]integerValue]) return; //如果比左右子树都大，完成整理
        if ([list[lchild] integerValue] > [list[rchild] integerValue]) { //如果左边最大
            [list exchangeObjectAtIndex:element withObjectAtIndex:lchild]; //把左面的提到上面
            element = lchild; //循环时整理子树
        }else{//否则右面最大
            [list exchangeObjectAtIndex:element withObjectAtIndex:rchild];
            element = rchild;
        }
        
        lchild = element * 2 +1;
        rchild = lchild + 1; //重新计算子树位置
    }
    //只有左子树且子树大于自己
    if (lchild < size && [list[lchild] integerValue] > [list[element] integerValue]) {
        [list exchangeObjectAtIndex:lchild withObjectAtIndex:element];
    }
}


+ (NSMutableArray *)megerSortAscendingOrderSort:(NSMutableArray *)arr
{
    //tempArray数组里存放ascendingArr个数组，每个数组包含一个元素
    NSMutableArray *tempArray = [NSMutableArray arrayWithCapacity:1];
    for (NSNumber *num in arr) {
        NSMutableArray *subArray = [NSMutableArray array];
        [subArray addObject:num];
        [tempArray addObject:subArray];
    }
    //开始合并为一个数组
    while (tempArray.count != 1) {
        NSInteger i = 0;
        while (i < tempArray.count - 1) {
            tempArray[i] = [self mergeArrayFirstList:tempArray[i] secondList:tempArray[i + 1]];
            [tempArray removeObjectAtIndex:i + 1];
            i++;
        }
    }
    NSLog(@"归并升序排序结果：%@", tempArray[0]);
    return tempArray;
    
    /**
     复杂度分析：

     我们来分析一下时间复杂度，一趟归并需要将1～n个相邻的元素进行两两归并，需要的时间为O(n)，整个归并排序需要进行log₂n次，因此总的时间复杂度为O(nlogn)。 这是该算法中最好、最坏和平均的时间性能。

     由于在归并过程中需要原始序列同样数量的存储空间n和递归时深度为logn的栈空间，因此空间复杂度为O(n+logn)。

     因为是两两比较，不存在跳跃，因此是一种稳定的排序算法。虽然占用内存比较多，但却是一种效率高的算法。
     */
}

+ (NSArray *)mergeArrayFirstList:(NSArray *)array1 secondList:(NSArray *)array2 {
    NSLog(@"array1:%@,array2:%@",array1,array2);
    NSMutableArray *resultArray = [NSMutableArray array];
    NSInteger firstIndex = 0, secondIndex = 0;
    while (firstIndex < array1.count && secondIndex < array2.count) {
        if ([array1[firstIndex] floatValue] < [array2[secondIndex] floatValue]) {
            [resultArray addObject:array1[firstIndex]];
            firstIndex++;
        } else {
            [resultArray addObject:array2[secondIndex]];
            secondIndex++;
        }
    }
    while (firstIndex < array1.count) {
        [resultArray addObject:array1[firstIndex]];
        firstIndex++;
    }
    while (secondIndex < array2.count) {
        [resultArray addObject:array2[secondIndex]];
        secondIndex++;
    }
    NSLog(@"resultArray:%@",resultArray);

    return resultArray.copy;
}

+ (void)quickSortArray:(NSMutableArray *)array withLeftIndex:(NSInteger)leftIndex andRightIndex:(NSInteger)rightIndex
{
    if (leftIndex >= rightIndex) {//如果数组长度为0或1时返回
        return ;
    }
    
    NSInteger i = leftIndex;
    NSInteger j = rightIndex;
    //记录比较基准数
    NSInteger key = [array[i] integerValue];
    
    while (i < j) {
        /**** 首先从右边j开始查找比基准数小的值 ***/
        while (i < j && [array[j] integerValue] >= key) {//如果比基准数大，继续查找
            j--;
        }
        //如果比基准数小，则将查找到的小值调换到i的位置
        array[i] = array[j];
        
        /**** 当在右边查找到一个比基准数小的值时，就从i开始往后找比基准数大的值 ***/
        while (i < j && [array[i] integerValue] <= key) {//如果比基准数小，继续查找
            i++;
        }
        //如果比基准数大，则将查找到的大值调换到j的位置
        array[j] = array[i];
        
    }
    
    //将基准数放到正确位置
    array[i] = @(key);
    
    /**** 递归排序 ***/
    //排序基准数左边的
    [self quickSortArray:array withLeftIndex:leftIndex andRightIndex:i - 1];
    //排序基准数右边的
    [self quickSortArray:array withLeftIndex:i + 1 andRightIndex:rightIndex];
    
    /**
     快速排序复杂度分析：

     最优的情况下，时间复杂度为O(nlogn),最坏的情况下为O(n²)。平实的情况为O(nlogn)。

     对于空间复杂度来说，主要是递归造成的栈空间的使用，最好情况，递归树的深度为log₂n,其空间复杂度也就是O(longn),最坏情况，需要进行n-1次递归调用，空间复杂度为O(n),平均情况，空间复杂度为O(logn)

     可惜的是，由于关键字的比较和交换是跳跃进行的，因此，快速排序是一种不稳定的排序方法。

     */
}
@end
