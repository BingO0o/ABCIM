//
//  ABCImageMessage.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/21.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "ABCMediaMessage.h"

#define ABCImageMessageTypeIdentifier @"ABC:Image"

@interface ABCImageMessage : ABCMediaMessage

-(instancetype) initWithImageUrl:(NSString *) imageUrl width:(float) width height:(float) height;

@property(nonatomic, strong) UIImage *image;//data数据不会序列化到json数据中
@property(nonatomic, assign) float width;
@property(nonatomic, assign) float height;

-(ABCImageMessage*)cloneWithURL:(NSString*)url;


@end
