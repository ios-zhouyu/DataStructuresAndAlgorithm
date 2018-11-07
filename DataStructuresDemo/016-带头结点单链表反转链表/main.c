//
//  main.c
//  016-带头结点单链表反转链表
//
//  Created by zhouyu on 11/7/18.
//  Copyright © 2018 zhouyu. All rights reserved.
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

LinkList initializeList() {
    LinkList head = (LinkList)malloc(sizeof(Node));
    if (!head) {
        printf("initial head failed!\n");
        exit(1);
    }
    head->num = -1;
    head->next = NULL;
    return head;
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

LinkList createList(LinkList head) {
    LinkList temp = head;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        LinkList node = createNode();
        node->num = i + 1000;
        
        temp->next = node;
        temp = node;
    }
    return head;
}

void looopList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}

LinkList reverseList(LinkList list) {
    LinkList newList, remainList, temp;//temp保存每次循环断开后的剩余链表
    newList = NULL;//新链表无头结点
    remainList = list->next;//接管指向剩余链表的开始结点
    list->next = NULL;//将头结点断开
    while (remainList != NULL) {
        temp = remainList->next;//临时保存指向剩余链表的结点
        remainList->next = newList;//断开当前结点,改变结点指向
        newList = remainList;//将断开的结点链接到新链表
        remainList = temp;//接管剩余链表
    }
    list->next = newList;//将倒置的结点链接到头结点
    return list;
}

int main() {
    LinkList head = initializeList();
    LinkList list = createList(head);
    looopList(list);
    printf("--------------------\n");
    LinkList revList = reverseList(list);
    looopList(revList);
    return 0;
}
