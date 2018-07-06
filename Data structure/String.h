//
//  String.h
//  Data structure
//
//  Created by yfm on 2018/7/6.
//  Copyright © 2018年 yfm. All rights reserved.
//

#ifndef String_h
#define String_h

#include <stdio.h>

typedef char * String;

int Strcmp(String p1, String p2);
int StrLength(String S);
unsigned long Strlen1(const char *str);
void SubString(String sub, String S, int pos, int len);
int Index(String S, String T, int pos);

#endif /* String_h */
