//
//  main.c
//  017-带头结点单链表两表连接
//
//  Created by zhouyu on 11/7/18.
//  Copyright © 2018 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

static int listNum = 1000;

struct List {
    int num;
    struct List *next;
};
typedef struct List Node;
typedef Node * LinkList;

LinkList initialList() {
    LinkList head = (LinkList)malloc(sizeof(Node));
    if (!head) {
        printf("initial head fatiled\n");
        exit(1);
    }
    head->num = 0;
    head->next = NULL;
    return head;
}

LinkList createNode() {
    LinkList node = (LinkList)malloc(sizeof(Node));
    if (!node) {
        printf("create new node fatiled\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

LinkList createList(LinkList head) {
    LinkList temp = head;
    for (int i = 0; i < MAX_SIZE; i++) {
        LinkList node = createNode();
        node->num = i + listNum;
        
        temp->next = node;
        temp = node;
    }
    listNum *= 2;
    return head;
}

void loopList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}

LinkList connectTwoList(LinkList list1, LinkList list2) {
    LinkList temp = list1;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    LinkList ptr = list2;
    ptr = ptr->next;//去掉头结点
    while (ptr != NULL) {
        temp->next = ptr;
        temp = ptr;
        ptr = ptr->next;
    }
    
    return list1;
}

int main(int argc, const char * argv[]) {
    
    LinkList head1 = initialList();
    LinkList list1 = createList(head1);
    LinkList head2 = initialList();
    LinkList list2 = createList(head2);
    loopList(list1);
    printf("------------------------------------\n");
    loopList(list2);
    printf("------------------------------------\n");
    LinkList list3 = connectTwoList(list1,list2);
    loopList(list3);
    return 0;
}
