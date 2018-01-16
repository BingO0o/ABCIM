//
//  ABCGroupNotifacationMessage.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/25.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMLib/ABCIMLib.h>

#define ABCGroupNotifacationTypeIdentifier @"ABC:GroupNotify"

//群组通知消息类型
#define NOTIFICATION_GROUP_CREATED 1 //创建群组
#define NOTIFICATION_GROUP_DISBANDED 2 //解散群组
#define NOTIFICATION_GROUP_MEMBER_ADDED 3 //添加群组成员
#define NOTIFICATION_GROUP_MEMBER_LEAVED 4 //群组成员离开
#define NOTIFICATION_GROUP_NAME_UPDATED 5 //群组名称更新

@interface ABCGroupNotifacationMessage : ABCMessageContent

@property(nonatomic,assign) int notificationType;

@property(nonatomic,strong) NSString *groupID;

@property(nonatomic,assign) int timestamp;

//created
@property(nonatomic,assign) NSString * master;
@property(nonatomic,strong) NSArray *members;
@property(nonatomic,strong) NSString *groupName;

//GROUP_MEMBER_ADDED,GROUP_MEMBER_LEAVED
@property(nonatomic,assign) NSString * member;

@end
