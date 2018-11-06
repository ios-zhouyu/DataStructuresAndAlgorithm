//
//  main.c
//  014-带头结点单链表清空链表
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
        printf("initial head fail!\n");
        exit(1);
    }
    head->num = MAX_SIZE;
    head->next = NULL;
    return head;
}

LinkList createList(LinkList head) {
    LinkList temp = head;
    LinkList node;
    
    for (int i = 0; i < MAX_SIZE; i++) {
        node = (LinkList)malloc(sizeof(Node));
        if (!node) {
            printf("create new node fail!\n");
            exit(1);
        }
        node->num = i + 1000;
        node->next = NULL;
        
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

LinkList emptyList(LinkList list) {
    LinkList temp = list;
    while (list != NULL) {
        temp = list;
        list = list->next;
        free(temp);
    }
    return list;
}

int main() {
    LinkList head;
    head = initializeList();
    LinkList list = createList(head);
    loopList(list);
    emptyList(list);
    printf("--------------------------\n");
    loopList(list);
    return 0;
}
