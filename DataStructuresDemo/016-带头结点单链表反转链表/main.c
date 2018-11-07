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

//指针与结点的关系: 指针与指针域的区别
//p指向结点的指针, p->next: 在等式右边代表取值,取下个结点; 在等式左边代表赋值,改变指针指向
LinkList reverseList(LinkList list) {
    LinkList last, current, temp;//temp保存每次循环时取出的当前结点的下一个结点
    last = NULL;//初始化指针,保存每次循环的最后结点
    current = list->next;//取出开始结点
    list->next = NULL;//改变头结点指针域指向,将头结点断开
    while (current != NULL) {
        temp = current->next;//下一结点赋值给temp
        current->next = last;//断开当前结点,改变结点指向,指向上一次断开时的尾结点
        last = current;//将断开的结点作为尾结点
        current = temp;//下一个结点作为当前结点
    }
    list->next = last;//将倒置的结点链接到头结点
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
