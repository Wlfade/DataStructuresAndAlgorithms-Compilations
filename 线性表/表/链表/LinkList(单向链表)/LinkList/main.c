//
//  main.c
//  LinkList
//
//  Created by 单车 on 2020/5/15.
//  Copyright © 2020 单车. All rights reserved.
//

#include <stdio.h>
#include "LinkList.h"
int main(int argc, const char * argv[]) {
    //初始化链表（1，2，3，4）
      printf("初始化链表为：\n");
      link *p=initLink();
      display(p);
    
      printf("在第4的位置插入元素5：\n");
      p=insertElem(p, 5, 4);
      display(p);
    
      printf("删除元素3:\n");
      p=delElem(p, 3);
      display(p);
    
      printf("查找元素2的位置为：\n");
      int address=selectElem(p, 2);
      if (address==-1) {
          printf("没有该元素");
      }else{
          printf("元素2的位置为：%d\n",address);
      }
      printf("更改第3的位置上的数据为7:\n");
      p=amendElem(p, 3, 7);
      display(p);
    
      return 0;
}
