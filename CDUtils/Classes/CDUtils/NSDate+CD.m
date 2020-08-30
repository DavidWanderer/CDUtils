//
//  NSDate+CD.m
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import "NSDate+CD.h"

@implementation NSDate (CD)

- (NSString *)stringWithFormat:(NSString *)format{
    NSTimeZone *timeZone=[NSTimeZone timeZoneWithName:@"UTC"];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:format];
    [formatter setTimeZone:timeZone];
    return [formatter stringFromDate:self];
}

+ (NSDate *)dateWithString:(NSString *)dateString format:(NSString *)format {
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:format];
    return [formatter dateFromString:dateString];
}

- (NSDate *)dateWithFormat:(NSString *)format{
    NSTimeZone *timeZone=[NSTimeZone timeZoneWithName:@"UTC"];
    NSDateFormatter *formatter = [[NSDateFormatter alloc] init];
    [formatter setDateFormat:format];
    [formatter setTimeZone:timeZone];
    return [formatter dateFromString:[formatter stringFromDate:self]];
}

+ (NSString *)timeStampWithDate:(NSDate *)date format:(NSString *)format{
    return [NSString stringWithFormat:@"%ld",(long)[[date dateWithFormat:format] timeIntervalSince1970]*1000];
}

+ (NSTimeInterval)timeIntervalStamp:(NSDate *)date format:(NSString *)format{
    return [[date dateWithFormat:format] timeIntervalSince1970]*1000;
}

+(NSDate *)dateWithTimeStamp:(NSString *)string format:(NSString *)format{
    NSDate *date = [NSDate dateWithTimeIntervalSince1970:[string doubleValue]/1000];
    date = [date dateWithFormat:format];
    return date;
}

@end
