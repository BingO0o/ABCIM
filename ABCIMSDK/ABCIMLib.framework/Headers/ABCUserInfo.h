//
//  ABCUserInfo.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/19.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABCUserInfo : NSObject<NSCopying>

+(ABCUserInfo *) decodeWithString:(NSString *) jsonString;

-(id)initWithUserId:(NSString *) uid name:(NSString *) name avatarURL:(NSString *) avatarURL;
/*!
 用户ID
 */
@property(nonatomic, strong) NSString *uid;
/*!
 用户名称
 */
@property(nonatomic, strong) NSString *name;
/*!
 用户头像的URL
 */
@property(nonatomic, strong) NSString *avatarURL;
/*!
 拓展信息
 */
@property(nonatomic, strong) NSString *extra;


@end
