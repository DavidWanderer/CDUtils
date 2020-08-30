//
//  UIView+CD.h
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/30.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIView (CD)

@property (nonatomic) CGFloat left;
@property (nonatomic) CGFloat top;
@property (nonatomic) CGFloat right;
@property (nonatomic) CGFloat bottom;
@property (nonatomic) CGFloat width;
@property (nonatomic) CGFloat height;

@property (nonatomic) CGPoint origin;
@property (nonatomic) CGSize size;

@property (nonatomic, assign) CGFloat x;
@property (nonatomic, assign) CGFloat y;
@property (nonatomic, assign) CGFloat centerX;
@property (nonatomic, assign) CGFloat centerY;

/// 圆角的颜色
@property (nonatomic, strong)  UIColor *roundCornerColor;

/// 圆角的半径
@property (nonatomic, assign)  CGFloat roundCornerRadius;

/// 给指定View绘制虚线，绘制完后添加到View上。
/// @param lineView 需要绘制虚线的View
/// @param lineWidth 虚线的宽度
/// @param lineSpacing 虚线的间距
/// @param lineColor 虚线的颜色
+ (void)drawDashLine:(UIView *)lineView lineWidth:(int)lineWidth lineSpacing:(int)lineSpacing lineColor:(UIColor *)lineColor;

/// 设置部分圆角
/// @param corners 需要设置为圆角的角 UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
/// @param radii 需要设置的圆角大小 例如 CGSizeMake(20.0f, 20.0f)
- (void)addRoundedCorners:(UIRectCorner)corners
withRadii:(CGSize)radii;

/// 设置部分圆角
/// @param corners 需要设置为圆角的角 UIRectCornerTopLeft | UIRectCornerTopRight | UIRectCornerBottomLeft | UIRectCornerBottomRight | UIRectCornerAllCorners
/// @param radii 需要设置的圆角大小 例如 CGSizeMake(20.0f, 20.0f)
/// @param rect 需要设置的圆角view的rect
- (void)addRoundedCorners:(UIRectCorner)corners
withRadii:(CGSize)radii
 viewRect:(CGRect)rect;

@end

NS_ASSUME_NONNULL_END
