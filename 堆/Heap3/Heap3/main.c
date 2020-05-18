//
//  main.c
//  Heap3
//
//  Created by 王玲峰 on 5/16/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//https://www.bilibili.com/video/BV1Eb41147dK //教育资料
//https://blog.csdn.net/lycorisradiata__/article/details/80312590
#include <stdio.h>
void swap(int arr[],int i ,int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
//调整一个子树为二叉树的函数
void heapify(int tree[],int n,int i){
    if (i >= n) {
        return;
    }
    int c1 = 2*i + 1;
    int c2 = 2*i + 2;
    int max = i;
    if (c1 < n && tree[c1] > tree[max]) {
        max = c1;
    }
    if (c2 < n && tree[c2] > tree[max]) {
        max = c2;
    }
    if (max != i) {
        swap(tree, max, i);
        heapify(tree, n, max);
    }
}
//创建堆函数
void build_heap(int tree[],int n){
    int last_nod = n-1; //最后一个叶节点
    int parent = (last_nod-1) / 2; //最后叶节点的父节点
    int i;
    //以此调用heapify 函数
    for (i = parent; i>=0; --i) {
        heapify(tree, n, i);
    }
}
void heap_sore(int tree[],int n){
    build_heap(tree, n);
    int i;
    for (i = n - 1; i>=0; i--) {
        swap(tree, i, 0);
        heapify(tree, i, 0);
    }
}
int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    int tree[] = {4,10,2,1,5,3};
    int n = 6;
    build_heap(tree, n);
    for (int i = 0; i < n; i ++) {
        printf("%d\n",tree[i]);
    }
    
    heap_sore(tree, n);
    printf("排序\n");

    for (int i = 0; i < n; i ++) {
        printf("%d\n",tree[i]);
    }

    return 0;
}
