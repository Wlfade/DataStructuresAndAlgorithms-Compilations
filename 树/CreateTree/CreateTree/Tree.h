//
//  Tree.h
//  CreateTree
//
//  Created by 王玲峰 on 5/15/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include <stdio.h>
#include <stdlib.h>
#define MAXNUM 0x7fffffff

typedef struct Tree{
      int value;
      struct Tree*left;
      struct Tree*right;
}BinaryTree;
//创建
BinaryTree* create(int a[],int n);
void preOrder(BinaryTree* t);
void InOrderTraverse(BinaryTree* t);
void PostOrderTraverse(BinaryTree* t);
//插入
BinaryTree * InsertNode(BinaryTree *tree,int data);
void SearchData(int targ, BinaryTree *nod);
BinaryTree *DeletNode(BinaryTree *parent, BinaryTree *cur, int DelData);
BinaryTree *delet(BinaryTree *tree,int DelData);

#endif /* Tree_h */
