
#import <UIKit/UIKit.h>
#import "ABCChatItem.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ABCChatItemCellLayout <NSObject>

@property (nonatomic, strong) NSString *reuseIdentifier;
@property (nonatomic, strong) id<ABCChatItem> chatItem;
@property (nonatomic, assign) CGFloat width;
@property (nonatomic, assign) CGFloat height;

- (instancetype)initWithChatItem:(id<ABCChatItem>)chatItem cellWidth:(CGFloat)width;
- (void)calculateLayout;

@end

NS_ASSUME_NONNULL_END
