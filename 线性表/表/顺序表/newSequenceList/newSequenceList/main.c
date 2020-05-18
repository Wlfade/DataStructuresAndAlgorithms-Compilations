//
//  main.c
//  newSequenceList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include <stdio.h>
#include "Sequence.h"
int main(int argc, const char * argv[]) {
    table t1=initTable();
      for (int i=1; i<=Size; i++) {
          t1.head[i-1]=i;
          t1.length++;
      }
      printf("原顺序表：\n");
      displayTable(t1);
    
      printf("删除元素1:\n");
      t1=delTable(t1, 1);
      displayTable(t1);
    
      printf("在第2的位置插入元素5:\n");
      t1=addTable(t1, 5, 2);
      displayTable(t1);
    
      printf("查找元素3的位置:\n");
      int add=selectTable(t1, 3);
      printf("%d\n",add);
    
      printf("将元素3改为6:\n");
      t1=amendTable(t1, 3, 6);
      displayTable(t1);
      return 0;
}
