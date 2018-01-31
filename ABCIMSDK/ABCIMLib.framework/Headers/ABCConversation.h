//
//  ABCConversation.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/22.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCStatusDefine.h"
#import "ABCMessageContent.h"
#import "ABCMessage.h"

@interface ABCConversation : NSObject

-(id) initABCConversationWithMessage:(ABCMessage *) message;

@property(nonatomic, assign) ABCConversationType conversationType;

@property(nonatomic, strong) NSString *conversationId;

/*!
 会话中最后一条消息的消息ID
 */
@property(nonatomic, assign) int lastestMessageId;

/*!
 会话中最后一条消息发送者id
 */
@property(nonatomic, strong) NSString *lastSenderUserId;


/*!
 会话中最后一条消息的内容
 */
@property(nonatomic, strong) ABCMessageContent *lastestMessage;

/*!
 会话中最后一条消息的类型名
 */
@property(nonatomic, strong) NSString *objectName;

/*!
 会话中的未读消息数量
 */
@property(nonatomic, assign) int unreadMessageCount;

@property(nonatomic, assign) long long timestamp;

@end
