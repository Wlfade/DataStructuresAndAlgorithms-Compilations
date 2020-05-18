//
//  CircleLinkList.h
//  circleLinkList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#ifndef CircleLinkList_h
#define CircleLinkList_h

#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int number;
    struct node *next;
}person;

person * initLink(int n);
void findAndKillK(person *head,int k,int m);
#endif /* CircleLinkList_h */
