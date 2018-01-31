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
#import "ABCBaseMessageCell.h"

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

/*!
 加载消息
 */
- (void)loadMessages;

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
 +气泡点击事件
 @param cell ABCBaseMessageCell
 */
- (void)bubbleViewClick:(ABCBaseMessageCell *)cell;

/*!
+气泡长按事件
@param cell ABCBaseMessageCell
*/
- (void)bubbleViewLongPress:(ABCBaseMessageCell *)cell;

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
