//
//  ABCVideoUtil.h
//  WBLiveKit
//
//  Created by bing on 2016/12/14.
//  Copyright © 2016年 wangchun. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABCVideoUtil : NSObject

+ (void)mergeVideo:(NSString *)videoPath andAudio:(NSString *)audioPath andTarget:(id)target andAction:(SEL)action;

+ (void)removeTempFilePath:(NSString*)filePath;

+ (void)mergeVideoToOneVideoDeleteTemp:(NSArray *)tArray toStorePath:(NSString *)storePath success:(void (^)(void))successBlock failure:(void (^)(void))failureBlcok;

+ (void)mergeVideoToOneVideo:(NSArray *)tArray toStorePath:(NSString *)storePath success:(void (^)(void))successBlock failure:(void (^)(void))failureBlcok;

+ (BOOL)isTempFileExist:(NSString *) filePath;

+ (void)removeAllTempFilePath:(NSArray*) fileArray;

@end
