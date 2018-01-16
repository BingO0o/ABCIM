//
//  ABCPublicObserver.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/19.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCStatusDefine.h"
#import "ABCMessage.h"

#ifndef ABCPublicObserver_h
#define ABCPublicObserver_h

/*
 //同IM服务器连接的状态变更通知
 -(void)onConnectionStatusChanged:(ABCConnectionStatus)status {
 if (status == ConnectionStatus_Connecting) {
 self.navigationItem.title = @"连接中...";
 } else if (status == ConnectionStatus_Connected) {
 self.navigationItem.title = @"对话";
 }
 }
 */
@protocol ABCConnectionObserver <NSObject>
@optional
//同IM服务器连接的状态变更通知
-(void)onConnectionStatusChanged:(ABCConnectionStatus)status;

@end

/*!
 IMlib消息接收的监听器
 */
@protocol ABCIMClientReceiveMessageObserver <NSObject>
@optional

/*!
 接收消息的回调方法
 @param message     当前接收到的消息
 */
- (void)onReceivedMessage:(ABCMessage *)message;
@end

/*!
 IMlib VOIP消息接收的监听器
 */
@protocol ABCIMClientVoipMessageObserver <NSObject>
@optional

/*!
 接收消息的回调方法
 @param message     当前接收到的消息
 */
- (void)onReceivedVoipMessage:(ABCMessage *)message;
@end

#endif /* ABCPublicObserver_h */
