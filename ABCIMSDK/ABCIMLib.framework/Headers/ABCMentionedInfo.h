//
//  ABCMentionedInfo.h
//  ABCIMLib
//
//  Created by bingo on 2018/3/28.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

/*!
 消息中的@提醒信息
 */
@interface ABCMentionedInfo : NSObject

/*!
 @提醒的类型
 */
@property(nonatomic, assign) ABCMentionedType type;

/*!
 @的用户ID列表
 
 @discussion 如果type是@所有人，则可以传nil
 */
@property(nonatomic, strong) NSArray<NSString *> *userIdList;

/*!
 包含@提醒的消息，本地通知和远程推送显示的内容
 */
@property(nonatomic, strong) NSString *mentionedContent;

/*!
 是否@了我
 */
@property(nonatomic, readonly) BOOL isMentionedMe;

/*!
 初始化@提醒信息
 
 @param type       @提醒的类型
 @param userIdList @的用户ID列表
 @param mentionedContent @ Push 内容
 
 @return @提醒信息的对象
 */
- (instancetype)initWithMentionedType:(ABCMentionedType)type
                           userIdList:(NSArray *)userIdList
                     mentionedContent:(NSString *)mentionedContent;

+(ABCMentionedInfo *) decodeWithString:(NSString *) jsonString;

@end
