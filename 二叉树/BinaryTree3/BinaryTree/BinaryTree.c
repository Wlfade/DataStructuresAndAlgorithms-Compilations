//
//  BinaryTree.c
//  BinaryTree
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include "BinaryTree.h"

#include <stdlib.h>
Node *CreatNode(int value,Node *left,Node *right){
    
}
void insert(Tree *tree,int value){
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    //判断树是不是空树
    if (tree->root == NULL) {
        tree->root = node;
    }else{
        Node *temp = tree->root; //从树根开始
        while (temp!= NULL) {
            if (value < temp->data) { //小于就进入左子树
                if (temp->left == NULL) {
                    temp->left = node;
                    return;
                }
                else{
                    temp = temp->left; //继续判断
                }
            }else{ //进入右子树
                if (temp->right == NULL) {
                    temp->right = node;
                    return;
                }else{
                    temp = temp->right;
                }
            }
        }
    }
    return;
}

void inorder(Node *node) //树的中序遍历
{
    if (node != NULL) {
        inorder(node->left);
        printf("%d\n",node->data);
        inorder(node->right);
    }
}
