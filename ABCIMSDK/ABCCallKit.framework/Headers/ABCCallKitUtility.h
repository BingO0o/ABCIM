//
//  ABCCallKitUtility.h
//  ABCCallKit
//
//  Created by bingo on 2018/1/9.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#define ABCCallHeaderLength 80.0f
#define ABCCallButtonLength 64.0f
#define ABCCallLabelHeight 25.0f
#define ABCCallVerticalMargin 32.0f
#define ABCCallHorizontalMargin 25.0f
#define ABCCallInsideMargin 5.0f

@interface ABCCallKitUtility : NSObject

+ (void)setScreenForceOn;

+ (void)clearScreenForceOnStatus;

+ (BOOL)isLandscape;

+ (NSString *)getReadableStringForMessageCell:(ABCCallDisconnectReason)hangupReason;
@end
