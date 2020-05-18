//
//  Sequence.h
//  newSequenceList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#ifndef Sequence_h
#define Sequence_h

#include <stdio.h>
#define Size 5
typedef struct Table{
    int *head;
    int length;
    int size;
}table;

table initTable(void);

table addTable(table t,int elem,int add);
table delTable(table t,int add);
int selectTable(table t,int elem);
table amendTable(table t,int elem,int newElem);
#endif /* Sequence_h */
