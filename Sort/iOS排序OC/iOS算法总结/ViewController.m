//
//  ViewController.m
//  iOS算法总结
//
//  Created by 王玲峰 on 5/4/20.
//  Copyright © 2020 王玲峰. All rights reserved.
//

#import "ViewController.h"
#import "SimpleSortTool.h"
#import "AdvanceSortTool.h"
@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    NSMutableArray * arr = @[@16,@1,@2,@9,@7,@12,@5,@3,@8,@13,@10].mutableCopy;
    [self logArr:arr];

    [AdvanceSortTool megerSortAscendingOrderSort:arr];
//    [self logArr:arr];
    
    
}
- (void)logArr:(NSMutableArray * )array {
    NSString * str = @"";
    for (NSNumber * value in array) {
       str = [str stringByAppendingString:[NSString stringWithFormat:@"%zd ",[value integerValue]]];
    }
    NSLog(@"%@",str);
}


@end
