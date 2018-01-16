//
//  ABCCall.h
//  ABCCallKit
//
//  Created by bingo on 2018/1/9.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ABCCallLib/ABCCallLib.h>
#import <ABCIMLib/ABCUserInfo.h>

@interface ABCCall : NSObject

@property(nonatomic, strong, readonly) ABCCallSession *currentCallSession;

+ (instancetype)sharedABCCall;

/*!
 当前会话类型是否支持视频通话
 
 @param conversationType 会话类型
 
 @return 是否支持视频通话
 */
- (BOOL)isVideoCallEnabled:(ABCConversationType)conversationType;

/*!
 发起视频通话
 @param targetId  目标会话ID
 */
- (void)startSingleCall:(NSString *)targetId userInfo:(ABCUserInfo *) userInfo;


#pragma mark - Utility
/*!
 弹出通话ViewController或选择成员ViewController
 
 @param viewController 通话ViewController或选择成员ViewController
 */
- (void)presentCallViewController:(UIViewController *)viewController;

- (void)dismissCallViewController:(UIViewController *)viewController;

@end
