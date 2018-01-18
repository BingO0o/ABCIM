//
//  ABCMessageContent.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/19.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ABCUserInfo.h"
#import "ABCStatusDefine.h"

@protocol ABCMessageCoding <NSObject>

@optional
/*!
 返回消息的类型名
 
 @return 消息的类型名
 
 @discussion 您定义的消息类型名，需要在各个平台上保持一致，以保证消息互通。
 
 @warning 请勿使用@"ABC_"开头的类型名，以免和SDK默认的消息名称冲突
 */
+ (NSString *)getObjectName;

/*!
 将消息内容序列化，编码成为可传输的json数据
 
 @discussion
 消息内容通过此方法，将消息中的所有数据，编码成为json数据，返回的json数据将用于网络传输。
 */
- (NSString *)encode;

/*!
 将json数据的内容反序列化，解码生成可用的消息内容
 
 @param jsonString  消息中的原始jsonString数据
 
 @discussion
 网络传输的json数据，会通过此方法解码，获取消息内容中的所有数据，生成有效的消息内容。
 */
- (void)decodeWithString:(NSString *)jsonString;

@end


/*!
 消息内容的存储协议
 
 @discussion 用于确定消息内容的存储策略。
 所有自定义消息必须实现此协议，否则将无法正常存储和使用。
 */
@protocol ABCMessagePersistentCompatible <NSObject>
@required

/*!
 返回消息的存储策略
 
 @return 消息的存储策略
 
 @discussion 指明此消息类型在本地是否存储、是否计入未读消息数。
 */
+ (ABCMessagePersistent)persistentFlag;

@end

/*!
 消息内容摘要的协议
 
 @discussion 用于在会话列表和本地通知中显示消息的摘要。
 */
@protocol ABCMessageContentView
@optional

/*!
 返回在会话列表和本地通知中显示的消息内容摘要
 
 @return 会话列表和本地通知中显示的消息内容摘要
 */
- (NSString *)conversationDigest;
 
@end

@interface ABCMessageContent : NSObject<ABCMessageCoding,ABCMessagePersistentCompatible,ABCMessageContentView>

/*!
 消息体中用户信息，也可以自定义extra字段
 */
@property(nonatomic, strong) ABCUserInfo *userInfo;

/*!
 消息通知中显示的titile
 */
@property(nonatomic, strong) NSString *pushTitle;

/*!
 消息通知中显示的content
 */
@property(nonatomic, strong) NSString *pushContent;

/*!
 消息发送者的name
 */
@property(nonatomic, strong) NSString *senderName;

/*!
 消息通知中显示的icon
 */
@property(nonatomic, strong) NSString *senderPortrait;

/*!
消息中拓展信息
*/
@property(nonatomic, strong) NSString *extra;

@end
