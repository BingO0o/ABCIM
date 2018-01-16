
#import <UIKit/UIKit.h>

@class ABCChatInputPanel;

NS_ASSUME_NONNULL_BEGIN

@protocol ABCChatInputPanelDelegate <NSObject>

@required
- (void)inputPanel:(ABCChatInputPanel *)inputPanel willChangeHeight:(CGFloat)height duration:(NSTimeInterval)duration animationCurve:(int)animationCurve;

@end

@interface ABCChatInputPanel : UIView

@property (nullable, nonatomic, weak) id<ABCChatInputPanelDelegate> delegate;

- (void)endInputting:(BOOL)animated;
- (void)adjustForSize:(CGSize)size keyboardHeight:(CGFloat)keyboardHeight duration:(NSTimeInterval)duration animationCurve:(int)animationCurve;
- (void)changeToSize:(CGSize)size keyboardHeight:(CGFloat)keyboardHeight duration:(NSTimeInterval)duration;

@end

NS_ASSUME_NONNULL_END
