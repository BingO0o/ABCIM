//
// ABCChatInputTextPanel.h
// ABCIMDemo
//
//  Created by bingo on 2017/12/26.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMKit/ABCIMKit.h>

@class ABCChatInputTextPanel;
@class HPGrowingTextView;

@protocol ABCChatInputTextPanelDelegate <ABCChatInputPanelDelegate>

@optional
- (void)didInputTextPanelStartInputting:(ABCChatInputTextPanel *)inputTextPanel;
- (void)inputTextPanel:(ABCChatInputTextPanel *)inputTextPanel requestSendText:(NSString *)text;

- (void)attachButtonClick;
- (void)micButtonClick;

/**
*  按下录音按钮开始录音
*/
- (void)didStartRecordingVoiceAction:(UIView *)recordView;

/**
 *  手指向上滑动取消录音
 */
- (void)didCancelRecordingVoiceAction:(UIView *)recordView;

/**
 *  松开手指完成录音
 */
- (void)didFinishRecoingVoiceAction:(UIView *)recordView;

/**
 *  当手指离开按钮的范围内时，主要为了通知外部的HUD
 */
- (void)didDragOutsideAction:(UIView *)recordView;

/**
 *  当手指再次进入按钮的范围内时，主要也是为了通知外部的HUD
 */
- (void)didDragInsideAction:(UIView *)recordView;

@end

@interface ABCChatInputTextPanel : ABCChatInputPanel

@property (nonatomic, strong) UIToolbar *backgroundView;

@property (nonatomic, strong) HPGrowingTextView *inputField;
@property (nonatomic, strong) UIView *inputFieldClippingContainer;
@property (nonatomic, strong) UIView *fieldBackground;

@property (nonatomic, strong) UIView *recordView;

@property (nonatomic, strong) UIButton *micButton;
@property (nonatomic, strong) UIButton *recordButton;
@property (nonatomic, strong) UIButton *faceButton;
@property (nonatomic, strong) UIButton *attachButton;

- (void)clearInputField;

@end
