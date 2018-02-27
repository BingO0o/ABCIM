//
//  Created by bing on 2017/12/22.
//  Copyright © 2017年 杭州暄暄科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABCFileCache: NSObject
+(ABCFileCache*)instance;

@property(nonatomic)NSFileManager *fileManager;

-(NSString *)storeFile:(NSData*)data forKey:(NSString*)key;

-(void)removeFileForKey:(NSString*)key;

-(NSString*)queryCacheForKey:(NSString*)key;

-(NSString*)cachePathForKey:(NSString*)key;
@end
