# 笔声SDK集成文档
[TOC]

### REVISION HISTORY
Version | Date |Changed By |Changes
------|------|------|------
0.0.1 | 2018-01-04|Bing|init

### 准备环境
请确保满足以下开发环境要求：
- Apple XCode 6.0或以上版本
- iOS 9.0或以上版本
- ABCIMLib
- ABCIMKit

### 添加ABCIMLib,ABCIMKit
- 添加ABCIMLib，ABCIMKit（使用Embedded Binaries 导入）

### pod导入
~~~
pod 'ABCIM/ABCIMLib', '~>0.0.5'
pod 'ABCIM/ABCIMKit', '~>0.0.5'
pod 'ABCIM/ABCCallLib', '~>0.0.5'
pod 'ABCIM/ABCCallKit', '~>0.0.5'
~~~

### ABCIMLib和ABCIMKit快速集成
#### 授权
sdk中授权规则建议在服务端向笔声server获得token (http://im-api.abcpen.com:5000/auth/grant)

~~~
//Authorization 生成规则:Basic $base64(appid:$hex_md5(appsecret)) 具体查看服务端文档，建议appid和appsecret 由服务端保存。

NSMutableDictionary *headers = [NSMutableDictionary dictionaryWithObject:@"application/json" forKey:@"Content-Type"];
[headers setObject:@"Basic MTo0NDk3NjBiMTIwNjEwYWMwYjNhYmRiZDk1NTI1NGVlMA==" forKey:@"Authorization"];

[urlRequest setAllHTTPHeaderFields:headers];
~~~

#### 连接服务器
~~~
/*!
与笔声IM服务器建立连接

@param token                   从您服务器端获取的token(用户身份令牌)
@param userId                  当前获得用户身份令牌的用户ID
*/
- (void) connectWithToken:(NSString *) token
userId:(int64_t) userId;
~~~

#### 发送与接收消息

连接服务器成功之后，您就可以收发消息了，下面以文本消息为例。

发送一条文本消息：
~~~
ABCTextMessage *textMessage = [[ABCTextMessage alloc] initWithContent:content];
textMessage.userInfo = self.userInfo;
ABCMessage *message = [[ABCIMClient sharedABCIMClient] sendMessage:self.chat.cType reciveId:[self.chat.targetId longLongValue] content:textMessage];
~~~

您可以通过设置来监听接收到的消息

~~~
[[ABCIMClient sharedABCIMClient] addReceiveMessageObserver:self];

~~~
#### 监听消息接收：
~~~
/*!
接收消息的回调方法
@param message     当前接收到的消息
*/
- (void)onReceivedMessage:(ABCMessage *)message;
~~~

#### 获取未读数
```
/*!
获取某个会话内的未读消息数

@param conversationType    会话类型
@param reciveId            会话目标ID
@return                    该会话内的未读消息数
*/
- (int)getUnreadCount:(ABCConversationType)conversationType reciveId:(int64_t)reciveId;
```

清除某个会话中的未读消息
```
/*!
清除某个会话中的未读消息数

@param conversationType    会话类型
@param reciveId            目标会话ID
@return                    是否清除成功
*/
- (BOOL)clearMessagesUnreadStatus:(ABCConversationType)conversationType reciveId:(int64_t)reciveId;
```

#### 获取会话列表
```
NSArray *array = [NSArray arrayWithObjects:@(ConversationType_PRIVATE),@(ConversationType_GROUP), nil];
NSArray *conversations = [[[ABCIMClient sharedABCIMClient] getConversationList:array] mutableCopy];
```

#### 插入消息
```
/*!
插入向外发送的消息

@param conversationType    会话类型
@param reciveId            目标会话ID
@param sentStatus          发送状态
@param content             消息的内容
@return                    插入的消息实体

*/
- (ABCMessage *)insertOutgoingMessage:(ABCConversationType)conversationType
reciveId:(int64_t)reciveId
sentStatus:(ABCSentStatus)sentStatus
content:(ABCMessageContent *)content;
```
```
/*!
插入接收的消息

@param conversationType    会话类型
@param senderUserId        发送者ID
@param content             消息的内容
@return                    插入的消息实体

@discussion 此方法不支持聊天室的会话类型。
*/
- (ABCMessage *)insertIncomingMessage:(ABCConversationType)conversationType
senderUserId:(int64_t)senderUserId
content:(ABCMessageContent *)content;
```

#### 读取消息列表
```
/*!
获取会话中所有消息

@param conversationType    会话类型
@param reciveId            目标会话ID
@return                    消息实体ABCMessage对象列表
*/
- (NSArray *)getHistoryMessages:(ABCConversationType)conversationType
reciveId:(int64_t)reciveId;
```
```
/*!
获取会话中，从指定消息之前、指定数量的最新消息实体

@param conversationType    会话类型
@param reciveId            目标会话ID
@param oldestMessageId     截止的消息ID
@return                    消息实体ABCMessage对象列表
*/
- (NSArray *)getHistoryMessages:(ABCConversationType)conversationType
reciveId:(int64_t)reciveId
oldestMessageId:(int) oldestMessageId
count:(int) count;
```
#### 自定义消息
1、自定义消息并注册消息类型

您需要继承 ABCCMessageContent 实现自定义消息类，并在 SDK 初始化之后，注册自定义消息。

ABCMessageContent 是消息内容类，是所有消息的基类。您可以继承此类，并实现其中的协议，来实现自定义消息。
ABCMessageContent 主要有三个协议：

编解码协议 ABCMessageCoding

在自定义消息中实现ABCMessageCoding中的方法
```
/*!
返回消息的类型名

@return 消息的类型名

@discussion 您定义的消息类型名，需要在各个平台上保持一致，以保证消息互通。

@warning 请勿使用@"ABC_"开头的类型名，以免和SDK默认的消息名称冲突
*/
+ (NSString *)getObjectName;
```

```
/*!
将消息内容序列化，编码成为可传输的json数据

@discussion
消息内容通过此方法，将消息中的所有数据，编码成为json数据，返回的json数据将用于网络传输。
*/
- (NSString *)encode;
```
```
/*!
将json数据的内容反序列化，解码生成可用的消息内容

@param jsonString  消息中的原始jsonString数据

@discussion
网络传输的json数据，会通过此方法解码，获取消息内容中的所有数据，生成有效的消息内容。
*/
- (void)decodeWithString:(NSString *)jsonString;
```

#### 自定义消息cell
您需要继承 ABCChatItemCell 实现自定义消息Cell，并在 SDK 初始化之后，注册自定义Cell。

并实现ABCChatItemCellLayout中的方法

具体请参考demo中的ABCTextMessageCell和ABCTextMessageCellLayout

#### 注册自定义消息，自定义cell
如您继承了ABCConversationViewController，只需要实现下面方法
```
/*!
注册自定义消息的Cell

@param cellClass     自定义消息cell的类
@param layoutClass   自定义消息layout的类
@param messageClass  自定义消息Cell对应的自定义消息的类，该自定义消息需要继承于RCMessageContent

@discussion 如果实现此方法，可以不用实现ABCIMLib 中的 registerMessageType。

*/
- (void)registerClass:(Class)cellClass layoutClass:(Class)layoutClass forMessageClass:(Class)messageClass;
```
注册消息
```
[self registerClass:[ABCTextMessageCell class] layoutClass:[ABCTextMessageCellLayout class] forMessageClass:[ABCTextMessage class]];
[self registerClass:[ABCImageMessageCell class] layoutClass:[ABCImageMessageCellLayout class] forMessageClass:[ABCImageMessage class]];
[self registerClass:[ABCAudioMessageCell class] layoutClass:[ABCAudioMessageCellLayout class] forMessageClass:[ABCAudioMessage class]];
[self registerClass:[ABCUnknownMessageCell class] layoutClass:[ABCUnknownMessageCellLayout class] forMessageClass:[ABCUnknownMessage class]];
[self registerClass:[ABCGroupNotifyMessageCell class] layoutClass:[ABCGroupNotifyMessageCellLayout class] forMessageClass:[ABCGroupNotifacationMessage class]];
```






