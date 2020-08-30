//
//  NSDate+CD.h
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSDate (CD)

/// 日期转字符串，返回转换后的字符串。
/// @param format 日期格式
- (NSString *)stringWithFormat:(NSString *)format;;

/// 字符串转日期
/// @param dateString 日期字符串
/// @param format 日期格式
+ (NSDate *)dateWithString:(NSString *)dateString format:(NSString *)format;

/// 日期转时间戳，返回转换后的字符串。
/// @param date 需要转换的日期对象
/// @param format 日期格式
+(NSString *)timeStampWithDate:(NSDate *)date format:(NSString *)format;

/// 日期转时间戳，返回转换后的时间戳数字格式。
/// @param date 需要转换的日期对象
/// @param format 日期格式
+ (NSTimeInterval)timeIntervalStamp:(NSDate *)date format:(NSString *)format;

/// 时间戳转日期，返回日期对象
/// @param string 时间戳字符串
/// @param format 时间格式字符串
+(NSDate *)dateWithTimeStamp:(NSString *)string format:(NSString *)format;
@end

NS_ASSUME_NONNULL_END
