//
//  Tree.c
//  CreateTree
//
//  Created by 王玲峰 on 5/15/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#include "Tree.h"
BinaryTree* create(int a[],int n)
{
     BinaryTree *ptree=(BinaryTree*)malloc(sizeof(BinaryTree )*n);
     int i;
     for(i=0;i<n;i++)
     {
         ptree[i].value=a[i];//数组a只起到一个赋值的作用
         ptree[i].left=NULL;
         ptree[i].right=NULL;
     }
     for(i=0;i<=n/2-1;i++)//原来的父亲节点范围为1~n/2,现在0~n/2-1,所以注意n/2要取到等
     {
         if(2*i+1<=n-1)
             ptree[i].left=&ptree[2*i+1];//把第2*i+1个结点的地址赋给左孩子
         if(2*i+2<=n-1)
             ptree[i].right=&ptree[2*i+2];
     }
     return ptree;
}
void preOrder(BinaryTree* t)
{
    if(t==NULL) return ;
    printf("%d\n",t->value);
    preOrder(t->left);
    preOrder(t->right);
}
void InOrderTraverse(BinaryTree* t)
{
  if (t == NULL)return;

    InOrderTraverse(t->left);
    printf("%d\n", t->value);
    InOrderTraverse(t->right);
}
void PostOrderTraverse(BinaryTree* t)
{
  if (t == NULL)return;

    PostOrderTraverse(t->left);
    PostOrderTraverse(t->right);
    printf("%d\n", t->value);

}
BinaryTree * InsertNode(BinaryTree *t,int data){
    if(t==NULL){
        if ((t = (BinaryTree *)malloc(sizeof(BinaryTree)))==NULL) {
            printf("内存不足");
            exit(0);
        }
        t->value = data;
        t->left = NULL;
        t->right = NULL;
        return t;
    }
    if (data > t->value)
    {
        t->right = InsertNode(t->right, data);
    }
    else if (data < t->value)
    {
        t->left = InsertNode(t->left, data);
    }
    else if (data == t->value)
    {
        printf("不允许插入重复值\n");
        exit(0);
    }
    return t;

}
/* 查找特定值 */
void SearchData(int targ, BinaryTree *nod)
{
    if (nod != NULL)
    {
        if (nod->value == targ)
        {
            printf("查找值存在，值为%d\n", nod->value);
        }
        else if (nod->value > targ)
        {
            SearchData(targ, nod->left);    //递归查找左子树
        }
        else if (nod->value < targ)
        {
            SearchData(targ, nod->right);    //递归查找右子树
        }
    }
    else if (nod == NULL)
    {
        printf("查找值不存在\n");
    }
}

BinaryTree *delet(BinaryTree *tree,int DelData){
    if (tree == NULL)return NULL;
    else{
        if (DelData > tree->value)
        {
            tree->right = delet(tree->right, DelData);
        }
         else if (DelData < tree->value)
        {
           tree->left = delet(tree->left, DelData);
        }
         else if (DelData == tree->value)
         {
             if (tree->right == NULL) {
                 return tree->left;
             }
             if (tree->left == NULL) {
                 return tree->right;
             }
             BinaryTree *minNode = tree->right; //后继节点
             while (minNode->left != NULL) {
                 minNode = minNode->left;
             }
             BinaryTree *n = tree->right;
             while (n->left != NULL) {
                 if (n->left->left == NULL) {
                     n->left = NULL;
//                     free(n->left);
                 }else{
                     n = n->left;
                 }
             }
             minNode->left = tree->left;
             minNode->right = tree->right;
             tree = minNode;
         }
        return tree;
    }
    
    return NULL;
    
}
