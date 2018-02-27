//
//  ABCIMDebugHelper.h
//  ABCIMLib
//
//  Created by bingo on 2018/2/27.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

#define TheAbcDebugHelper [ABCIMDebugHelper sharedDebugHelper]

@interface ABCIMDebugHelper : NSObject

+ (instancetype)sharedDebugHelper;

@property(nonatomic, assign) BOOL isDebug;

@property(nonatomic, assign) BOOL isLocalHost;


@end
