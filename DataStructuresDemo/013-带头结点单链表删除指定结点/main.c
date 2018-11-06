//
//  main.c
//  013-单链表删除指定结点
//
//  Created by zhouyu on 11/6/18.
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
    LinkList head;
    head = (LinkList)malloc(sizeof(Node));
    if (!head) {
        printf("initial head node failed!\n");
        exit(1);
    }
    head->next = NULL;
    return head;
}

LinkList createNode() {
    LinkList node;
    node = (LinkList)malloc(sizeof(Node));
    if (!node) {
        printf("create node failed!\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

LinkList createList(LinkList head) {
    LinkList temp = head;
    LinkList node;
    for (int i = 0; i < MAX_SIZE; i++) {
        node = createNode();
        node->num = i + 1000;
        node->next = NULL;
        
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
        printf("%d \n", temp->num);
        temp = temp->next;
    }
}

LinkList deleteNode(LinkList list, int num) {
    LinkList temp = list;
    LinkList delNode;
    while (temp != NULL) {
        if (temp->next->num == num) {//找到将要删除点的上一个点(将要删除的点就是temp->next, 上一点就是temp,下一点就是temp->next->next)
            delNode = temp->next;//将要删除的点
            delNode->next = NULL;
            temp->next = temp->next->next;//将将要删除点的下一个点连接到上一个点的后面
            break;
        } else {
            temp = temp->next;
        }
    }
    
    if (delNode == NULL) {
        printf("cant not fond this node!\n");
        exit(1);
    }
    
    return delNode;
}

int main() {
    
    LinkList head = initializeList();
    LinkList list = createList(head);
    loopList(list);
    
    LinkList delNode = deleteNode(list, 1019);
    printf("-------------------- %d \n", delNode->num);
    free(delNode);
    loopList(list);
    return 0;
}
