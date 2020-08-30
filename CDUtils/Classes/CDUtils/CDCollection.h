//
//  CDCollection.h
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CDCollection : NSObject

@end

@interface NSArray (CD)

/// 根据索引获取数组中的对象，若索引越界，返回nil。
/// @param index 索引
- (id)cd_objectAtIndex:(NSUInteger)index;

/// 获取数组中的前几个对象，若索引越界，越界后不加入到返回的数组中。
/// @param objects 数据源
/// @param cnt 需要取出的对象的数量
+ (id)cd_arrayWithObjects:(const id _Nonnull [_Nullable])objects count:(NSUInteger)cnt;

@end

@interface NSMutableArray (CD)

/// 根据索引获取数组中的对象，若索引越界，返回nil。
/// @param index 索引
- (id)cd_objectAtIndex:(NSUInteger)index;

/// 向数组末尾添加对象，若对象为空，则不做操作。
/// @param anObject 需要添加的对象
- (void)cd_addObject:(id)anObject;

/// 替换数组中索引位置的对象。
/// @param index 索引位置
/// @param anObject 对象
- (void)cd_replaceObjectAtIndex:(NSUInteger)index withObject:(id)anObject;

/// 在数组中索引位置插入对象。
/// @param anObject 需要插入的对象
/// @param index 索引
- (void)cd_insertObject:(id)anObject atIndex:(NSUInteger)index;

@end

@interface NSDictionary (CD)

/// 将指定的一组Key和一组Value组成一个字典对象。
/// @param objects 指定的值对象
/// @param keys 指定的Key对象
+ (instancetype)cd_dictionaryWithObjects:(NSArray *)objects forKeys:(NSArray *)keys;

@end

@interface NSMutableDictionary (CD)

/// 根据Key替换字典中的值，若Key为空，则不做任何操作。
/// @param anObject 值
/// @param aKey Key
- (void)cd_setObject:(id)anObject forKey:(id<NSCopying>)aKey;

@end

NS_ASSUME_NONNULL_END
