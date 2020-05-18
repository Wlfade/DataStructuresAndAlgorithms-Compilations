//
//  Heap.h
//  Heap
//
//  Created by 王玲峰 on 5/16/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#ifndef Heap_h
#define Heap_h
#define INIT_ARRAY_SIZE 50

#include <stdio.h>


/* 函数声明 */
//创建堆
void build_heap(int array[],int length);
//堆的调整
void max_heap_adjust(int array[],int index);
//堆的删除
void heap_delete(int array[],int value);
//堆的插入
void heap_insert(int **array,int value);
//堆排序
void heap_sort(int array[],int length);
//堆打印
void print_array(int* a , int length);
#endif /* Heap_h */
