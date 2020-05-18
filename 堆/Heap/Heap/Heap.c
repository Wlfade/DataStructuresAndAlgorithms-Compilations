//
//  Heap.c
//  Heap
//
//  Created by 王玲峰 on 5/16/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#include "Heap.h"
#include <stdlib.h>
int heap_size; //堆大小
int heap_cap_size; //堆容量大小

/*返回以index为根的完全二叉树的左子树的索引，整个二叉树索引以0为开始*/
int left(int index){
    return ((index << 1)+1);
}
/*返回以index为根的完全二叉树的右子树的索引，整个二叉树索引以0为开始*/
int right(int index){
    return ((index << 1)+2);
}
/** 两个数交换 */
void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    return;
}
void build_heap(int array[],int length){
    heap_size = length;
    for (int i = ((heap_size - 1)>>1); i >= 0; --i) {
        max_heap_adjust(array, i);
    }
}
void max_heap_adjust(int array[],int index){
    int left_index = left(index);
    int right_index = right(index);
    int largest = index;
    //左子树和父节点进行对比
    if(left_index <= (heap_size-1) && array[left_index] > array[largest]){
        largest = left_index; //记录较大值的索引
    }
    //右子树和父节点进行对比
    if (right_index <= (heap_size-1)&&array[right_index]>array[largest]) {
        largest = right_index;
    }
    if (largest == index) {
        return;
    }else{
        //需要交换
        swap(&array[index], &array[largest]); //交换
        printf("调整:index:%d,largest:%d\n",index,largest);
        for (int i =0; i < heap_size; i++) {
            printf("%d\t", array[i]);
        }
        printf("\n------------\n");

        //递归调用
        max_heap_adjust(array, largest);
    }
    
}
void heap_delete(int array[],int value){
    int index = 0;
    for (index = 0; index < heap_size; index++) {
        if (array[index] == value) {
            break;
        }
    }
    array[index] =  array[heap_size -1]; //将最后的值 赋值到删除的位置处
    --heap_size;
    max_heap_adjust(array, index);
}
void heap_insert(int **array,int value){
    int index = 0;
    int parent_index = 0;
    if (heap_size + 1 > heap_cap_size) {
        *array = (int*) realloc(*array,2*INIT_ARRAY_SIZE * sizeof(int));
    }
    (*array)[heap_size] = value;  //一定要记得加上()既(*array)[heap_size] 如果写出*array[heap_size]肯定会出问题
    index = heap_size;
    heap_size++; //
    //
    while (index) {
        parent_index = ((index - 1)>>1);
        if ((*array)[parent_index]<(*array)[index]) {
            swap(&((*array)[parent_index]), &((*array)[index]));
        }
        index = parent_index;
    }
}
void heap_sort(int array[],int length){
    int old_heap_size = heap_size;
    int i;
    for (i = length - 1; i>=1; --i) {
        swap(&array[i], &array[0]);
        --heap_size;
        max_heap_adjust(array, 0);
    }
    //恢复堆的大小
    heap_size = old_heap_size;
}
void print_array(int* a , int length) {
    for (int i =0; i < length; i++) {
        printf("%d\t", a[i]);
    }
    printf("\n");
}
