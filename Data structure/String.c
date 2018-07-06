//
//  String.c
//  Data structure
//
//  Created by yfm on 2018/7/6.
//  Copyright © 2018年 yfm. All rights reserved.
//

#include "String.h"
#include <stdlib.h>

/*
 字符串比较,strcmp实现
 linux底层实现（https://code.woboq.org/userspace/glibc/string/strcmp.c.html）
 */
int Strcmp(String p1, String p2) {
    const unsigned char *s1 = (const unsigned char *)p1;
    const unsigned char *s2 = (const unsigned char *)p2;
    unsigned char c1, c2;

    do {
        c1 = (unsigned char)*s1++;
        c2 = (unsigned char)*s2++;
        if (c1 == '\0')
            return c1 - c2;
    } while (c1 == c2);

    return c1-c2;
}

/*
 获取字符串长度，strlen实现
 linux底层实现（https://code.woboq.org/userspace/glibc/string/strlen.c.html#37）
 */
int StrLength(String S) {
    int count = 0;
    while (*S++ != '\0') {
        count++;
    }

    return count;
}

/*
 strlen递归实现，不需要额外的变量
 */
unsigned long Strlen1(const char *str)
{
    return *str?(strlen(++str) + 1) : 0;
}

/*
 串S存在，1<=pos<=Strlength(S),
 且0<=len<=StrLength(S)-pos+1,
 用sub返回串S的第pos个字符起长度为len的子串
 */
void SubString(String sub, String S, int pos, int len) {

}

/*
 T为非空字符串。若主串S中第pos个字符之后存在于T相等的子串，
 则返回第一个这样的子串在S中的位置，否则返回0
 */
int Index(String S, String T, int pos) {
    return 0;
}


