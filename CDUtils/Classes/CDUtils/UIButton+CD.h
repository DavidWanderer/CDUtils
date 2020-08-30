//
//  UIButton+CD.h
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (CD)

/// 扩大UIButton的点击范围，控制上右下左的额外的点击范围。
/// @param top top
/// @param right right
/// @param bottom bottom
/// @param left left
- (void)setEnlargeEdgeWithTop:(CGFloat)top right:(CGFloat)right bottom:(CGFloat)bottom left:(CGFloat)left;

@end

NS_ASSUME_NONNULL_END
