//
//  ABCMessage.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/19.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCMessageContent.h"
#import "ABCStatusDefine.h"

@interface ABCMessage : NSObject



/*!
 会话类型x
 */
@property(nonatomic, assign) ABCConversationType conversationType;
/*!
 消息本地id
 */
@property(nonatomic) int msgLocalID;

@property(nonatomic,strong) NSString *uuid;

/*!
 消息发送者id
 */
@property(nonatomic, strong) NSString *senderUserId;

/*!
 消息接受者id或者是群组id
 */
@property(nonatomic, strong) NSString *targetId;

/*!
 消息的发送或接收时间
 */
@property(nonatomic) long long timestamp;

/*!
 消息的发送状态
 */
@property(nonatomic, assign) ABCSentStatus sentStatus;

/*!
 消息的类型名
 */
@property(nonatomic, strong) NSString *objectName;

/*!
 消息的内容
 */
@property(nonatomic, strong) ABCMessageContent *content;

/*!
 消息的原始json数据
 */
@property(nonatomic, strong) NSString *rawContent;

/*!
 消息是否已读
 */
@property(nonatomic, assign) BOOL isRead;

@property (nonatomic, assign) BOOL outgoing;

@end
