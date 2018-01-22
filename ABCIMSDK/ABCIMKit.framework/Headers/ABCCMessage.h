#import <Foundation/Foundation.h>
#import "ABCChatItem.h"
#import <ABCIMLib/ABCMessage.h>

@interface ABCCMessage : NSObject <ABCChatItem>

@property (nonatomic, strong) ABCMessage *message;

@property (nonatomic, strong) NSString *objectName;

@property (nonatomic, assign) BOOL uploading;


@end
