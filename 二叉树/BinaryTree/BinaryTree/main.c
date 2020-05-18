//
//  main.c
//  BinaryTree
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include <stdio.h>
#include "BinaryTree.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    Tree tree;
    tree.root = NULL;//创建一个空树
    int n = 7;
//    scanf("%d",&n);
    for (int i = 0; i < n; i++)//输入n个数并创建这个树
    {
        int temp;
//        scanf("%d",&temp);
        insert(&tree, i);
    }
    inorder(tree.root);//中序遍历
    getchar();
    return 0;

}
