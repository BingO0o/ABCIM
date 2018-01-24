//
//  ABCVideoMessageCell.h
//  ABCIMDemo
//
//  Created by dev001 on 2018/1/8.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCBaseMessageCell.h"
#import <ABCIMLib/ABCVideoMessage.h>

@interface ABCVideoMessageCell : ABCBaseMessageCell

@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UIButton *playBtn;
@property (nonatomic, strong) UILabel *labDuration;
@property (nonatomic, strong) UIImageView *unreadImageView;
@property (nonatomic, strong) UIProgressView *progressView;

@property (nonatomic) UIActivityIndicatorView *downloadIndicatorView;
@property (nonatomic) UIActivityIndicatorView *uploadIndicatorView;

@end

@protocol ABCVideoMessageCellDelegate <ABCChatItemCellDelegate>

@optional
- (void)didPlayVideo:(ABCVideoMessageCell *)cell;

@end
