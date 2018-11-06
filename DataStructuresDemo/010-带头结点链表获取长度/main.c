//
//  main.c
//  010-带头结点链表获取长度
//
//  Created by zhouyu on 2018/11/6.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 20

struct List {
    int num;
    char *name;
    struct List *next;
};
typedef struct List Node;
typedef Node * LinkList;

LinkList initializeList() {
    LinkList head;
    head = (LinkList)malloc(sizeof(Node));
    if (!head) {
        printf("初始化头结点失败\n");
        exit(1);
    }
    head->name = "这是头结点";
    head->next = NULL;
    return head;
}

LinkList createLinkList(LinkList head) {
    LinkList temp = head;
    LinkList newNode;
    for (int i = 0; i < MAX_SIZE; i++) {
        newNode = (LinkList)malloc(sizeof(Node));
        if (!newNode) {
            printf("创建新结点失败\n");
            exit(1);
        }
        newNode->num = i + 1000;
        newNode->name = "zhouyu";
        newNode->next = NULL;
        
        //头插法
        if (temp->next == NULL) {
            temp->next = newNode;
        } else {
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    return head;
}

int getListLength(LinkList head) {
    LinkList temp = head;
    int i = 0;
    while (temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    return i;
}

void loopThroughList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("%d ---- %s \n", temp->num, temp->name);
        temp = temp->next;
    }
}

int main() {
    
    LinkList head = initializeList();
    LinkList list = createLinkList(head);
    int count = getListLength(list);
    
    printf("%d\n", count);
    
    loopThroughList(list);
    return 0;
}
