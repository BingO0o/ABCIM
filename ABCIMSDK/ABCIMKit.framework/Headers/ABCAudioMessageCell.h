//
//  ABCAudioMessageCell.h
//  ABCIMDemo
//
//  Created by bingo on 2017/12/27.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCBaseMessageCell.h"
#import <ABCIMLib/ABCMessage.h>

@interface ABCAudioMessageCell : ABCBaseMessageCell

@property (nonatomic, strong) UIImageView *unreadImageView;
@property (nonatomic, strong) UILabel *timeLengthLabel;
@property (nonatomic, strong) UIImageView *imgWave;
@property (nonatomic, strong) UILabel *createTimeLabel;

@property (nonatomic) UIActivityIndicatorView *downloadIndicatorView;
@property (nonatomic) UIActivityIndicatorView *uploadIndicatorView;

@end


@protocol ABCAudioMessageCellDelegate <ABCChatItemCellDelegate>

@optional
- (void)didPlayAudio:(ABCAudioMessageCell *)cell;

@end
