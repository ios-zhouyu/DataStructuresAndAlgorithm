//
//  main.c
//  026-单链表结构处理多项式
//
//  Created by zhouyu on 2018/11/8.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

//f(x)=x^4+2x^3-x+5
//拆分: 2x^3: 分为三步分: 1. 系数 2. 变量 3. 幂
//常量为n * x ^0 次幂
//因此链表需要存储的就是: 系数和幂
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct List {
    int num;
    int power;
    struct List *next;
};
typedef struct List Node;
typedef Node * LinkList;

LinkList initialList() {
    LinkList headPointer = NULL;
    return headPointer;
}

LinkList createNode() {
    LinkList node = (LinkList)malloc(sizeof(Node));
    if (!node) {
        printf("create new node failed\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

LinkList createMultipleTermList(LinkList headPointer, int (*arr)[2], int count) {
    LinkList node = NULL;
    LinkList firstNode = NULL;
    for (int i = 0; i < count; i++) {
        node = createNode();
        node->num = *(arr[i] + 0);
        node->power = *(arr[i] + 1);
        
        //头插法
//        node->next = headPointer;
//        headPointer = node;
        
        //尾插法
        if (headPointer == NULL) {
            headPointer = node;
            firstNode = headPointer;
        } else {
            headPointer->next = node;
            headPointer = node;
        }
    }
    headPointer = firstNode;
    
    return headPointer;
}

void loopList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("(%d ---- %d)\n", temp->num, temp->power);
        temp = temp->next;
    }
}

int calculateMultipleTermList(LinkList list, int x) {
    LinkList temp = list;
    int result = 0;
    while (temp != NULL) {
        result += (temp->num) * pow(x, (temp->power));
        temp = temp->next;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    int X = 3;
    int arr[][2] = {{1,4}, {2, 3}, {-1,1}, {5,0}};
    int count = sizeof(arr) / sizeof(arr[0]);
    
    LinkList headPointer = initialList();
    LinkList multipleTermList = createMultipleTermList(headPointer, arr, count);
    
    loopList(multipleTermList);
    
    int result = calculateMultipleTermList(multipleTermList, X);
    
    printf("f(x)=x^4+2x^3-x+5 再X = %d时,计算出的结果为: %d\n", X, result);
    return 0;
}
