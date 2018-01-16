//
//  ABCMediaContent.h
//  ABCIMLib
//
//  Created by bingo on 2018/1/4.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import "ABCMessageContent.h"

@interface ABCMediaMessage : ABCMessageContent

/*!
 文件的本地路径
 */
@property(nonatomic, strong) NSString *filePath;

/*!
 文件的网络地址
 */
@property(nonatomic, strong) NSString *url;
/*!
 文件类型
 */
@property(nonatomic, strong) NSString *type;
/*!
 文件大小，单位为Byte
 */
@property(nonatomic, assign) long long size;

@end
