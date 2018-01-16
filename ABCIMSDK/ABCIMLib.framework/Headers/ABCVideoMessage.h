//
//  ABCVideoMessage.h
//  ABCIMLib
//
//  Created by dev001 on 2018/1/8.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMLib/ABCIMLib.h>

#define ABCVideoMessageTypeIdentifier @"ABC:Video"

@interface ABCVideoMessage : ABCMediaMessage

@property(nonatomic) int duration;
@property(nonatomic, strong) NSString *thumbUrl;//封面地址
@property(nonatomic, assign) float width;
@property(nonatomic, assign) float height;
@property(nonatomic, strong) UIImage *image;//data数据不会序列化到json数据中

@end
