//
//  ABCCallDefine.h
//  ABCCallKit
//
//  Created by bingo on 2018/1/8.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#ifndef ABCCallDefine_h
#define ABCCallDefine_h

typedef enum ABCVideoAction{
    ABCVideoAction_chat           = 1,        //切换到聊天界面
    ABCVideoAction_close          = 2,        //挂断
    ABCVideoAction_switch         = 3,        //切换摄像头
    ABCVideoAction_accpet         = 4,        //接受
}ABCVideoAction;

typedef enum ABCVideoUserType{
    ABCVideoUserType_sender       = 0,        //发起视频
    ABCVideoUserType_recieve      = 1,        //接收者
}ABCVideoUserType;

typedef enum ABCVideoCMDType{
    ABCVideoCMDType_recieve      = 0,        //发起视频
    ABCVideoCMDType_accept       = 1,        //接受
    ABCVideoCMDType_refuse       = 2,        //拒绝
    ABCVideoCMDType_timeout      = 3,        //超时
    ABCVideoCMDType_cancel       = 4,        //取消
    ABCVideoCMDType_busy         = 5,        //占线
    DELETE_MSG                   = 6,        //消息撤回
}ABCVideoCMDType;


#endif /* ABCCallDefine_h */
