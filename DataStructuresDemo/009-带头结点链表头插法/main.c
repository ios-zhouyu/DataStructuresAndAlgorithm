//
//  main.c
//  009-带头结点链表头插法
//
//  Created by zhouyu on 2018/11/6.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
        printf("初始化head失败\n");
        exit(1);
    }
    head->name = "这是头结点";
    head->next = NULL;
    return head;
}

//头插法创建链表
LinkList createLinkListFromHead(LinkList head) {
    LinkList newNode;
    LinkList temp = head;
    for (int i = 0; i < MAX_SIZE; i++) {
        newNode = (LinkList)malloc(sizeof(Node));
        if (!newNode) {
            printf("创建新结点失败\n");
            exit(1);
        }
        newNode->num = i + 1000;
        newNode->name = "zhouyu";
        newNode->next = NULL;
        
        //头插法需要判断头结点后面是否有结点
        if (head->next == NULL) {//插入第一个结点
            temp->next = newNode;
        } else {//插入其他结点
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    
    return head;
}

void loopThroughList(LinkList head) {
    LinkList temp = head;
    while (temp != NULL) {
        printf("%d --- %s \n", temp->num, temp->name);
        temp = temp->next;
    }
}

int main() {
    
    LinkList head;
    head = initializeList();
    LinkList list = createLinkListFromHead(head);
    loopThroughList(list);
    return 0;
}
