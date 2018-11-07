//
//  main.c
//  015-带头结点单链表交换两个结点的位置
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
        printf("initial head failed\n");
        exit(1);
    }
    head->num = 0;
    head->next = NULL;
    return head;
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

void loopList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("%d\n",temp->num);
        temp = temp->next;
    }
}

int searchNode(LinkList list, int num) {
    LinkList temp = list;
    while (temp != NULL) {
        if (temp->num == num) {
            printf("find this node!\n");
            return 1;
        }
        temp = temp-> next;
    }
    printf("can not find this node!\n");
    return 0;
}

void exchangeTwoNode(LinkList list, int num1, int num2) {
    if (searchNode(list, num1) == 0 || searchNode(list, num2) == 0) {
        printf("node->num is not exist!\n");
        exit(1);
    }
    LinkList temp = list;
    
    LinkList ptr1, ptr2;
    
    while (temp != NULL) {
        if (temp->num == num1 ) {
            ptr1 = temp;
        }
        if (temp->num == num2) {
            ptr2 = temp;
        }
        
        temp = temp->next;
    }
    
}

int main() {
    
    LinkList head = initializeList();
    LinkList list = createList(head);
    loopList(list);
    
    return 0;
}
