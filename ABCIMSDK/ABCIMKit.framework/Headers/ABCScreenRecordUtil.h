//
//  WBScreenRecordUtil.h
//  WBLiveKit
//
//  Created by bing on 2016/12/14.
//  Copyright © 2016年 wangchun. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@protocol ABCScreenRecordUtilDelegate <NSObject>

@optional
- (void)recorderDuration:(NSInteger) vDuration;
- (void)previewRecordPath:(NSString *) videPath;
- (void)megerTempVideoPathFinish;
- (void)saveCourseVideoFinish;

@end

@interface ABCScreenRecordUtil : NSObject

@property(nonatomic,strong)NSString *courseId;
@property(nonatomic,strong)NSString *courseUrl;
@property(nonatomic,strong)NSString *draftUrl;
@property(nonatomic,strong)NSString *recordName;
@property(nonatomic, assign) NSInteger videDuration;

@property (nonatomic, weak) id <ABCScreenRecordUtilDelegate> delegate;

+(instancetype)sharedInstance;

@property (assign,nonatomic) BOOL isRecording;

-(void) startScreemRecordByView:(UIView *) recordView;

-(void) startScreemRecord;

-(void) stopScreemRecord;

-(void) stopScreemRecordAndGenPreview;

-(void) pauseScreemRecord;

-(void) resumeScreemRecord;

-(void) generatePreviewRecord;

-(void) saveFinalRecordVideo;

-(void) removeTempAndPreviewVideo;

-(void) setRecordView:(UIView *) recordView;

- (UIImage*) getVideoPreViewImage:(NSURL *) videoPath;

@end
