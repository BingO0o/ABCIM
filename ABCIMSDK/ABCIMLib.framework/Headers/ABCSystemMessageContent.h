//
//  ABCSystemMessage.h
//  ABCIMLib
//
//  Created by bingo on 2018/1/26.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMLib/ABCIMLib.h>

@protocol ABCSystemMessageType <NSObject>

@optional
/*!
 返回系统消息类别
 @return 系统消息类别
 
 @discussion 根据自定义的具体系统消息内容来给出对应消息类别
  */
- (int)getSystemType;

- (NSString *) getMessageTarget;

@end

@protocol ABCSystemConversationType <NSObject>

@optional
/*!
 返回该类别是否生成会话
 @return 是否生成会话
 */
- (BOOL) isConversationType;

- (ABCMessagePersistent)persistentFlag;

@end

@interface ABCSystemMessageContent : ABCMessageContent<ABCSystemMessageType,ABCSystemConversationType>


@end
