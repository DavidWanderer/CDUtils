//
//  UIColor+CD.h
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (CD)

/// 从十六进制字符串中获取颜色，默认alpha = 1.0。
/// @param color 颜色字符串
+ (UIColor *)colorWithHexString:(NSString *)color;

/// 从十六进制字符串中获取颜色，color字符串支持：@"#123456"、@"0X123456"、@"123456"三种格式。
/// @param color 颜色字符串
/// @param alpha 透明底值
+ (UIColor *)colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;

/// 判断十六进制字符串是否是颜色值字符串，返回YES代表是，返回NO代表不是。
/// @param color 颜色字符串
+ (BOOL)colorStatusWithHexString:(NSString *)color;

@end

NS_ASSUME_NONNULL_END
