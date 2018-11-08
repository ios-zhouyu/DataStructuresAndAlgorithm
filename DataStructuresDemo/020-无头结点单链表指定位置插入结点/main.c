//
//  main.c
//  020-无头结点单链表指定位置插入结点
//
//  Created by zhouyu on 2018/11/8.
//  Copyright © 2018年 zhouyu. All rights reserved.
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
        node->num = i + 1000;
        //头插法
        node->next = temp;
        temp = node;
    }
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

LinkList insertNode(LinkList list, LinkList node, int loction) {
    LinkList temp = list;
    int length = getListLength(list);
    if (length == 0) {
        printf("this list is a null list!\n");
        exit(1);
    }
    if (loction < 1 || loction > length + 1) {
        printf("the location is not right!\n");
        exit(1);
    }
    
    if (loction == 1) {//开始位置
        node->next = temp;
        temp = node;//指针指向开始结点
        list = temp;
    } else {
        int i = 1;
        while (temp != NULL) {
            if (loction - 1 == i) {//插入位置结点的上一个结点
                node->next = temp->next;
                temp->next = node;
                break;
            }
            temp = temp->next;
            i++;
        }
    }
    
    return list;
}

int main(int argc, const char * argv[]) {
    
    LinkList headPointer = NULL;
    LinkList nullList = initialList(headPointer);
    LinkList list = createList(nullList);
    loopList(list);
    printf("----------------------------\n");
    
    LinkList node = createNode();
    node->num = 9999;
    node->next = NULL;
    LinkList newList = insertNode(list, node, 1);
    loopList(newList);
    printf("----------------------------\n");
    return 0;
}
