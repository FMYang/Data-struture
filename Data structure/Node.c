//
//  Node.c
//  Data structure
//
//  Created by yfm on 2018/7/5.
//  Copyright © 2018年 yfm. All rights reserved.
//
//  单链表

#include "Node.h"
#include <stdlib.h>
#include <time.h>

// 随机产生n个元素的值，建立带表头结点的单链表L（头插法）
void CreateListHead(LinkList *L, int n) {
    LinkList p;
    *L = (LinkList)malloc(sizeof(Node));
    srand((unsigned int)time(0)); // 初始化随机种子
    (*L)->next = NULL; // 先建立一个带头结点的单链表， L指向整个单链表（L为头指针）
    for (int i=0; i<n; i++) {
        p = (LinkList)malloc(sizeof(Node)); // 生成新的结点
        p->data = rand()%100 + 1; //
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

// 随机产生n个元素的值，建立带表头结点的单链表L（尾插法）
void CreateListTail(LinkList *L, int n) {
    LinkList p, r;
    int i;
    srand((unsigned int)time(0));
    *L = (LinkList)malloc(sizeof(Node));
    r = *L; // r为指向尾部的结点
    for (i=0; i<n; i++) {
        p = (LinkList)malloc(sizeof(Node)); // 生成新的结点
        p->data = rand()%100+1;
        r->next = p; // 将表尾终端结点的指针指向新节点
        r = p; // 将当前的新结点定义为表尾终端结点
    }
    r->next = NULL; // 表示当前链表结束
}

// 单链表查找
Status Node_GetElem(LinkList L, int i, ElemType *e) {
    int j = 1;
    LinkList p; // 声明一结点p
    p = L->next; // 让p直行链表L的第一个结点
    while (p && j<i) {
        p = p->next; // p指向下一个结点
        ++j;
    }

    if (!p && j>1)
        return ERROR; // 第i个元素不存在
    *e = p->data; // 取得第i个元素的数据
    
    return OK;
}

// 单链表插入
Status Node_ListInsert(LinkList *L, int i, ElemType e) {
    int j;
    LinkList p = NULL, s;
    j = 1;
    while (p && j < i) { // 寻找第i个结点
        p = p->next;
        ++j;
    }
    if (!p && j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}

// 单链表删除
Status Node_ListDelete(LinkList *L, int i, ElemType *e) {
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i) {
        p = p->next;
        j++;
    }
    if (!(p->next) || j>i)
        return ERROR;
    q = p->next;
    p->next = q->next; // q的后继赋值给p的后继
    *e = q->data; // 将q结点中的数据给e
    free(q); // 让系统回收此结点，释放内存
    return OK;
}

// 单链表的整表删除
Status ClearList(LinkList *L) {
    LinkList p, q;
    p = (*L)->next; // p指向第一个结点
    while (p) { // 没到表尾
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL; // 头结点指针域为空
    return OK;
}
