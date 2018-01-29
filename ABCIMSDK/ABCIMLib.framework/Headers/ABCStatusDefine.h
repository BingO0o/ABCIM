//
//  ABCStatusDefine.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/19.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>
#ifndef ABCStatusDefine_h
#define ABCStatusDefine_h


#pragma mark - 连接状态

#pragma mark ABCConnectionStatus - 网络连接状态码
typedef NS_ENUM(NSInteger, ABCConnectionStatus) {
    /*!
     未连接
     */
    ConnectionStatus_UnConnected = 0,
    /*!
     连接中
     */
    ConnectionStatus_Connecting = 1,
    /*!
     已连接
     */
    ConnectionStatus_Connected = 2,
    /*!
     连接失败
     */
    ConnectionStatus_ConnectFail = 3
};


/*!
 会话类型
 */
typedef NS_ENUM(NSUInteger, ABCConversationType) {
    /*!
     单聊
     */
    ConversationType_PRIVATE = 1,
    /*!
     群聊
     */
    ConversationType_GROUP = 2,
    
    /*!
     系统消息
     */
    ConversationType_SYSTEM = 3

};

#pragma mark ABCSentStatus - 消息的发送状态
/*!
 消息的发送状态
 */
typedef NS_ENUM(NSUInteger, ABCSentStatus) {
    /*!
     接收方
     */
    SentStatus_Revice = 0,
    /*!
     发送中
     */
    SentStatus_SENDING = 10,
    
    /*!
     发送失败
     */
    SentStatus_FAILED = 20,
    
    /*!
     已发送成功
     */
    SentStatus_SENT = 30
};

typedef NS_ENUM(NSInteger, ABCErrorCode) {
    /*!
     未知错误（预留）
     */
    ERRORCODE_UNKNOWN = -1,
    
    /*!
     当前连接不可用
     */
    ERRORCODE_CONNECT_INVALID = -2,
    
    /*!
     消息过大
     */
    ERRORCODE_MESSAGE_LENGTH_OVERFLOW = -3,
    
    /*!
     插入数据库失败
     */
    ERRORCODE_DB_ERROR = -4,
    
    /*!
     文件上传失败
     */
    ERRORCODE_FILE_UPLOAD_FAIL = -5,

    /*!
     没有对应用户信息
     */
    ERRORCODE_NO_USER_CACHE = -6,

    /*!
     文件下载失败
     */
    ERRORCODE_FILE_DOWNLOAD_FAIL = -7,
};

#pragma mark ABCMessagePersistent - 消息的存储策略
/*!
 消息的存储策略
 */
typedef NS_ENUM(NSUInteger, ABCMessagePersistent) {
    /*!
     在本地不存储，不计入未读数
     */
    MessagePersistent_NONE = 0,
    
    /*!
     在本地只存储，但不计入未读数
     */
    MessagePersistent_ISPERSISTED = 1,
    
    /*!
     在本地进行存储并计入未读数
     */
    MessagePersistent_ISCOUNTED = 2
};


typedef NS_ENUM(NSInteger, ABCSyncStatus) {
    
    /*!
     消息开始同步
     */
    SyncStatus_BEGIN = 0,
    
    /*!
     消息结束
     */
    SyncStatus_END = 1
};

#endif /* ABCStatusDefine_h */
