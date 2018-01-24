
#import <UIKit/UIKit.h>
#import "ABCChatItemCellLayout.h"

@class ABCChatItemCell;

NS_ASSUME_NONNULL_BEGIN

@protocol ABCChatItemCellDelegate <NSObject>



@end

@interface ABCChatItemCell : UICollectionViewCell

@property (nullable, nonatomic, weak) id<ABCChatItemCellDelegate> delegate;
@property (nullable, nonatomic, strong) id<ABCChatItemCellLayout> layout;
@property (nullable, nonatomic, strong) UIView *itemView;

+ (NSString *)reuseIdentifier;

@end

NS_ASSUME_NONNULL_END
