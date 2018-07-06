//
//  Node.h
//  Data structure
//
//  Created by yfm on 2018/7/5.
//  Copyright © 2018年 yfm. All rights reserved.
//
//  单链表
//

/*  链式存储结构
      L         L->next
      ------    -------   -------   ------
 -->  |a1| |--> |a2|0x|-->|a3|0x|-->|an|^|
      ------    -------   -------   ------
 */

#ifndef Node_h
#define Node_h

#include <stdio.h>
#define ERROR 0
#define OK 1
typedef int ElemType; /*ElemType 类型根据实际情况而定，这里假设为int*/
typedef int Status;

/*线性表的单链表存储结构*/
typedef struct Node {
    ElemType data;  // 存放数据元素的数据域
    struct Node *next; // 存放后继结点地址的指针域
} Node;

typedef struct Node *LinkList; // 定义LinkList

void CreateListHead(LinkList *L, int n);
void CreateListTail(LinkList *L, int n);
Status Node_GetElem(LinkList L, int i, ElemType *e);
Status Node_ListInsert(LinkList *L, int i, ElemType e);
Status Node_ListDelete(LinkList *L, int i, ElemType *e);
Status ClearList(LinkList *L);

#endif /* Node_h */
