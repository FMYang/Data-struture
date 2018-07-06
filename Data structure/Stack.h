//
//  Stack.h
//  Data structure
//
//  Created by yfm on 2018/7/6.
//  Copyright © 2018年 yfm. All rights reserved.
//
//  栈是限定仅在表尾进行插入和删除操作的线性表

/* 顺序存储
 有4个元素的栈            空栈
 ----     <-- top      ----
 |a4|  3               |  |
 ____                  ____
 |a3|  2               |  |
 ____                  ____    <-- top
 |a2|  1
 ____
 |a1|  0
 ____
*/


/* 链式存储
 --------    <-- top
 | a3 | |
 --------
 | a2 | |
 --------
 | a1 |^|
 --------

 */
#ifndef Stack_h
#define Stack_h

#include <stdio.h>
#define MAXSIZE 20
#define ERROR 0
#define OK 1
typedef int Status;
typedef int SElemType;

/*栈的顺序存储结构*/
typedef struct {
    SElemType data[MAXSIZE];
    int top; // 用于栈顶指针
}SqStack;

/*栈的链式存储结构*/
typedef struct StackNode {
    SElemType data;
    struct StackNode *next;
}StackNode;

typedef struct StackNode *LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
}LinkStack;

#endif /* Stack_h */
