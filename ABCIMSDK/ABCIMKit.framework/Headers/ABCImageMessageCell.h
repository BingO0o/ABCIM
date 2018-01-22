//
//  ABCImageMessageCell.h
//  ABCIMDemo
//
//  Created by bingo on 2017/12/26.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCBaseMessageCell.h"


@interface ABCImageMessageCell : ABCBaseMessageCell

@property (nonatomic) UIImageView *imageView;
@property (nonatomic) UIActivityIndicatorView *activityView;

@end

@protocol ABCImageMessageCellDelegate <ABCChatItemCellDelegate>

@optional
- (void)cell:(ABCImageMessageCell *)cell didTapImage:(UIImage *)image;
@end

