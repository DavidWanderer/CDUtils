//
//  UIImage+CD.h
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (CD)

/// 获取指定路径下的指定图片。
/// @param imageName 图片名称
/// @param path Bundle路径地址
+ (UIImage *)imageName:(NSString *)imageName bundlePath:(NSString *)path;

/// 通过颜色生成纯色图片。
/// @param color 颜色色值
+ (UIImage *)createImageWithColor:(UIColor *)color;

/// 根据文字生成二维码。
/// @param string 文字
/// @param Imagesize 二维码尺寸
/// @param waterImagesize 二维码水印（显示在二维码中间）
+ (UIImage *)qrImageForString:(NSString *)string imageSize:(CGFloat)Imagesize logoImageSize:(CGFloat)waterImagesize;

/// 纠正图片方向。
- (UIImage *)fixOrientation;

/// 按给定的方向旋转图片。
/// @param orient 需要旋转的方向
- (UIImage*)rotate:(UIImageOrientation)orient;

/// 垂直翻转。
- (UIImage *)flipVertical;

/// 水平翻转。
- (UIImage *)flipHorizontal;

/// 将图片旋转角度。
/// @param degrees 旋转的角度
- (UIImage *)imageRotatedByDegrees:(CGFloat)degrees;

/// 将图片旋转弧度。
/// @param radians 旋转的弧度
- (UIImage *)imageRotatedByRadians:(CGFloat)radians;

/// 将UIView转成UIImage并返回图片路径,不支持tableview、collectionview等。
/// @param view 需要截图的View
/// @param landscapeLeft 图片截成横屏传YES
+ (NSString *)getViewImagePath:(UIView *)view landscapeLeft:(BOOL)landscapeLeft;

/// 将UIView转成UIImage并返回图片对象,不支持tableview、collectionview等。
/// @param theView 需要截图的View
/// @param landscapeLeft 图片截成横屏传YES
+ (UIImage *)getImageFromView:(UIView *)theView landscapeLeft:(BOOL)landscapeLeft;

@end

NS_ASSUME_NONNULL_END
