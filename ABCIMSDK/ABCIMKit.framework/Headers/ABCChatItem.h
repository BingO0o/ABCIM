

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ABCChatItem <NSObject>

@required

/*!
 消息的UUID
 */
- (NSString *)uniqueIdentifier;

/*!
 消息的类型名
 */
- (NSString *)objectName;

@end

NS_ASSUME_NONNULL_END
