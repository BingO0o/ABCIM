
#import <UIKit/UIKit.h>
#import "ABCChatCollectionViewLayout.h"
#import "ABCChatItemCell.h"
#import "ABCChatInputPanel.h"

@class ABCChatContainerView;
@class ABCChatCollectionView;

NS_ASSUME_NONNULL_BEGIN

@interface ABCChatViewController : UIViewController <UICollectionViewDataSource, UICollectionViewDelegate, ABCChatCollectionViewLayoutDelegate, ABCChatInputPanelDelegate, ABCChatItemCellDelegate>

@property (nullable, nonatomic, strong) ABCChatContainerView *containerView;
@property (nullable, nonatomic, strong) UIImageView *backgroundView;

@property (nullable, nonatomic, strong) ABCChatCollectionView *collectionView;
@property (nullable, nonatomic, strong) ABCChatCollectionViewLayout *collectionLayout;
@property (nullable, nonatomic, strong) UIScrollView *collectionViewScrollToTopProxy;

// Supporting you have only one input panel. If you had custom input panels,
// this property would be a pointer which point to current panel.
@property (nullable, nonatomic, strong) ABCChatInputPanel *inputPanel;

@property (nonatomic, assign) CGFloat halfTransitionKeyboardHeight;
@property (nonatomic, assign) CGFloat keyboardHeight;
@property (nonatomic, assign) BOOL isRotating;

@property (nonatomic, assign) BOOL isInControllerTransition;


/*!
 收到的消息是否显示发送者的名字
 
 @discussion 默认值为YES。
 您可以针对群聊、单聊等不同场景，自己定制是否显示发送方的名字。
 */
@property(nonatomic) BOOL displayUserNameInCell;

//
// Pay more attention to inverted mode with layouts,
// as you see on collectionView:
//
// +------------+                +------------+
// |    ...     |                |  layout 0  |
// |  layout 2  |                |  layout 1  |
// |  layout 1  |       VS.      |  layout 2  |
// |  layout 0  |                |    ...     |
// +------------+                +------------+
//
// inverted is YES               inverted is NO
//
@property (nonatomic, strong) NSMutableArray<id<ABCChatItemCellLayout>> *layouts;

// Default is YES.
@property (nonatomic, assign, getter=isInverted) BOOL inverted;

@property (nonatomic, assign) CGFloat chatInputContainerViewDefaultHeight;
@property (nonatomic, assign) CGFloat scrollFractionalThreshold; // in [0, 1]

@property (nonatomic, assign, readonly) CGFloat cellWidth;

+ (nullable Class)cellLayoutClassForItemType:(NSString *)type;
+ (nullable Class)inputPanelClass;
- (void)registerChatItemCells;

- (void)didTapStatusBar;

- (nullable id<ABCChatItemCellLayout>)createLayoutWithItem:(id<ABCChatItem>)item;


/*!
 注册自定义消息的Cell
 
 @param cellClass     自定义消息cell的类
 @param layoutClass   自定义消息layout的类
 @param messageClass  自定义消息Cell对应的自定义消息的类，该自定义消息需要继承于RCMessageContent
 
 @discussion 此方法只注册自定义布局，注册消息类型请使用ABCIMLib实现registerMessageType。
 
 */
- (void)registerClass:(Class)cellClass layoutClass:(Class)layoutClass forMessageClass:(Class)messageClass;

@end

//
// Pay more attention to use these methods with inverted mode.
// These methods won't check or even map the relationship
// between layouts and their indexes for you.
//
@interface ABCChatViewController (ABCChanges)

- (void)insertLayouts:(NSArray<id<ABCChatItemCellLayout>> *)layouts atIndexes:(NSIndexSet *)indexes animated:(BOOL)animated;
- (void)deleteLayoutsAtIndexes:(NSIndexSet *)indexes animated:(BOOL)animated;
- (void)updateLayoutAtIndex:(NSUInteger)index toLayout:(id<ABCChatItemCellLayout>)layout animated:(BOOL)animated;

@end

//
// These scrolling methods already deal with inverted mode for you.
// For example `isScrolledAtBottom`, the `bottom` is the bottom you see on screen,
// maybe not real bottom of collectionView.
//
@interface ABCChatViewController (ABCScrolling)

- (BOOL)isCloseToTop;
- (BOOL)isScrolledAtTop;
- (void)scrollToTopAnimated:(BOOL)animated;

- (BOOL)isCloseToBottom;
- (BOOL)isScrolledAtBottom;
- (void)scrollToBottomAnimated:(BOOL)animated;

- (void)stopScrollIfNeeded;

- (void)adjustCollectionViewForSize:(CGSize)size keyboardHeight:(CGFloat)keyboardHeight inputContainerHeight:(CGFloat)inputContainerHeight scrollToBottom:(BOOL)scrollToBottom duration:(NSTimeInterval)duration animationCurve:(int)animationCurve;

@end

NS_ASSUME_NONNULL_END
