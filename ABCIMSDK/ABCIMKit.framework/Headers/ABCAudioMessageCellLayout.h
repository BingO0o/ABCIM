//
//  ABCAudioMessageCellLayout.h
//  ABCIMDemo
//
//  Created by bingo on 2017/12/27.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCBaseMessageCellLayout.h"
#import <ABCIMLib/ABCAudioMessage.h>

@interface ABCAudioMessageCellLayout : ABCBaseMessageCellLayout

@property (nonatomic, assign) CGRect audioViewFrame;

@property(nonatomic, strong) ABCAudioMessage * audioMessage;

@end

