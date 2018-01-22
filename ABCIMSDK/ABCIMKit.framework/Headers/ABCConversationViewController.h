//
//  ABCConversationViewController.h
//  ABCIMKit
//
//  Created by bingo on 2018/1/3.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCChatViewController.h"
#import <ABCIMLib/ABCIMLib.h>
#import <ABCIMKit/ABCPluginBoardView.h>

@interface ABCConversationViewController : ABCChatViewController

/*!
 初始化会话页面
 
 @param conversationType 会话类型
 @param targetId         目标会话ID
 
 @return 会话页面对象
 */
- (id)initWithConversationType:(ABCConversationType)conversationType targetId:(NSString *)targetId;

#pragma mark - 会话属性

@property (nonatomic, strong) ABCPluginBoardView *pluginBoardView;

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

#pragma mark - 消息操作

#pragma mark 发送消息
/*!
 发送普通消息
 
 @param messageContent 消息的内容
 */
- (void)sendMessage:(ABCMessageContent *)messageContent;

/*!
 发送媒体文件消息
 
 @param messageContent 消息的内容
 */
- (void)sendMediaMessage:(ABCMessageContent *)messageContent;

/*!
 +号菜单点击
 @param tag     按钮index
 */
-(void)pluginBoardView:(ABCPluginBoardView*)pluginBoardView clickedItemWithTag:(NSInteger)tag;

/*!
 发送文本消息
 @param content     消息内容
 */
- (void)sendTextMessage:(NSString *)content;

/*!
 发送图片消息
 @param image     图片
 */
-(void) sendImageMessage:(UIImage *) image;

/*!
 发送音频消息
 @param audioUrl        本地音频Url
 @param second          音频时长
 */
-(void) sendAudioMessage:(NSString *) audioUrl second:(int) second;

/*!
 发送视频消息
 @param videoUrl        本地视频Url
 @param image           视频封面
 @param second          视频时长
 */
-(void) sendVideoMessage:(NSString *)videoUrl imgCover:(UIImage *)image second:(long) second;

@end
