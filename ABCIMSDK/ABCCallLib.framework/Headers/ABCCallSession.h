//
//  ABCCallSession.h
//  ABCCallLib
//
//  Created by bingo on 2018/1/9.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ABCIMLib/ABCIMlib.h>

/*!
 通话状态
 */
typedef NS_ENUM(NSInteger, ABCCallStatus) {
    /*!
     初始状态
     */
    //  RCCallIdle   = 0,
    /*!
     正在呼出
     */
    ABCCallDialing = 1,
    /*!
     正在呼入
     */
    ABCCallIncoming = 2,
    /*!
     收到一个通话呼入后，正在振铃
     */
    ABCCallRinging = 3,
    /*!
     正在通话
     */
    ABCCallActive = 4,
    /*!
     已经挂断
     */
    ABCCallHangup = 5,
};

/*!
 通话结束原因
 */
typedef NS_ENUM(NSInteger, ABCCallDisconnectReason) {
    /*!
     己方取消已发出的通话请求
     */
    ABCCallDisconnectReasonCancel = 1,
    /*!
     己方拒绝收到的通话请求
     */
    ABCCallDisconnectReasonReject = 2,
    /*!
     己方挂断
     */
    ABCCallDisconnectReasonHangup = 3,
    /*!
     己方忙碌
     */
    ABCCallDisconnectReasonBusyLine = 4,
    /*!
     己方未接听
     */
    ABCCallDisconnectReasonNoResponse = 5,
    /*!
     己方不支持
     */
    ABCCallDisconnectReasonEngineUnsupported = 6,
    /*!
     己方网络出错
     */
    ABCCallDisconnectReasonNetworkError = 7,
    
    /*!
     对方取消已发出的通话请求
     */
    ABCCallDisconnectReasonRemoteCancel = 11,
    /*!
     对方拒绝收到的通话请求
     */
    ABCCallDisconnectReasonRemoteReject = 12,
    /*!
     通话过程对方挂断
     */
    ABCCallDisconnectReasonRemoteHangup = 13,
    /*!
     对方忙碌
     */
    ABCCallDisconnectReasonRemoteBusyLine = 14,
    /*!
     对方未接听
     */
    ABCCallDisconnectReasonRemoteNoResponse = 15,
    /*!
     对方网络错误
     */
    ABCCallDisconnectReasonRemoteEngineUnsupported = 16,
    /*!
     对方网络错误
     */
    ABCCallDisconnectReasonRemoteNetworkError = 17
};

@protocol ABCCallSessionDelegate <NSObject>

@optional
/*!
 通话已接通
 */
- (void)callDidConnect;

/*!
 通话已结束
 */
- (void)callDidDisconnect;

/*!
 对端用户挂断
 
 @param userId 用户ID
 @param reason 挂断的原因
 */
- (void)remoteUserDidLeft:(NSString *)userId reason:(ABCCallDisconnectReason)reason;

- (void)remoteUserDidJoin:(NSString *)userId;

/*!
 彩铃
 */
- (void)shouldAlertForWaitingRemoteResponse;

/*!
 来电铃声
 */
- (void)shouldRingForIncomingCall;

/*!
 停止播放铃声(通话接通或挂断)
 */
- (void)shouldStopAlertAndRing;

@end
@interface ABCCallSession : NSObject

- (void) proccesABCMessage:(ABCMessage *) message;

/*!
 设置通话状态变化的监听器
 
 @param delegate 通话状态变化的监听器
 */
- (void)setDelegate:(id<ABCCallSessionDelegate>)delegate;

@property(nonatomic,strong) NSString *channelName;

/**
 * 对方用户信息
 */

@property(nonatomic,strong) ABCUserInfo *userInfo;

/**
 * 发起人
 */

@property(nonatomic,strong) NSString *senderId;


/*!
 通话的目标会话ID
 */
@property(nonatomic,strong) NSString *targetId;

/**
 * 会话类型
 */
@property(nonatomic,assign) ABCConversationType conversationType;

/**
 * 扩展字段
 */
@property(nonatomic,strong) NSString *extra;

@property(nonatomic,assign) long long reciveTime;

@property(nonatomic,assign)ABCCallStatus callStatus;


/*!
 接听来电
  */
- (void)accept;

/*!
 挂断通话
 */
- (void)hangup;

/*!
 邀请用户加入通话
 
 @param userIdList 用户ID列表（暂时只支持单个用户）
 */
- (void)inviteRemoteUsers:(NSArray *)userIdList;

/*!
 设置用户所在的视频View
 
 @param userId 用户ID（自己或他人）
 @param view   视频的View
 */
- (void)setVideoView:(UIView *)view userId:(NSString *)userId;

/*!
 切换摄像头
  */
- (void)switchCameraMode;

@end
