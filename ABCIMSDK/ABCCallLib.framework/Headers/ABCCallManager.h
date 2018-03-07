//
//  ABCCallManager.h
//  ABCCallLib
//
//  Created by bingo on 2018/1/9.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCCallSession.h"

/*!
 ABCCallLib全局通话呼入的监听器
 */
@protocol ABCCallReceiveDelegate <NSObject>

/*!
 接收到通话呼入的回调
 
 @param callSession 呼入的通话实体
 */
- (void)didReceiveCall:(ABCCallSession *)callSession;


@end

@interface ABCCallManager : NSObject

@property(nonatomic, assign ,readonly) BOOL isCalling;

/*!
 获取笔声ABCCallManager的核心类单例
 
 @return 笔声ABCCallManager的核心类单例
 
 @discussion 您可以通过此方法，获取ABCCallManager的单例，访问对象中的属性和方法.
 */
+ (instancetype)sharedABCCallManager;

/*!
 当前会话类型是否支持视频通话
 
 @param conversationType 会话类型
 
 @return 是否支持视频通话
 */
- (BOOL)isVideoCallEnabled:(ABCConversationType)conversationType;

/*!
 设置全局通话呼入的监听器
 
 @param delegate CallLib全局通话呼入的监听器
 */
- (void)setDelegate:(id<ABCCallReceiveDelegate>)delegate;

/*
 设置当前使用voip证书名称
 */
- (void)setVoipCerName:(NSString *) cerName;

/*!
 当前的通话会话实体
 */
@property(nonatomic, strong) ABCCallSession *callSession;

/*!
 发起一个通话
 
 @param conversationType 会话类型
 @param targetId      目标会话ID
 @param delegate         通话监听
 @param extra            附件信息
 
 @return 呼出的通话实体
 */
- (ABCCallSession *)startCall:(ABCConversationType)conversationType
                   targetId:(NSString *)targetId
                     userInfo:(ABCUserInfo *) userInfo
              sessionDelegate:(id<ABCCallSessionDelegate>)delegate
                        extra:(NSString *)extra;

@end
