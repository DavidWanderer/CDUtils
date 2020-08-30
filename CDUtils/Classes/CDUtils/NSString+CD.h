//
//  NSString+CD.h
//  CDUtils
//
//  Created by Hu, Yuping on 2020/8/24.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface NSString (CD)

/// 判断字符串是否为nil，非字符串类型或只包含不可见字符
/// @param str 字符串参数
+ (BOOL)isNilOrEmpty:(NSString *)str;

/// 判断手机号是否有效，返回YES：有效，返回NO：无效。
/// @param phoneNumber 手机号
+(BOOL)isValidPhoneNumber:(NSString *)phoneNumber;

/// 判断邮箱是否有效，返回YES：有效，返回NO：无效。
/// @param email 邮箱
+(BOOL)isValidEmail:(NSString *)email;

/// 判断是否是纯数字，返回YES：是，返回NO：不是。
/// @param number 字符串
+(BOOL)isValidNumber:(NSString *)number;

/// 判断是否包含汉字，返回YES：包含汉字，返回NO：不包含汉字。
/// @param string 字符串
+ (BOOL)isContainChineseCharacters:(NSString *)string;

/// 将字符串进行Base64加密，返回加密后的字符串
-(NSString *)base64Encode;

/// 将字符串进行Base64解密，返回解密后的字符串
-(NSString *)base64Decode;

/// 将字符串进行URL编码，返回编码后的字符串
-(NSString*)stringValueEncode;

/// 将URL编码的字符串进行解码，返回解码后的字符串。
-(NSString *)stringValueDecode;

/// 将字符串进行MD5加密，返回加密后的字符串。
- (NSString *)md5String;

/// 字符串sha1加密，返回加密后的字符串。
- (NSString*)sha1String;

/// 字符串sha224加密，返回加密后的字符串。
- (NSString *)sha224String;

/// 字符串sha256加密，返回加密后的字符串。
- (NSString *)sha256String;

/// 字符串sha384加密，返回加密后的字符串。
- (NSString *)sha384String;

/// 字符串sha512加密，返回加密后的字符串。
- (NSString *)sha512String;

/// 字符串aes128加密，返回加密后的字符串。
/// @param key 密钥
-(NSString *)aes128Encrypt:(NSString *)key;

/// 字符串aes128解密，返回解密后的字符串。
/// @param key 密钥
-(NSString *)aes128Decrypt:(NSString *)key;

/// 字符串aes256加密，返回加密后的字符串。
/// @param key 密钥
-(NSString *)aes256Encrypt:(NSString *)key;

/// 字符串aes256解密，返回解密后的字符串。
/// @param key 密钥
-(NSString *)aes256Decrypt:(NSString *)key;

/// 字符串RSA公钥加密，返回加密后的字符串。
/// @param pubKey 公钥
-(NSString *)rsaEncryptByPublicKey:(NSString *)pubKey;

/// 字符串RSA公钥解密，返回解密后的字符串。
/// @param pubKey 公钥
-(NSString *)rsaDecryptByPublicKey:(NSString *)pubKey;

/// 字符串RSA私钥解密，返回解密后的字符串。
/// @param privKey 私钥
-(NSString *)rsaDecryptByPrivateKey:(NSString *)privKey;

/// 字符串是否包含string，返回YES：包含，返回NO：不包含。
/// @param string 子串
- (BOOL)isContainString:(NSString *)string;

/// 国际化处理，返回国际化后的字符串。
/// @param key 国际化字符串Key
/// @param bundleNamed 国际化Bundle名称
+ (NSString *)sdkLocalizedStringForKey:(NSString *)key bundleNamed:(NSString *)bundleNamed;

/// 获取Bundle
/// @param bundleNamed Bundle名称
+ (NSBundle *)sdkBundleNamed:(NSString *)bundleNamed;

/// 字节转换为M、G字符串
/// @param bytes 字节数
+ (NSString *)dataConvertedToStringOfBytes:(long long)bytes;

/// 获取手机型号
+ (NSString *)iphoneType;

/// 判断手机是否是刘海屏，返回YES：当前是刘海屏，返回NO：当前是非刘海屏。
+ (BOOL)isIphoneX;

/// 获取手机的IP地址，必须在有网环境下获取。
+ (NSString *)deviceIPAddress;

/// json字符串转换成Object
- (id)jsonStringToObject;

/// 截取URL中的参数，并返回一个字典对象。
- (NSMutableDictionary *)getURLParameters;
@end

NS_ASSUME_NONNULL_END
