//
//  ABCBaseMessageCell.h
//  ABCIMDemo
//
//  Created by bingo on 2017/12/26.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMKit/ABCChatItemCell.h>
#import "ABCCMessage.h"

@interface ABCBaseMessageCell : ABCChatItemCell

@property (nonatomic, strong) UIView *bubbleView;
@property (nonatomic, strong) UIImageView *bubbleImageView;
@property (nonatomic, strong) UIImageView *avatarImageView;
@property (nonatomic, strong) UIButton *sentStatusView;
@property (nonatomic, strong) UILabel *labNickName;

@property (nonatomic, strong) ABCMessage *message;
@property (nonatomic, assign, getter=isHighlight) BOOL hightlight;

@end


@protocol ABCBaseMessageCellDelegate <ABCChatItemCellDelegate>

@optional
- (void)bubbleViewClick:(ABCBaseMessageCell *)cell;
- (void)bubbleViewLongPress:(ABCBaseMessageCell *)cell;
- (void)sentStatusViewClick:(ABCBaseMessageCell *)cell;

@end
