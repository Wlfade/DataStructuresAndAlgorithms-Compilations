//
//  BinaryTree.h
//  BinaryTree
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

#include <stdio.h>
//树的节点
typedef struct node{
    int data; //数据域
    struct node *left;
    struct node *right;
}Node;
//树根
typedef struct {
    Node *root;
}Tree;

int N; //记录元素个数
//插入
void insert(Tree *tree,int value); //创建树
//中序遍历
void inorder(Node *node);

Node *CreatNode(int value,Node *left,Node *right);
#endif /* BinaryTree_h */
