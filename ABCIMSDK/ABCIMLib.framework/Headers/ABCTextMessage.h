//
//  ABCTextMessage.h
//  ABCIMLib
//
//  Created by bingo on 2017/12/20.
//  Copyright © 2017年 杭州喧喧科技有限公司. All rights reserved.
//

#import <ABCIMLib/ABCIMLib.h>

#define ABCTextMessageTypeIdentifier @"ABC:Text"

@interface ABCTextMessage : ABCMessageContent

-(instancetype) initWithContent:(NSString *) content;

@property(nonatomic, strong) NSString *content;

@end
