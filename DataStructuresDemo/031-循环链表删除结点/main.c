//
//  main.c
//  031-循环链表删除结点
//
//  Created by zhouyu on 2018/11/9.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

struct List {
    int num;
    struct List *next;
};
typedef struct List Node;
typedef Node * LinkList;

LinkList initializeList(LinkList headPointer) {
    headPointer = NULL;
    return headPointer;
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

LinkList createList(LinkList list) {
    LinkList temp = list;
    LinkList node = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        node = createNode();
        node->num = i + 1000;
        //尾插法
        if (temp == NULL) {
            temp = node;
            list = node;
        } else {
            temp->next = node;
            temp = node;
        }
    }
    temp->next = list;//尾指针指向头部
    return list;
}

void loopList(LinkList list) {
    LinkList temp = list;
    do {
        printf("%d\n", temp->num);
        temp = temp->next;
    } while (temp != list);
}

int getListLength(LinkList list) {
    int length = 0;
    LinkList temp = list;
    do {
        temp = temp->next;
        length++;
    } while (temp != list);
    return length;
}

LinkList deleteNode(LinkList list, int num) {
    LinkList temp = list;
    LinkList ptr = temp;
    int length = 0;
    do {
        if (temp->num == num && length != 0) {
            ptr->next = temp->next;
            free(temp);
        }
        ptr = temp;//保存上一个结点
        temp = temp->next;
        length++;
    } while(temp != list);
    
    if (temp->num == num && length == getListLength(list)) {//删除开始结点
        ptr->next = temp->next;
        free(temp);
        list = ptr->next;
    }
    
    return list;
}

int main() {
    LinkList headPointer = NULL;
    LinkList nullList = initializeList(headPointer);
    LinkList list = createList(nullList);
    loopList(list);
    printf("------------------------------\n");
    
    LinkList newList = deleteNode(list, 1000);
    loopList(newList);
    
    return 0;
}

