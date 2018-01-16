//
//  ABCConversationViewController.h
//  ABCIMKit
//
//  Created by bingo on 2018/1/3.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMKit/ABCIMKit.h>
#import <ABCIMLib/ABCIMLib.h>

@interface ABCConversationViewController : ABCChatViewController

/*!
 初始化会话页面
 
 @param conversationType 会话类型
 @param targetId         目标会话ID
 
 @return 会话页面对象
 */
- (id)initWithConversationType:(ABCConversationType)conversationType targetId:(NSString *)targetId;

#pragma mark - 会话属性

/*!
 当前会话的会话类型
 */
@property(nonatomic) ABCConversationType conversationType;

/*!
 目标会话ID
 */
@property(nonatomic, strong) NSString *targetId;


#pragma mark - 自定义消息
/*!
 注册自定义消息的Cell
 
 @param cellClass     自定义消息cell的类
 @param layoutClass   自定义消息layout的类
 @param messageClass  自定义消息Cell对应的自定义消息的类，该自定义消息需要继承于RCMessageContent
 
 @discussion 如果实现此方法，可以不用实现ABCIMLib 中的 registerMessageType。

 */
- (void)registerClass:(Class)cellClass layoutClass:(Class)layoutClass forMessageClass:(Class)messageClass;

@end
