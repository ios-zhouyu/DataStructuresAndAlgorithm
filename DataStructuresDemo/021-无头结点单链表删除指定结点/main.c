//
//  main.c
//  021-无头结点单链表删除指定结点
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

int checkNodeInList(LinkList list, int num) {
    while (list != NULL) {
        if (list->num == num) {
            return 1;
        }
        list = list->next;
    }
    return 0;
}

LinkList deleteNode(LinkList list, int num) {
    LinkList temp = list;
    
    if (checkNodeInList(list, num) == 0) {
        printf("this node is not exist!\n");
        exit(1);
    }
    
    int i = 1;
    LinkList ptr = NULL;
    while (temp != NULL) {
        if (temp->num == num && i == 1) {//删除开始结点
            list = list->next;
            free(temp);
            break;
        } else if (temp->num == num) {
            ptr->next = temp->next;//当前结点的上一个结点指针域指向当前结点的下一个结点
            free(temp);
            break;
        }
        ptr = temp;//记录上一个结点
        temp = temp->next;
        i++;
    }
    
    return list;
}

int main() {
    
    LinkList headPointer = NULL;
    LinkList nullList = initialList(headPointer);
    LinkList list = createList(nullList);
    loopList(list);
    printf("----------------------------\n");
    
    LinkList newList = deleteNode(list, 1020);
    loopList(newList);
    printf("----------------------------\n");
    
    return 0;
}
