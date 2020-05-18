//
//  BinaryTree.c
//  BinaryTree2
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include "BinaryTree.h"
int CreateTree(struct TreeNode** root) {
 
    int val;
    scanf("%d", &val);
    if (val <= 0) {
        *root = NULL;
        return 0;
    }
 
    *root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    if (!root) {
        printf("创建失败\n");
    }
 
    if (val > 0) {
        (*root)->val = val;
        CreateTree(&((*root)->left));
        CreateTree(&((*root)->right));
    }
    return 0;
}
//先序
void PreOrderTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    PreOrderTree(root->left);
    PreOrderTree(root->right);
}
//中序
void PostOrderTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    PostOrderTree(root->left);
    PostOrderTree(root->right);
    printf("%d ", root->val);
}

int maxDepth(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    else {
        int maxLeft = maxDepth(root->left), maxRight = maxDepth(root->right);
        if (maxLeft > maxRight) {
            return 1 + maxLeft;
        }
        else {
            return 1 + maxRight;
        }
    }
}

int LeafNodeNum(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
 
    if (root->left == NULL&&root->right == NULL) {
        return 1;
    }
    else {
        return LeafNodeNum(root->left) + LeafNodeNum(root->right);
    }
}



