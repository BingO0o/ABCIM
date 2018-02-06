//
//  ABCGroupNotifyContent.h
//  ABCIMLib
//
//  Created by bingo on 2018/2/5.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMLib/ABCIMLib.h>

#define ABCGroupNotifacationTypeIdentifier @"ABC:GroupNotify"

@protocol ABCGroupNotifyMessageType <NSObject>

@optional
/*!
 返回群组消息类别
 @return 群组消息类别
 
 @discussion 根据自定义的具体群组消息内容来给出对应消息类别
 */
- (int)getGroupNotifyType;

- (NSString *)getGroupId;

@end

@protocol ABCGroupNotifyPersistentCompatible <NSObject>

@optional

- (ABCMessagePersistent)persistentFlag;

@end

@interface ABCGroupNotifyContent : ABCMessageContent<ABCGroupNotifyMessageType,ABCGroupNotifyPersistentCompatible>

@end
