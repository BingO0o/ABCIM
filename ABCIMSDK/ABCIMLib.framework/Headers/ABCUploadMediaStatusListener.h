//
//  ABCUploadMediaStatusListener.h
//  ABCIMLib
//
//  Created by bingo on 2018/1/4.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCMessage.h"
#import <Foundation/Foundation.h>

@interface ABCUploadMediaStatusListener : NSObject

/*!
 上传的媒体文件消息的消息实体
 */
@property(nonatomic, strong) ABCMessage *currentMessage;

/*!
 更新上传进度需要调用的block [progress:当前上传的进度，0 <= progress < 100]
 */
@property(nonatomic, strong) void (^updateBlock)(int progress);

@property(nonatomic, strong) void (^successBlock)(ABCMessageContent *content);

@property(nonatomic, strong) void (^errorBlock)(ABCErrorCode errorCode);

/*!
 上传取消需要调用的block
 */
@property(nonatomic, strong) void (^cancelBlock)(void);

@end
