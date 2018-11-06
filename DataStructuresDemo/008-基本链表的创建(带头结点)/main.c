//
//  main.c
//  008-基本链表的创建
//
//  Created by zhouyu on 2018/11/5.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
//原因是因为在c的结构体中，字符串不能直接这样赋值，需要用到string中的拷贝语句。
stu->num = 0001;
strcpy(stu->name, "zhouyu");
strcpy(stu->address, "北京市海淀区");

Node node = {0002, "zhangsan","上海市黄浦区"};
stu = &node;
 */

//定义结构体
struct List {
    int num;
    char name[20];
    char address[200];
    struct List *next;
};

//定义新类型
typedef struct List Node;
//定义新类型指针
typedef Node * LinkList;

//初始化带头结点的链表
LinkList initializeList() {
    LinkList head;
    head = (LinkList)malloc(sizeof(Node));
    if (!head) {
        printf("初始化head失败");
        exit(1);
    }
    strcpy(head->name, "这是头结点");
    head->next = NULL;
    return head;
}

//尾插法创建循环链表
LinkList createListFromTail(LinkList head) {
    LinkList newNode;
    LinkList temp = head;
    for (int i = 0; i < 20; i++) {
        //初始化新结点并赋值
        newNode = (LinkList)malloc(sizeof(Node));
        if (!newNode) {
            printf("创建新结点失败");
            exit(1);
        }
        newNode->num = i + 1000;
        strcpy(newNode->name, "zhouyu");
        newNode->next = NULL;
        
        //将新结点链接到表中,并移动到下一个位置
        temp->next = newNode;
        temp = newNode;
    }
    return head;
}

//遍历链表
void loopThroughLink(LinkList head) {
    LinkList temp = head;
    while (temp != NULL) {
        printf("%d -- %s \n", temp->num, temp->name);
        temp = temp->next;
    }
}

int main() {
    
    //初始化头结点
    LinkList head = initializeList();
    
    //指向链表头部的移动指针来创建链表
    LinkList ptr = createListFromTail(head);

    //遍历链表
    loopThroughLink(ptr);
    
    return 0;
}
