//
//  List.h
//  Data structure
//
//  Created by yfm on 2018/7/5.
//  Copyright © 2018年 yfm. All rights reserved.
//
//  线性表
//

#ifndef List_h
#define List_h

#include <stdio.h>

#define OK 1
#define ERROR 0
#define MAXSIZE 20 /*存储空间初始分配量*/
typedef int ElemType; /*ElemType 类型根据实际情况而定，这里假设为int*/
typedef int Status;
typedef struct {
    ElemType data[MAXSIZE]; /*数组存储数据元素，最大值为MAXSIZE*/
    int length;  /*线性表当前长度*/
}SqList;

Status GetElem(SqList *L, int i, ElemType *e);
Status ListInsert(SqList *L, int i, ElemType e);
Status ListDelete(SqList *L, int i, ElemType *e);

#endif /* List_h */
