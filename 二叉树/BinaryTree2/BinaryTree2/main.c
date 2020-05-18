//
//  main.c
//  BinaryTree2
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
int c_Node = 0;     //节点数
int c_Leaf = 0;     //叶子数
int depth = 0;      //二叉树高度
typedef char ElemType;
typedef struct Node         //节点
{
    ElemType data;          //节点数据
    struct Node *lchild;        //左孩子
    struct Node *rchild;        //右孩子
} biNode, *biTree;

//先序建立二叉树
void createTree(biNode **root)
{

    ElemType data;
    scanf("%c",&data);
    if(data == '#')
    {
        (*root)=NULL;
    }

    else
    {
        *root = (biNode *)malloc(sizeof(biNode));
        if((*root) == NULL)
        {
            printf("分配空间失败!\n");
            exit(0);
        }
        (*root)->data = data;
        createTree(&((*root)->lchild));
        createTree(&((*root)->rchild));
    }

}


//先序遍历二叉树
void preOrder(biNode *root)
{
    if(root)
    {
        printf("%c ",root->data);
        preOrder(root->lchild);
        preOrder(root->rchild);
    }

}


//中序遍历二叉树
void inOrder(biNode *root)
{
    if(root)
    {
        inOrder(root->lchild);
        printf("%c ",root->data);
        inOrder(root->rchild);
    }

}

//后序遍历二叉树
void postOrder(biNode *root)
{
    if(root)
    {
        postOrder(root->lchild);
        postOrder(root->rchild);
        printf("%c ",root->data);
    }
}


//统计节点数
void cal_Node(biNode *root)
{
    if(root)
    {
        c_Node++;
        cal_Node(root->lchild);
        cal_Node(root->rchild);
    }
}

//统计叶子数 方法一
void cal_Leaf(biNode *root)
{
    if(root)
    {
        if(root->lchild==NULL&&root->rchild==NULL) c_Leaf++;
        cal_Leaf(root->lchild);
        cal_Leaf(root->rchild);
    }
}

//统计叶子数 方法二
int calLeaf(biNode *root)
{
    int hl,hr;
    if(root==NULL) return 0;
    if(root)
    {
        if(root->lchild==NULL&&root->rchild==NULL) return 1;
        hl = calLeaf(root->lchild);
        hr = calLeaf(root->rchild);
    }
    return hl+hr;
}

//打印叶子数据
void printLeaf(biNode *root)
{
    if(root)
    {
        if(root->lchild==NULL&&root->rchild==NULL)
            printf("%c ",root->data);
        printLeaf(root->lchild);
        printLeaf(root->rchild);
    }
}

//计算二叉树深度(方法一）
int cal_Depth(biNode *root)
{
    if(root == NULL) return 0;
    if(root)
    {
        int hl = cal_Depth(root->lchild);
        int hr = cal_Depth(root->rchild);
        return hl>hr?hl+1:hr+1;
    }
    return 0;
}

//计算二叉树高度(方法二）
void calDepth(biNode *root, int h)
{

    if(root)
    {
        if(h > depth) depth = h;
        calDepth(root->lchild,h+1);
        calDepth(root->rchild,h+1);
    }
}

//树状打印二叉树
void print_Tree(biNode *root, int h) {

    if(root) {
        print_Tree(root->rchild, h+1);
        for(int i=0; i<h; i++) printf("--");
        printf("%c\n",root->data);
        print_Tree(root->lchild, h+1);
    }

}


int main()
{
    printf("先序输入二叉树数据(# = NULL)：");
    biNode *root;
    createTree(&root);
    printf("先序遍历结果：");
    preOrder(root);
    printf("\n\n中序遍历结果:  ");
    inOrder(root);
    printf("\n\n后序遍历结果： ");
    postOrder(root);
    cal_Node(root);
    cal_Leaf(root);
    printf("\n\n节点数: %d\n",c_Node);
    printf("\n\n叶子点数：%d\n",c_Leaf);
    printf("叶子数（方法二）：%d\n",calLeaf(root));
    printf("\n打印叶子节点: ");
    printLeaf(root);
    calDepth(root,1);
    printf("\n二叉树高度（方法一）：%d\n",cal_Depth(root));
    printf("二叉树高度（方法二）：%d\n",depth);
    printf("\n\n树状打印二叉树\n\n");
    print_Tree(root,1);


}
