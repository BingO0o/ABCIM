
#import <UIKit/UIKit.h>

@class ABCChatCollectionViewLayout;
@protocol ABCChatItemCellLayout;

NS_ASSUME_NONNULL_BEGIN

@protocol ABCChatCollectionViewLayoutDelegate <UICollectionViewDelegate>

@required
- (NSArray<id<ABCChatItemCellLayout>> *)cellLayouts;

@end

@interface ABCChatCollectionViewLayout : UICollectionViewLayout

@property (nonatomic, assign) UIEdgeInsets inset;

- (instancetype)initWithInverted:(BOOL)inverted;

- (NSArray<UICollectionViewLayoutAttributes *> *)layoutAttributesForLayouts:(NSArray<id<ABCChatItemCellLayout>> *)layouts containerWidth:(CGFloat)containerWidth maxHeight:(CGFloat)maxHeight contentHeight:(nullable CGFloat *)contentHeight;

- (BOOL)hasLayoutAttributes;

@end

NS_ASSUME_NONNULL_END
