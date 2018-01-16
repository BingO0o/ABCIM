
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface ABCChatContainerView : UIView

@property (nullable, nonatomic, copy) void (^layoutForSize)(CGSize size);

@end

NS_ASSUME_NONNULL_END
