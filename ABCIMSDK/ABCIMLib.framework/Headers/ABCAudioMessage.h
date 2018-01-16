//
//  ABCAudioMessage.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/22.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCMediaMessage.h"

#define ABCAudioMessageTypeIdentifier @"ABC:Audio"

@interface ABCAudioMessage : ABCMediaMessage

@property(nonatomic) int duration;

@end
