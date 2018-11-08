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

#define MAX_SIZE 5

static int listNum = 1000;

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
        node->num = i + listNum;
        //头插法
        node->next = temp;
        temp = node;
    }
    listNum *= 2;
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

LinkList connectTwoLists(LinkList list1, LinkList list2) {
    LinkList temp = list1;
    
    if (temp == NULL) {
        list1 = list2;
    }
    
    LinkList ptr = NULL;//记录最后一个点
    while (temp != NULL) {
        if (temp != NULL && temp->next == NULL) {
            ptr = temp;
        }
        temp = temp->next;
    }
    ptr->next = list2;
    
    return list1;
}

int main() {
    LinkList headPointer = NULL;
    LinkList nullList = initialList(headPointer);
    LinkList list1 = createList(nullList);
    loopList(list1);
    printf("----------------------------\n");
    
    LinkList list2 = createList(nullList);
    loopList(list2);
    printf("----------------------------\n");
    
    LinkList list3 = connectTwoLists(list1, list2);
    loopList(list3);
    printf("----------------------------\n");
    
    return 0;
}
