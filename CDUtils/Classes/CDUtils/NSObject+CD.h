//
//  NSObject+CD.h
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSObject (CD)

/// 清除指定目录下的指定文件夹
/// @param directory 目录名
/// @param dirname 文件夹名称
-(void)clearPathDirectory:(NSSearchPathDirectory)directory dirname:(NSString *)dirname;

/// 获取磁盘总大小
+ (NSNumber *)totalDiskSpace;

/// 获取磁盘剩余空间
+ (NSNumber *)freeDiskSpace;

/// 根据路径获取文件大小
/// @param filePath 文件路径
+ (NSNumber *)getFileSizeWithfilePath:(NSString *)filePath;

/// 获取最顶层的ViewController
+ (UIViewController *)getCurrentViewController;
@end

NS_ASSUME_NONNULL_END
