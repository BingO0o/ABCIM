//
//  ABCPluginBoardView.h
//  ABCIMDemo
//
//  Created by dev001 on 2018/1/9.
//  Copyright © 2018年 杭州喧喧科技有限公司. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef enum MenuType{
    MenuType_Image = 1,
    MenuType_Camera,
    MenuType_VideoChat,
}MenuType;

@protocol ABCPluginBoardViewDelegate;

@interface ABCPluginBoardView : UIView

@property (nonatomic, weak) id<ABCPluginBoardViewDelegate> delegate;

/*!
 当前所有的扩展项
 */
@property(nonatomic, strong, readonly) NSMutableArray *allItems;

/*!
 向扩展功能板中插入扩展项
 
 @param image 扩展项的展示图片
 @param title 扩展项的展示标题
 @param index 需要添加到的索引值
 @param tag   扩展项的唯一标示符
  */
- (void)insertItemWithImage:(UIImage*)image title:(NSString*)title atIndex:(NSInteger)index tag:(NSInteger)tag;

/*!
 添加扩展项到扩展功能板，并在显示为最后一项
 
 @param image 扩展项的展示图片
 @param title 扩展项的展示标题
 @param tag   扩展项的唯一标示符
 */
-(void)addItemWithImage:(UIImage*)image title:(NSString*)title tag:(NSInteger)tag;

/*!
 更新指定扩展项
 
 @param index 扩展项的索引值
 @param image 扩展项的展示图片
 @param title 扩展项的展示标题
 */
-(void)updateItemAtIndex:(NSInteger)index image:(UIImage*)image title:(NSString*)title;

/*!
 更新指定扩展项
 
 @param tag   扩展项的唯一标示符
 @param image 扩展项的展示图片
 @param title 扩展项的展示标题
 */
-(void)updateItemWithTag:(NSInteger)tag image:(UIImage*)image title:(NSString*)title;

/*!
 删除扩展功能板中的指定扩展项
 
 @param index 指定扩展项的索引值
 */
- (void)removeItemAtIndex:(NSInteger)index;

/*!
 删除扩展功能板中的指定扩展项
 
 @param tag 指定扩展项的唯一标示符
 */
- (void)removeItemWithTag:(NSInteger)tag;

/*!
 删除扩展功能板中的所有扩展项
 */
- (void)removeAllItems;

@end



@protocol ABCPluginBoardViewDelegate<NSObject>

@optional
/*!
 点击扩展功能板中的扩展项的回调
 
 @param pluginBoardView 当前扩展功能板
 @param tag             点击的扩展项的唯一标示符
 */
-(void)pluginBoardView:(ABCPluginBoardView*)pluginBoardView clickedItemWithTag:(NSInteger)tag;

@end


