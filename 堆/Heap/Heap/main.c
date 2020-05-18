//
//  main.c
//  Heap
//
//  Created by 王玲峰 on 5/16/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#include "Heap.h"

int main(int argc, const char * argv[]) {
    int i = 0;
    int a[] = {9, 3, 7, 6, 5, 1, 10, 2};
    int *array = NULL;
    array = (int *)malloc(INIT_ARRAY_SIZE*sizeof(int));
    int length = sizeof(a)/sizeof(int);
    printf("数组的长度是:%d\n", length);
    for (i = 0; i < length; ++i) {
        array[i] = a[i];
    }
    printf("原始数组为\n");
    print_array(array, length);
    printf("堆的建立后的数组\n");
    build_heap(array, length);
    print_array(array, length);
    printf("堆排序后的数组为\n");
    heap_sort(array, length);
    print_array(array, length);
    //这个地方一定要记得先构建堆，不然下面执行删除和插入有问题
    build_heap(array, length);
    printf("删除数据10后的数组\n");
    heap_delete(array, 10);
    length--;
    print_array(array, length);
    printf("插入数据10后的数组\n");
    length++;
    heap_insert(&array, 10);
    print_array(array, length);
    printf("堆排序后的数组为\n");
    heap_sort(array, length);
    print_array(array, length);
    return 0;
}
