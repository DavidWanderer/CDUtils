//
//  CDCollection.m
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import "CDCollection.h"

@implementation CDCollection

@end

#pragma mark - NSArray

@implementation NSArray (CD)

- (id)cd_objectAtIndex:(NSUInteger)index {
    if (index >= self.count) {
        return nil;
    }
    return [self objectAtIndex:index];
}

+ (id)cd_arrayWithObjects:(const id _Nonnull [_Nullable])objects count:(NSUInteger)cnt {
    id validObjects[cnt];
    NSUInteger count = 0;
    for (NSUInteger i = 0; i < cnt; i++) {
        if (objects[i]) {
            validObjects[count] = objects[i];
            count++;
        } else {
            
        }
    }
    return [self arrayWithObjects:validObjects count:count];
}

@end

#pragma mark - NSMutableArray

@implementation NSMutableArray (CD)

- (id)cd_objectAtIndex:(NSUInteger)index {
    if (index >= self.count) {
        return nil;
    }
    return [self objectAtIndex:index];
}

- (void)cd_addObject:(id)anObject {
    if (!anObject) {
        return;
    }
    [self addObject:anObject];
}

- (void)cd_replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject {
    if (index >= self.count) {
        return;
    }
    if (!anObject) {
        return;
    }
    [self replaceObjectAtIndex:index withObject:anObject];
}

- (void)cd_insertObject:(id)anObject atIndex:(NSUInteger)index {
    if (index > self.count) {
        return;
    }
    if (!anObject) {
        return;
    }
    [self insertObject:anObject atIndex:index];
}

@end

#pragma mark - NSDictionary

@implementation NSDictionary (CD)
+ (instancetype)cd_dictionaryWithObjects:(NSArray *)objects forKeys:(NSArray *)keys {
    if (objects && keys) {
      return [self dictionaryWithObject:objects forKey:keys];
    }
    
    return nil;
}

@end

#pragma mark - NSMutableDictionary


@implementation NSMutableDictionary (CD)
- (void)cd_setObject:(id)anObject forKey:(id<NSCopying>)aKey {
    if (!aKey || [self isEmptyStr:aKey]) {
        return;
    }
    if (!anObject) {
        return;
    }
    [self setObject:anObject forKey:aKey];
}

- (BOOL)isEmptyStr:(id)obj {
    if ([obj isKindOfClass:[NSString class]]
        && [self isEmpty:(NSString *)obj]) {
        return YES;
    }
    return NO;
}

- (BOOL)isEmpty:(NSString *)str {
    return [self isEmptyIgnoringWhitespace:YES str:str];
}

- (BOOL)isEmptyIgnoringWhitespace:(BOOL)ignoreWhitespace str:(NSString *)str {
    NSString *toCheck = (ignoreWhitespace) ? [self stringByTrimmingWhitespace:str] : str;
    return [toCheck isEqualToString:@""];
}

- (NSString *)stringByTrimmingWhitespace:(NSString *)str {
    return [str stringByTrimmingCharactersInSet:[NSCharacterSet whitespaceCharacterSet]];
}
             
@end
