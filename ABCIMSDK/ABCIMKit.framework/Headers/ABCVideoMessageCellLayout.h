//
//  ABCVideoMessageCellLayout.h
//  ABCIMDemo
//
//  Created by dev001 on 2018/1/8.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCBaseMessageCellLayout.h"
#import <ABCIMLib/ABCVideoMessage.h>

@interface ABCVideoMessageCellLayout : ABCBaseMessageCellLayout

@property (nonatomic, assign) CGRect videoViewFrame;

@property(nonatomic, strong) ABCVideoMessage * videoMessage;

@end

