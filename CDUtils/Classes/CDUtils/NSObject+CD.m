//
//  NSObject+CD.m
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import "NSObject+CD.h"

@implementation NSObject (CD)

-(void)clearPathDirectory:(NSSearchPathDirectory)directory dirname:(NSString *)dirname {
    NSFileManager *manger = [NSFileManager defaultManager];
    NSString *createPath = [[NSSearchPathForDirectoriesInDomains(directory, NSUserDomainMask, YES) firstObject] stringByAppendingPathComponent:dirname];
    if ([manger fileExistsAtPath:createPath]) {
        [manger removeItemAtPath:createPath error:nil];
    }
}

+ (NSNumber *)totalDiskSpace {
    NSError *error;
    NSFileManager *manager = [NSFileManager defaultManager];
    NSDictionary *fileSystemDict = [manager attributesOfFileSystemForPath:NSHomeDirectory() error:&error];
    if (error) {
        NSLog(@"获取信息失败, error: %@",error);
        return nil;
    }
    return fileSystemDict[NSFileSystemSize];
}

+ (NSNumber *)freeDiskSpace {
    NSError *error;
    NSFileManager *fileManager = [NSFileManager defaultManager];
    NSDictionary *fileSystemDict = [fileManager attributesOfFileSystemForPath:NSHomeDirectory() error:&error];
    if (error) {
        NSLog(@"获取剩余空间失败: %@",error);
        return nil;
    }
    return fileSystemDict[NSFileSystemFreeSize];
}

+ (NSNumber *)getFileSizeWithfilePath:(NSString *)filePath {
    NSError *error;
    NSDictionary *fileDic = [[NSFileManager defaultManager] attributesOfItemAtPath:filePath error:&error];
    if (error) {
        NSLog(@"获取文件信息失败，error：%@",error);
        return nil;
    }
    return fileDic[NSFileSize];
}

+ (UIViewController *)getCurrentViewController {
    UIViewController *result = nil;
    UIWindow * window = [[UIApplication sharedApplication] keyWindow];
    //app默认windowLevel是UIWindowLevelNormal，如果不是，找到它
    if (window.windowLevel != UIWindowLevelNormal) {
        NSArray *windows = [[UIApplication sharedApplication] windows];
        for(UIWindow * tmpWin in windows) {
            if (tmpWin.windowLevel == UIWindowLevelNormal) {
                window = tmpWin;
                break;
            }
        }
    }
    id nextResponder = nil;
    UIViewController *appRootVC = window.rootViewController;
    //1、通过present弹出VC，appRootVC.presentedViewController不为nil
    if (appRootVC.presentedViewController) {
        nextResponder = appRootVC.presentedViewController;
    }
    else{
        nextResponder = appRootVC;
    }
    
    //1、tabBarController
    if ([nextResponder isKindOfClass:[UITabBarController class]]){
        UITabBarController * tabbar = (UITabBarController *)nextResponder;
        UIViewController *vc = tabbar.viewControllers[tabbar.selectedIndex];
        if ([vc isKindOfClass:[UINavigationController class]]) { // 如果是Navigation则取navigation中的最后一个vc
            UINavigationController * nav = (UINavigationController *)vc;
            result = nav.childViewControllers.lastObject;
        } else { // 如果不是Navigaytion，则直接取当前的VC
            result = vc;
        }
        
        if (!result) { // 添加此判断，当Navgation中的数组为空的时候，返回当前的Navigation
            result = nextResponder;
        }
    }else if ([nextResponder isKindOfClass:[UINavigationController class]]){
        //2、navigationController
        UIViewController * nav = (UIViewController *)nextResponder;
        result = nav.childViewControllers.lastObject;
        
        if (!result) { // 添加此判断，当Navgation中的数组为空的时候，返回当前的Navigation
            result = nextResponder;
        }
    }else{//3、viewControler
        result = nextResponder;
    }
    return result;
}

@end
