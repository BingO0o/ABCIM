//
//  ABCImageMessageCellLayout.h
//  ABCIMDemo
//
//  Created by bingo on 2017/12/26.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCBaseMessageCellLayout.h"
#import <ABCIMLib/ABCImageMessage.h>

@interface ABCImageMessageCellLayout : ABCBaseMessageCellLayout

@property(nonatomic, strong) ABCImageMessage *imageMessage;
@property (nonatomic, assign) CGRect imageViewFrame;

@end

