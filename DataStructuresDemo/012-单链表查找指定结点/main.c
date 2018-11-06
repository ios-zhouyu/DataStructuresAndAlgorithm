//
//  main.c
//  012-单链表查找指定结点
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
typedef Node *LinkList;

LinkList initializeList() {
    LinkList head;
    head = (LinkList)malloc(sizeof(Node));
    if (!head) {
        printf("初始化失败\n");
        exit(1);
    }
    head->name = "this is head node";
    head->next = NULL;
    return head;
}

LinkList createNode() {
    LinkList node = (LinkList)malloc(sizeof(Node));
    if (!node) {
        printf("create new node fail!\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

LinkList createList(LinkList head) {
    LinkList temp = head;
    char nameArr[20] = "qwertyuiopasdfghjklz";
    for (int i = 0; i < MAX_SIZE; i++) {
        LinkList node = createNode();
        node->num = i;
        node->name = &nameArr[i];
        
        if (temp->next == NULL) {
            temp->next = node;
        } else {
            node->next = temp->next;
            temp->next = node;
        }
    }
    return head;
}

void loopList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("%d --- %s\n", temp->num, temp->name);
        temp = temp->next;
    }
}

LinkList searchNode(LinkList list, int num) {
    LinkList temp = list;
    
    while (temp != NULL) {
        temp = temp->next;
        if (temp->num == num) {
            printf("find the node!\n");
            return temp;
        }
    }
    if (temp == NULL) {
        printf("node is not exist!");
    }
    return temp;
}


int main() {
    LinkList head = initializeList();
    LinkList list = createList(head);
    loopList(list);
    
    LinkList findNode = searchNode(list, 10);
    if (findNode) {
        printf("findNode.num = %d   findNode.name = %s\n",findNode->num, findNode->name);
    }
    
    return 0;
}
