//
//  Stack.c
//  Data structure
//
//  Created by yfm on 2018/7/6.
//  Copyright © 2018年 yfm. All rights reserved.
//

#include "Stack.h"
#include <stdlib.h>

// 栈的顺序存储结构
// 插入元素e为新的栈顶元素(入栈)
Status Push(SqStack *S, SElemType e) {
    if (S->top == MAXSIZE - 1)
        return ERROR;
    S->top++;
    S->data[S->top] = e;
    return OK;
}

// 删除栈顶元素(出栈)
Status Pop(SqStack *S, SElemType *e) {
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top--;
    return OK;
}


// 栈的链式存储结构
int StackEmpty(LinkStack *top) {
    if (top == NULL)
        return 1;
    else
        return 0;
}

Status Push_Link(LinkStack *S, SElemType e) {
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top; // 把当前的栈顶元素赋值给新结点的直接后继
    S->top = s; // 将新的结点s赋值给栈顶指针
    S->count++;
    return OK;
}

Status Pop_Link(LinkStack *S, SElemType *e) {
    LinkStackPtr p;
    if (S->top == NULL)
        return ERROR;
    p = S->top;
    S->top = S->top->next;
    free(p);
    S->count--;
    return OK;
}
