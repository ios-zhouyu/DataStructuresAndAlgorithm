//
//  main.c
//  025-无头结点链表两表链接
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

LinkList initialList(LinkList headPoniter) {
    headPoniter = NULL;
    return headPoniter;
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
    LinkList temp = nullList;
    for (int i = 0; i < MAX_SIZE; i++) {
        LinkList node = createNode();
        node->num = i + 1000;
        //头插法
        node->next = temp;
        temp = node;
    }
    return temp;
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
    while (list != NULL) {
        length++;
        list = list->next;
    }
    printf("the length of this list is %d\n", length);
    return length;
}

int main() {
    LinkList headPointer = NULL;
    LinkList nullList = initialList(headPointer);
    LinkList list = createList(nullList);
    loopList(list);
    printf("----------------------------\n");
    
    return 0;
}
