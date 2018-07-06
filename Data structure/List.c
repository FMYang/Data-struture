//
//  List.c
//  Data structure
//
//  Created by yfm on 2018/7/5.
//  Copyright © 2018年 yfm. All rights reserved.
//

#include "List.h"

/*注意：线性表是从1开始计数的，可C语言中的数组却是从0开始第一个下标的，
 于是线性表的第i个元素是要存储在数组的第i-1的位置*/

/* 初始条件：顺序线性表L已存在，1<=i<=ListLength
   操作结果：用e返回L中第i个数据元素的值 */
Status GetElem(SqList *L, int i, ElemType *e) {
    if (L->length==0 || i<1 || i>L->length)
        return ERROR;
    *e = L->data[i-1];
    return OK;
}

/* 初始条件：顺序线性表L已存在， 1<=i<=ListLenght
   操作结果：在L中第i个位置之前插入新的元素e，L的长度加1 */
Status ListInsert(SqList *L, int i, ElemType e) {
    int k;
    // 线性表的长度不能超过存储空间(即数组的长度)
    if (L->length == MAXSIZE)
        return ERROR;
    if (i<1 || i>L->length+1)
        return ERROR;
    if (i<L->length) {
        for (k=L->length-1; k>=i-1; k--)
            L->data[k+1] = L->data[k];
    }
    L->data[i-1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e) {
    if (i<1 || i>L->length)
        return ERROR;
    *e = L->data[i-1];
    if (L->length) {
        for (int k=i; k<L->length; k++) {
            L->data[k-1] = L->data[k];
        }
    }
    L->length--;
    return OK;
}
