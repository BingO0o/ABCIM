
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^ABCChatCollectionViewAction)();

@interface ABCChatCollectionView : UICollectionView

@property (nullable, nonatomic, copy) ABCChatCollectionViewAction tapAction;

@end

NS_ASSUME_NONNULL_END
