//
//  main.c
//  CreateTree
//
//  Created by 王玲峰 on 5/15/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#include <stdio.h>
#include "Tree.h"

int main(int argc, const char * argv[]) {
    int a[]={3,4,5,8,9,10};
    BinaryTree *root=NULL;
    root=create(a,sizeof(a)/sizeof(a[0]));
    preOrder(root);
    return 0;

}
