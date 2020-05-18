//
//  SimpleSortTool.h
//  iOS算法总结
//
//  Created by 王玲峰 on 5/4/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface SimpleSortTool : NSObject
//
/**
冒泡排序
【冒泡排序】：相邻元素两两比较，比较完一趟，最值出现在末尾
  第1趟：依次比较相邻的两个数，不断交换（小数放前，大数放后）逐个推进，最值最后出现在第n个元素位置
  第2趟：依次比较相邻的两个数，不断交换（小数放前，大数放后）逐个推进，最值最后出现在第n-1个元素位置
   ……   ……
 第n-1趟：依次比较相邻的两个数，不断交换（小数放前，大数放后）逐个推进，最值最后出现在第2个元素位置
*/

+(NSMutableArray *)bubbleSortWithArr:(NSMutableArray *)mutArr;


/**
选择排序
  【选择排序】：最值出现在起始端
  第1趟：在n个数中找到最小(大)数与第一个数交换位置
  第2趟：在剩下n-1个数中找到最小(大)数与第二个数交换位置
  重复这样的操作...依次与第三个、第四个...数交换位置
  第n-1趟，最终可实现数据的升序（降序）排列。
*/
+ (NSMutableArray *)simpleSelectionSortWithArr:(NSMutableArray *)arr;

/**
插入排序*/
+ (NSMutableArray *)straightInsertionSortWithArr:(NSMutableArray *)arr;

@end

NS_ASSUME_NONNULL_END
