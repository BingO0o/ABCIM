//
//  ABCSystemMessageCellLayout.h
//  ABCIMDemo
//
//  Created by bingo on 2017/12/26.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMKit/ABCIMKit.h>

@class ABCCMessage;

@interface ABCSystemMessageCellLayout : NSObject <ABCChatItemCellLayout>

@property (nonatomic, strong) NSString *reuseIdentifier;
@property (nonatomic, strong) id<ABCChatItem> chatItem;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;

@property (nonatomic, strong, readonly) ABCCMessage *message;

@property (nonatomic, assign) CGRect backgroundImageViewFrame;
@property (nonatomic, assign) UIImage *backgroundImage;
@property (nonatomic, assign) CGRect textLabelFrame;
@property (nonatomic, strong) NSAttributedString *attributedText;

- (instancetype)initWithChatItem:(id<ABCChatItem>)chatItem cellWidth:(CGFloat)width;
- (void)calculateLayout;

@end

@interface ABCSystemMessageCellLayout (MMStyle)

+ (UIFont *)textFont;
+ (UIColor *)textColor;
+ (UIImage *)systemMessageBackground;

@end
