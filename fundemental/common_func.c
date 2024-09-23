#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 输入输出

/*
 * @brief 将字符 c 退回到输入流中
 * @param c 要退回的字符
 * 
 * @return 成功则返回该字符，失败返回EOF
 * @note 如果失败原来的流不变
 */
int ungetch(char c);

/*
 * @brief 计算字符串长度，不包含’\0’
 * @param str 字符串（必须要以'\0'结束）
 * 
 * @return 返回字符串的字符数
 * @note 返回的size_t类型是无符号的
 */
size_t  strlen( const char*  str);


/*
 * @brief 将参数src字符串拷贝至参数dest所指向的地址
 * @param dest 目标空间
 * @param src 源字符串
 * 
 * @return 返回参数dest的字符串起始地址
 * @note 源字符串必须以'\0'结束，并且会将源字符串的'\0'拷贝到目标空间
 *       如果dest所指内容空间不够大会造成缓冲区溢出错误
 */
char* strcpy(char* dest,char* src);

/*
 * @brief 拷贝src字符串的前num个字符至dest
 * @param dest 目标空间
 * @param src 源字符串
 * 
 * @return 返回参数dest的字符串起始地址
 * @note 源字符串必须要以'\0'结束
 *       目标空间必须可修改
 *       src和dest所指的内存区域不能重叠，且dest必须有足够的空间放置n个字符
 */
char* strncpy(char* dest,const char* src,size_t num);

/*
 * @brief 将参数src字符串复制到参数dest所指的字符串尾部
 * @param dest 目标字符串
 * @param src 追加字符串
 * 
 * @return 返回参数dest的字符串起始地址
 * @note 源字符串必须以'\0'结束
 *       dest最后的结束字符’\0’会被覆盖掉，并在连接后的字符串的尾部再增加一个’\0’
 *       dest与src所指的内存空间不能重叠，且dest要有足够的空间来容纳要复制的字符串
 */
char* strcat(char* dest,const char* src);



/*
 * @brief 将会从字符串src的开头拷贝n个字符到dest字符串尾部
 * @param dest 目标字符串
 * @param src 追加字符串
 * 
 * @return 返回参数dest的字符串起始地址
 * @note dest要有足够的空间来容纳要拷贝的字符串
 *       dest最后的结束字符’\0’会被覆盖掉，并在连接后的字符串的尾部再增加一个’\0’
 *       dest与src所指的内存空间不能重叠，且dest要有足够的空间来容纳要复制的字符串
 */
char* strncat (char* dest,const char* src,size_t num);