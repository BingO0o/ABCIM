//
//  ABCBaseMessageCellLayout.h
//  ABCIMDemo
//
//  Created by bingo on 2017/12/26.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ABCChatItemCellLayout.h"
#import "ABCCMessage.h"

@class ABCCMessage;

@interface ABCBaseMessageCellLayout : NSObject <ABCChatItemCellLayout>

@property (nonatomic, strong) NSString *reuseIdentifier;
@property (nonatomic, strong) id<ABCChatItem> chatItem;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;

@property (nonatomic, strong, readonly) ABCCMessage *message;
@property (nonatomic, assign, readonly) BOOL isOutgoing;

@property (nonatomic, assign) UIEdgeInsets bubbleViewMargin;
@property (nonatomic, assign) CGRect bubbleViewFrame;
@property (nonatomic, assign) CGRect sentStatusViewFrame;
@property (nonatomic, assign) CGFloat avatarSize;
@property (nonatomic, assign) CGRect avatarImageViewFrame;
@property (nonatomic, assign) CGRect nameLabelFrame;
@property (nonatomic, strong) UIImage *avatarImage;
@property (nonatomic, strong) NSString *avatarUrl;
@property (nonatomic, strong) NSString *nickName;

@property (nonatomic, strong) UIImage *bubbleImage;
@property (nonatomic, strong) UIImage *highlightBubbleImage;
@property (nonatomic, assign) CGRect bubbleImageViewFrame;

@property (nonatomic, assign) BOOL isShowName;//默认不显示

- (instancetype)initWithChatItem:(id<ABCChatItem>)chatItem cellWidth:(CGFloat)width;
- (void)calculateLayout;

@end

@interface ABCBaseMessageCellLayout (ABCStyle)

+ (UIImage *)outgoingAvatarImage;
+ (UIImage *)incomingAvatarImage;

+ (UIImage *)outgoingBubbleImage;
+ (UIImage *)highlightOutgoingBubbleImage;
+ (UIImage *)incomingBubbleImage;
+ (UIImage *)highlightIncomingBubbleImage;

@end
