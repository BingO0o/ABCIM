//
//  ABCCallBaseMessage.h
//  ABCCallLib
//
//  Created by bingo on 2018/1/10.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMLib/ABCIMLib.h>

@interface ABCCallBaseMessage : ABCMessageContent

@property(nonatomic, strong) NSString *channel_id;
@property(nonatomic, assign) ABCConversationType conversationType;

@end
