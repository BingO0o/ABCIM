//
//  ABCIMClient.h
//  ABCIMSdk
//
//  Created by bingo on 2017/12/18.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>
#import "ABCPublicObserver.h"
#import "ABCMediaMessage.h"
#import "ABCUserInfo.h"
#import "ABCSystemMessageContent.h"
#import "ABCConversation.h"

@interface ABCIMClient : NSObject

/*!
 当前登录用户id
 */
@property(nonatomic, strong) NSString * currUserId;

/*!
 当前消息target,设置后会根据这个target来进行存储，查询消息（可不设置）
 */
@property(nonatomic, strong) NSString * messageTarget;

/*!
 设置当前登录用户信息，如设置此字段，在消息体传输中都会带上
 */
@property(nonatomic, strong) ABCUserInfo *currentUserInfo;

/*!
 获取笔声ABCIMClient的核心类单例
 
 @return 笔声ABCIMClient的核心类单例
 
 @discussion 您可以通过此方法，获取IMLib的单例，访问对象中的属性和方法.
 */
+ (instancetype)sharedABCIMClient;


/*!
 与笔声IM服务器建立连接
 
 @param token                   从您服务器端获取的token(用户身份令牌)
 @param deviceId                设备唯一id，跟获取accessToken是传的deviceId保持一致
 @param userId                  当前获得用户身份令牌的用户ID
 */
- (void) connectWithToken:(NSString *) token
                 deviceId:(NSString *) deviceId
                   userId:(NSString *) userId;

/*!
 断开与笔声IM服务器的连接，并不再接收远程推送
 
 @discussion
 因为SDK在前后台切换或者网络出现异常都会自动重连，会保证连接的可靠性。
 所以除非您的App逻辑需要登出，否则一般不需要调用此方法进行手动断开。
 */
- (void)logout;

/*!
 设置deviceToken，用于远程推送
 
 @param deviceToken     从系统获取到的设备号deviceToken(需要去掉空格和尖括号)
 如:
 - (void)application:(UIApplication *)application
 didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken {
 NSString *token = [deviceToken description];
 token = [token stringByReplacingOccurrencesOfString:@"<"
 withString:@""];
 token = [token stringByReplacingOccurrencesOfString:@">"
 withString:@""];
 token = [token stringByReplacingOccurrencesOfString:@" "
 withString:@""];
 [[ABCIMClient sharedABCIMClient] bindDeviceToken:token];
 }
 */
- (void)setDeviceToken:(NSString *)deviceToken cerName:(NSString *) cerName;

/*!
 设置voipToken，用于远程推送
 
 @param voipToken 使用ABCCallLib的时候需要设置
 */
- (void)setVOIPToken:(NSString *)voipToken cerName:(NSString *) cerName;

/*!
 解除deviceToken绑定
 */
-(void)unBindDeviceToken:(NSString *)deviceToken
                success:(void (^)(void))success
                failure:(void (^)(void))fail;

#pragma mark - 连接状态监听

/*!
 添加连接状态Observer
 */
-(void)addConnectionObserver:(id<ABCConnectionObserver>)ob;

/*!
 移除连接状态Observer
 */
-(void)removeConnectionObserver:(id<ABCConnectionObserver>)ob;

/*!
 添加消息接收Observer
 */
-(void)addReceiveMessageObserver:(id<ABCIMClientReceiveMessageObserver>)ob;

/*!
 移除消息接收Observer
 */
-(void)removeReceiveMessageObserver:(id<ABCIMClientReceiveMessageObserver>)ob;

/*!
 设置历史消息同步状态代理
 */
-(void)setMessageSyncStatusDelegate:(id<ABCMessageSyncStatusDelegate>) delegate;

-(void)pushVOIPObserver:(id<ABCIMClientVoipMessageObserver>)ob;

-(void)popVOIPObserver:(id<ABCIMClientVoipMessageObserver>)ob;

#pragma mark - 注册自定义消息类型

/*!
 注册自定义的消息类型
 
 @param messageClass    自定义消息的类，该自定义消息需要继承于ABCMessageContent
 
 @discussion
 如果您需要自定义消息，必须调用此方法注册该自定义消息的消息类型，否则SDK将无法识别和解析该类型消息。
 */
- (void)registerMessageType:(Class)messageClass;

/*!
 注册自定义的系统消息
 
 @param messageClass    自定义的系统消息的类，该自定义消息需要继承于ABCSystemMessageContent
  */
- (void)registerSystemMessage:(Class) messageClass;

/*!
 注册自定义的群组消息
 
 @param messageClass    自定义的群组消息的类，该自定义消息需要继承于ABCGroupNotifyContent
 */
- (void)registerGroupNotifyMessage:(Class) messageClass;

#pragma mark 消息
/*!
 发送消息
 
 @param conversationType    发送消息的会话类型
 @param targetId          发送消息的目标会话ID
 @param content             消息的内容
 @param successBlock        发送成功回调
 @param errorBlock          发送失败回调
 @return                    发送的消息实体

 */
- (ABCMessage *)sendMessage:(ABCConversationType)conversationType
                   targetId:(NSString *)targetId
                    content:(ABCMessageContent *)content
                    success:(void (^)(ABCMessage *message))successBlock
                      error:(void (^)(ABCErrorCode nErrorCode, ABCMessage *message))errorBlock;

/*!
 重发消息
 @param message    发送消息体
 @param successBlock        发送成功回调
 @param errorBlock          发送失败回调
 @return                    发送的消息实体
 */
- (ABCMessage *)resendMessage:(ABCMessage *) message
                      success:(void (^)(ABCMessage *message))successBlock
                        error:(void (^)(ABCErrorCode nErrorCode, ABCMessage *message))errorBlock;

/*!
 发送媒体消息（图片消息或文件消息）
 
 @param conversationType    发送消息的会话类型
 @param targetId          发送消息的目标会话ID
 @param content             消息的内容(必须继承与ABCMediaMessage,不然以普通Message发送)
 @param progressBlock       消息发送进度更新的回调 [progress:当前的发送进度, 0
 <= progress <= 100, message:消息实体]
 @param successBlock        发送成功回调
 @param errorBlock          发送失败回调
 */
- (ABCMessage *)sendMediaMessage:(ABCConversationType)conversationType
                      targetId:(NSString *)targetId
                         content:(ABCMessageContent *)content
                        progress:(void (^)(int progress, ABCMessage *message))progressBlock
                         success:(void (^)(ABCMessage *message))successBlock
                           error:(void (^)(ABCErrorCode nErrorCode, ABCMessage *message))errorBlock;

/*!
 重发媒体消息（图片消息或文件消息）
 
 @param message             发送消息体
 @param progressBlock       消息发送进度更新的回调 [progress:当前的发送进度, 0
 <= progress <= 100, message:消息实体]
 @param successBlock        发送成功回调
 @param errorBlock          发送失败回调
 */
- (ABCMessage *)resendMediaMessage:(ABCMessage *) message
                           success:(void (^)(ABCMessage *message))successBlock
                          progress:(void (^)(int progress, ABCMessage *message))progressBlock
                             error:(void (^)(ABCErrorCode nErrorCode, ABCMessage *message))errorBlock;


- (ABCMessage *)sendVOIPMessage:(ABCConversationType)conversationType
                     targetId:(NSString *)targetId
                        content:(ABCMessageContent *)content
                        success:(void (^)(ABCMessage *message))successBlock
                          error:(void (^)(ABCErrorCode nErrorCode, ABCMessage *message))errorBlock;


/*!
 更新本地消息内容数据
 @param message    ABCMessage
 
 @discussion 可设置媒体消息中文件信息是否已读，或者其它类型消息的ABCMessageContent
 勿修改ABCMessage 中其它属性，以免造成数据混乱
 */
- (void)updateABCMessage:(ABCMessage *) message;

/*!
 插入向外发送的消息
 
 @param conversationType    会话类型
 @param targetId          目标会话ID
 @param sentStatus          发送状态
 @param content             消息的内容
 @return                    插入的消息实体
 
 */
- (ABCMessage *)insertOutgoingMessage:(ABCConversationType)conversationType
                            targetId:(NSString *)targetId
                          sentStatus:(ABCSentStatus)sentStatus
                             content:(ABCMessageContent *)content;

/*!
 插入接收的消息
 
 @param conversationType    会话类型
 @param senderUserId        发送者ID
 @param content             消息的内容
 @return                    插入的消息实体
 
 @discussion 此方法不支持聊天室的会话类型。
 */
- (ABCMessage *)insertIncomingMessage:(ABCConversationType)conversationType
                         senderUserId:(NSString *)senderUserId
                             content:(ABCMessageContent *)content;

/*!
 获得音频或者视频本地地址
 
 @param message      当前message
 @param progress     下载进度
 @param success      如果本地没有则下载并返回进度，如果已经存在直接返回地址
 @param fail         下载失败
 */
- (void)getLocalUrlByMessage:(ABCMediaMessage *)message
                    progress:(void (^) (float progressValue))progress
                     success:(void (^) (NSString *localUrl))success
                     failure:(void (^)(id responseObject))fail __deprecated_msg("已废弃，请勿使用。");

/*!
 获得音频或者视频本地地址
 
 @param message      当前ABCMessage 体（必须是ABCMediaMessage,不然不处理）
 @param delegate     下载信息状态代理
 @discussion         设置 ABCMediaMessageDownloadDelegate 默认进入下载队列，也可以自行调用 downloadMediaFile:delegate:方法开始下载
 */
- (NSString *)getLocalUrlByMessage:(ABCMessage *)message
                          delegate:(id<ABCMediaMessageDownloadDelegate>) delegate;


/*!
 判断是否存在本地地址
 @param mediaMessage      当前ABCMediaMessage
 */
-(BOOL) hasMediaLocalFile:(ABCMediaMessage *) mediaMessage;


/*!
 获得音频或者视频本地地址
 
 @param message      当前ABCMessage 体（必须是ABCMediaMessage,不然不处理）
 @param delegate     下载信息状态代理
 @discussion         监听媒体消息下载情况
 */
- (void) downloadMediaFile:(ABCMessage *) message
            delegate:(id<ABCMediaMessageDownloadDelegate>) delegate;

#pragma mark - 会话操作
/*!
 获取会话列表
 
 @param conversationTypeList 会话类型的数组(需要将ABCConversationType转为NSNumber构建Array)
 @return                        会话ABCConversation的列表
 
 @discussion 此方法会从本地数据库中，读取会话列表。
 返回的会话列表按照时间从前往后排列，如果有置顶的会话，则置顶的会话会排列在前面。
 */
- (NSArray *)getConversationList:(NSArray *)conversationTypeList __deprecated_msg("2.*上已废弃，请勿使用。");

/*!
 获取会话列表
 
 @param conversationTypeList 会话类型的数组(需要将ABCConversationType转为NSNumber构建Array)
 @return                        会话ABCConversation的列表
 
 @discussion 此方法会从本地数据库中，读取会话列表。
 返回的会话列表按照时间从前往后排列，如果有置顶的会话，则置顶的会话会排列在前面。
 新增会话中@信息
 */
- (NSArray *)getConversations:(NSArray *)conversationTypeList;

/*!
 获取单个会话数据
 
 @param conversationType    会话类型
 @param targetId            目标会话ID
 @return                    会话的对象
 */
- (ABCConversation *)getConversation:(ABCConversationType)conversationType targetId:(NSString *)targetId;

/*!
 获取会话中所有消息
 
 @param conversationType    会话类型
 @param targetId            目标会话ID
 @return                    消息实体ABCMessage对象列表
 */
- (NSArray *)getHistoryMessages:(ABCConversationType)conversationType
                       targetId:(NSString *)targetId;

/*!
 获取会话中，从指定消息之前、指定数量的最新消息实体

 @param conversationType    会话类型
 @param targetId            目标会话ID
 @param oldestMessageId     截止的消息ID（oldestMessageId == -1 取当前最新）
 @param count               需要获取消息数量
 @return                    消息实体ABCMessage对象列表
 */
- (NSArray *)getHistoryMessages:(ABCConversationType)conversationType
                       targetId:(NSString *)targetId
                oldestMessageId:(int) oldestMessageId
                          count:(int) count;


/*!
 获取会话中，从指定消息之前、指定数量的最新消息实体
 
 @param conversationType    会话类型
 @param targetId            目标会话ID
 @param oldestMessageId     截止的消息ID（oldestMessageId == -1 取当前最新）
 @param count               需要获取消息数量
 @param isInverted          isInverted == true DESC倒序 isInverted == false: ASC正序
 @return                    消息实体ABCMessage对象列表
 */
- (NSArray *)getHistoryMessages:(ABCConversationType)conversationType
                       targetId:(NSString *)targetId
                    isInverted:(BOOL) isInverted
                oldestMessageId:(int) oldestMessageId
                          count:(int) count;

/*!
 获取会话中，从指定消息之前、指定数量，指定消息类型的最新消息实体
 
 @param conversationType    会话类型
 @param targetId            目标会话ID
 @param objectNames         消息类型
 @param oldestMessageId     截止的消息ID（oldestMessageId == -1 取当前最新）
 @param count               需要获取消息数量
 @return                    消息实体ABCMessage对象列表
 */
- (NSArray *) getHistoryMessages:(ABCConversationType)conversationType
                        targetId:(NSString *)targetId
                      objectNames:(NSArray *)objectNames
                        isForward:(BOOL) isForward
                 oldestMessageId:(int) oldestMessageId
                           count:(int) count;

/*!
 获取会话中，从指定消息之前、指定数量，指定用户发送的最新消息实体
 
 @param sender              发送者ID
 @param targetId            目标会话ID
 @param oldestMessageId     截止的消息ID（oldestMessageId == -1 取当前最新）
 @param count               需要获取消息数量
 @return                    消息实体ABCMessage对象列表
 */
- (NSArray *) getGroupMessages:(NSString *) sender
                      targetId:(NSString *)targetId
               oldestMessageId:(int) oldestMessageId
                         count:(int) count;

/*!
 获取系统消息中所有消息
 
 @param messageType    系统消息类别
 @return               系统消息实体ABCMessage对象列表
 */
- (NSArray *)getHistorySystemMessages:(int) messageType;



/*!
 消息撤回
 @param message             消息实体ABCMessage
 @param successBlock        发送成功回调
 @param errorBlock          发送失败回调
 @return                    消息实体ABCMessage
 @discussion                具体限制撤回时间点由业务层控制
 */
-(ABCMessage *) recallMessage:(ABCMessage *) message
                      success:(void (^)(ABCMessage *message))successBlock
                        error:(void (^)(ABCErrorCode nErrorCode, ABCMessage *message))errorBlock;

/*!
 删除消息
 
 @param conversationType    会话类型
 @param messageIds  消息ID的列表(msgLocalID)
 @return            是否删除成功
 
 @discussion        数据清理成功后处理下UI上的数据，或者重新获取下会话历史消息

 */
- (BOOL)deleteMessages:(ABCConversationType)conversationType
            messageIds:(NSArray *)messageIds;

/*!
 删除某个会话中的所有消息
 
 @param conversationType    会话类型
 @param targetId            目标会话ID(系统消息中请使用消息type)
 @param successBlock        成功的回调
 @param errorBlock          失败的回调
 
 @discussion                数据清理成功后处理下UI上的数据，或者重新获取下会话历史消息
  */
- (void)deleteMessages:(ABCConversationType)conversationType
              targetId:(NSString *)targetId
               success:(void (^)(void))successBlock
                 error:(void (^)(ABCErrorCode status))errorBlock;

/*!
 删除某个会话中的所有消息
 
 @param conversationType    会话类型
 @param targetId            目标会话ID(系统消息中请使用消息type)
 @return                    是否删除成功
 
 @discussion                数据清理成功后处理下UI上的数据，或者重新获取下会话历史消息
 */
- (BOOL)clearMessages:(ABCConversationType)conversationType targetId:(NSString *)targetId;

/*!
 设置会话的置顶状态
 
 @param conversationType    会话类型
 @param targetId            目标会话ID
 @param isTop               是否置顶
 @return                    设置是否成功
 */
- (BOOL)setConversationToTop:(ABCConversationType)conversationType targetId:(NSString *)targetId isTop:(BOOL)isTop;


#pragma mark - 未读消息数
/*!
 获取某个会话内的未读消息数
 
 @param conversationType    会话类型
 @param targetId            会话目标ID
 @return                    该会话内的未读消息数
 */
- (int)getUnreadCount:(ABCConversationType)conversationType targetId:(NSString *)targetId;


/*!
 获取某个类型的会话中所有的未读消息数
 
 @param conversationTypes   会话类型的数组
 @return                    该类型的会话中所有的未读消息数
 */
- (int)getUnreadCount:(NSArray *)conversationTypes;

/*!
 清除某个会话中的未读消息数
 
 @param conversationType    会话类型
 @param targetId            目标会话ID(系统消息中请使用消息type)
 @return                    是否清除成功
 */
- (BOOL)clearMessagesUnreadStatus:(ABCConversationType)conversationType targetId:(NSString *)targetId;

#pragma mark - 用户相关

/*!
 从ABCIMLib中获取缓存的用户id
 @param userId            目标用户ID
 */
- (ABCUserInfo *)getUserInfo:(NSString *)userId __deprecated_msg("已废弃，请勿使用。");

/*!
 从ABCIMLib中获取缓存用户信息
 @param userId              目标用户ID
 @param asyncDataSource     ABCUserInfoDataSource
 @param successBlock        获取成功回调
 @param errorBlock          获取失败回调
 @discussion                当IMClient中未能获取到缓存文件，请实现ABCUserInfoDataSource中方法从业务服务器中获得用户信息
 */
- (void)getUserInfo:(NSString *)userId
    asyncDataSource:(id<ABCUserInfoDataSource>) asyncDataSource
            success:(void (^)(ABCUserInfo *userInfo))successBlock
              error:(void (^)(ABCErrorCode status))errorBlock;

@end
