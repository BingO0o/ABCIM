//
//  ABCRecallMessage.h
//  ABCIMLib
//
//  Created by bingo on 2018/1/5.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMLib/ABCIMLib.h>

/*!
 撤回消息的类型名
 */
#define ABCRecallMessageTypeIdentifier @"ABC:Recall"

@interface ABCRecallMessage : ABCMessageContent

-(id) initRecallMessageWithMsgId:(NSString *) msgId;

/*!
 对应ABCMessage 中的uuid
 */
@property(nonatomic, strong) NSString *msgId;

@end
