//
//  ABCUnknownMessageCellLayout.h
//  ABCIMDemo
//
//  Created by bingo on 2017/12/28.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCBaseMessageCellLayout.h"

@interface ABCUnknownMessageCellLayout : ABCBaseMessageCellLayout

@property (nonatomic, strong, readonly) ABCCMessage *message;

@property (nonatomic, assign) CGRect backgroundImageViewFrame;
@property (nonatomic, assign) UIImage *backgroundImage;
@property (nonatomic, assign) CGRect unkonwnLabelFrame;
@property (nonatomic, strong) NSAttributedString *unKonwnAttributed;

- (instancetype)initWithChatItem:(id<ABCChatItem>)chatItem cellWidth:(CGFloat)width;
- (void)calculateLayout;

@end
