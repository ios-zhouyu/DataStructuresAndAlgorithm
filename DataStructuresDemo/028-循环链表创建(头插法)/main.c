//
//  main.c
//  028-循环链表创建
//
//  Created by zhouyu on 2018/11/8.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

struct List {
    int num;
    struct List *next;
};
typedef struct List Node;
typedef Node * LinkList;

LinkList initializeList(LinkList headPointer) {
    headPointer = NULL;
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

LinkList createList(LinkList list) {
    LinkList temp = list;
    LinkList node = NULL;
    //头插法: 记录最后一个结点
    LinkList lastNode = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        node = createNode();
        node->num = i + 1000;
        node->next = NULL;
        
        //头插法
        if (temp == NULL) {
            lastNode = node;
        }
        node->next = temp;
        temp = node;
    }

    //头插法
    lastNode->next = temp;
    list = temp;
    
    return list;
}

//循环链表的循环方式和单链表有区别
void loopList(LinkList list) {
    LinkList temp = list;
    do {
        printf("%d\n",temp->num);
        temp = temp->next;
    } while (temp != list) ;//循环终止条件: 头尾相同
}

int main() {
    
    LinkList headPointer = NULL;
    LinkList nullList = initializeList(headPointer);
    LinkList list = createList(nullList);
    loopList(list);
    
    return 0;
}
