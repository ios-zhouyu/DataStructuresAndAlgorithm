//
//  main.c
//  019-无头结点单链表创建(尾插法)
//
//  Created by zhouyu on 2018/11/8.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

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
        printf("create new node failed!\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

LinkList createList(LinkList nullList) {
    LinkList temp = nullList;//nullList也即是头指针headPointer
    LinkList firstNode = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        LinkList node = createNode();
        node->num = i + 1000;
        
        if (temp == NULL) {
            temp = node;
            firstNode = temp;//保留住头指针
        } else {
            temp->next = node;
            temp = node;
        }
    }
    return firstNode;
}

void loopList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}

int getListLength(LinkList list) {
    int length = 0;
    LinkList temp = list;
    while (temp != NULL) {
        length++;
        temp = temp->next;
    }
    printf("the length of this list is %d\n",length);
    return length;
}

int main() {
    
    LinkList headPointer = NULL;
    LinkList nullList = initializeList(headPointer);
    LinkList list = createList(nullList);
    loopList(list);
    int length = getListLength(list);
    
    return 0;
}
