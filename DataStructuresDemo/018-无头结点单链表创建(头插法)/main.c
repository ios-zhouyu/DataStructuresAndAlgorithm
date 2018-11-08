//
//  main.c
//  018-无头节点单链表创建
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

LinkList initializeList(LinkList headPointer) {
    headPointer = NULL;
    printf("initial null list success!\n");
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

LinkList createList(LinkList nullList) {
    LinkList temp = nullList;
    for (int i = 0; i < MAX_SIZE; i++) {
        LinkList node = createNode();
        node->num = i + 1000;
        
        //MARK: 头插法
        //修改新节点的指针域指向NULL
        node->next = temp;//
        //修改头指针的指向新建节点
        temp = node;
    }
    
    //MARK: 创建完毕后返回头指针
    return temp;
}

void loopList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}

//注意头指针与头结点的区别
int main(int argc, const char * argv[]) {
    
    //MARK: 空表: 没有结点,仅仅用一个头指针表示,头指针为NULL
    LinkList headPointer = NULL;
    LinkList nullList = initializeList(headPointer);
    LinkList list = createList(nullList);
    loopList(list);
    
    return 0;
}
