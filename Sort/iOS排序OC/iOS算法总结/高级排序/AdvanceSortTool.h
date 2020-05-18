//
//  AdvanceSortTool.h
//  iOS算法总结
//
//  Created by 王玲峰 on 5/4/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

/**
 总之，从指标来看，快速排序是性能最好的排序算法，如果求稳定的话，建议选择归并排序。


 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AdvanceSortTool : NSObject
//希尔排序
+(NSMutableArray *)shellSort:(NSMutableArray *)arr;

//堆排序
+ (NSMutableArray *)heapSort:(NSMutableArray *)arr;

//归并排序
+ (NSMutableArray *)megerSortAscendingOrderSort:(NSMutableArray *)arr;

//快速排序
+ (void)quickSortArray:(NSMutableArray *)array withLeftIndex:(NSInteger)leftIndex andRightIndex:(NSInteger)rightIndex;
@end

NS_ASSUME_NONNULL_END
