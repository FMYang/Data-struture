//
//  main.c
//  Data structure
//
//  Created by yfm on 2018/7/4.
//  Copyright © 2018年 yfm. All rights reserved.
//

#include <stdio.h>
#include "List.h"
#include "Node.h"
#include "String.h"

void ListTest(void);
void NodeTest(void);

void showList(SqList *L, char* msg) {
    printf("%s，List的数据为：\n", msg);
    for(int i= 0; i<L->length; i++) {
        printf("%d,", L->data[i]);
    }
    printf("\n");
}

int Fbi(int i) {
    if (i<2) {
        return 1;
    }
    return Fbi(i-1)+Fbi(i-2);
}

int main(int argc, const char * argv[]) {
//    ListTest();
    NodeTest();

    int a[40];
    a[0] = a[1] = 1;
    for (int i=2; i<40; i++) {
        a[i] = a[i-1] + a[i-2];
    }

    printf("前40位斐波那契数列数为：\n");
    for (int i=0; i<40; i++) {
        printf("%d,", Fbi(i));
    }
    printf("\n");


    char *s = "helloa";
    char *s1 = "hellos";
    printf("%d", Strcmp(s, s1));
    printf("长度为：%d\n", StrLength(s));

    printf("STRLEN: %d\n", StrLength(s));
    printf("sstrlen: %ld\n", Strlen1(s));
    
    return 0;
}

void ListTest(void) {
    printf("线性表顺序存储结构操作测试：\n");
    // 初始化线性表
    SqList L = {{5,2,1,3}, 4};
    showList(&L, "结构体L的值为");

    showList(&L, "插入前");
    ListInsert(&L, 1, 20);
    showList(&L, "插入后");

    ElemType e;
    GetElem(&L, 1, &e);

    printf("第1个位置的元素为：%d\n", e);

    ListDelete(&L, 5, &e);
    printf("待删除的元素为: %d\n", e);
    showList(&L, "删除后");
}

void NodeTest(void) {
    printf("线性表链式存储结构操作测试：\n");
    LinkList L;
    int n=10;
    // 初始化单链表
    CreateListTail(&L, n);

    LinkList p = L->next;
    do {
        printf("%d,", p->data);
        p = p->next;
    } while (p->next);
    printf("%d", p->data);
    printf("\n");

    ElemType e;
    Node_GetElem(L, 5, &e);
    printf("%d\n", e);

    Node_ListDelete(&L, 4, &e);
    printf("删除的元素为：%d\n", e);
    p = L->next;

    printf("删除之后的数据为：\n");
    do {
        printf("%d,", p->data);
        p = p->next;
    } while (p->next);
    printf("%d", p->data);
    printf("\n");
}


