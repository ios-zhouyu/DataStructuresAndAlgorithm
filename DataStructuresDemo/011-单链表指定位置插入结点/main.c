//
//  main.c
//  011-单链表指定位置插入结点
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
        printf("初始化失败\n");
        exit(1);
    }
    head->name = "这是头结点";
    head->next = NULL;
    printf("初始化成功\n");
    return head;
}

LinkList createListFromTail(LinkList head) {
    LinkList temp = head;
    LinkList newNode;
    for (int i = 0; i < MAX_SIZE; i++) {
        newNode = (LinkList)malloc(sizeof(Node));
        if (!newNode) {
            printf("第%d个新结点创建失败\n",i);
            exit(1);
        }
        newNode->num = i + 1000;
        newNode->name = "zhouyu";
        newNode->next = NULL;
        
        //尾插法
        temp->next = newNode;
        temp = newNode;
    }
    printf("添加结点成功\n");
    return head;
}

void loopList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("%d ---- %s \n", temp->num, temp->name);
        temp = temp->next;
    }
}

int getListLength(LinkList list) {
    LinkList temp = list;
    int i = 0;
    while (temp->next != NULL) {
        temp = temp->next;
        i++;
    }
    return i;
}

void insertNode(LinkList list, LinkList node, int location) {
    int length = getListLength(list);
    if (location > length || location < 0) {
        printf("插入位置错误\n");
        exit(1);
    }
    
    LinkList temp = list;
    int i = 0;
    while (temp != NULL) {
        if (location == i) {
            node->next = temp->next;
            temp->next = node;
            break;
        }
        temp = temp->next;
        i++;
    }
    
}

LinkList createNewNode() {
    LinkList node = (LinkList)malloc(sizeof(Node));
    if (!node) {
        printf("创建结点失败\n");
        exit(1);
    }
    node->num = rand() + 100000;
    node->name = "王五";
    node->next = NULL;
    return node;
}

int main() {
    
    LinkList head = initializeList();
    LinkList list = createListFromTail(head);
    loopList(list);
    printf("插入结点前链表长度: %d \n", getListLength(list));
    LinkList node = createNewNode();
    insertNode(list, node, 0);
    printf("插入结点后链表长度: %d \n", getListLength(list));
    loopList(list);
    return 0;
}
