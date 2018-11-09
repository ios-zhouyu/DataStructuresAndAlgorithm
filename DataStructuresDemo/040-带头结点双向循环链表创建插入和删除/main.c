//
//  main.c
//  040-带头结点双向循环链表创建插入和删除
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
    struct List *pre;
    struct List *next;
};
typedef struct List Node;
typedef Node * LinkList;

LinkList initializeList(LinkList head) {
    head = (LinkList)malloc(sizeof(Node));
    if (!head) {
        printf("initial list failed!\n");
        exit(1);
    }
    head->pre = NULL;
    head->next = NULL;
    return head;
}

LinkList createNode() {
    LinkList node = (LinkList)malloc(sizeof(Node));
    if (!node) {
        printf("create new node failed\n");
        exit(1);
    }
    node->pre = NULL;
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
        temp->next = node;
        node->pre = temp;
        temp = node;
    }
    
    //循环--与非循环就多了此步
    temp->next = list;
    list->pre = temp;
    
    return list;
}

void loopList(LinkList list) {
    LinkList temp = list;
    
    do {
        printf("%d\n", temp->num);
        temp = temp->next;
    } while(temp != list);
}

int getListLength(LinkList list) {
    LinkList temp = list;
    int length = 0;
    do {
        temp = temp->next;
        length++;
    } while(temp != list);
    return length;
}

LinkList insertNode(LinkList list, LinkList node, int location) {
    LinkList temp = list;
    
    if (location < 1 || location > getListLength(list)) {
        printf("location is not right!\n");
        exit(1);
    }
    
    int length = 0;
    temp = list->next;
    do {
        if (location - 1 == length) {
            temp->pre->next = node;
            node->pre = temp->pre;
            
            node->next = temp;
            temp->pre = node;
            if (location == 1) {
                list = node;
            };
            break;
        }
        temp = temp->next;
        length++;
        
        if (location - 1 == length) {//最后一个
            temp->pre->next = node;
            node->pre = temp->pre;
            
            node->next = temp;
            temp->pre = node;
            break;
        }
    } while(temp != list);
    
    return list;
}

LinkList deleteNode(LinkList list, int num) {
    LinkList temp = list;
    do {
        if (temp->num == num) {
            temp->pre->next = temp->next;
            temp->next->pre = temp->pre;
            if (temp == list) {
                list = temp->next;
            }
            free(temp);
            break;
        }
        temp = temp->next;
    } while(temp != list);
    return list;
}

int main() {
    
    LinkList head = NULL;
    LinkList nullList = initializeList(head);
    LinkList list = createList(nullList);
    loopList(list);
    printf("---------------------------------\n");
    
    LinkList node = createNode();
    node->num = 9999;
    node->pre = NULL;
    node->next = NULL;
    LinkList newList = insertNode(list, node, 11);
    loopList(newList);
    printf("---------------------------------\n");

    LinkList newList2 = deleteNode(list, 9999);
    loopList(newList2);
    printf("---------------------------------\n");
    
    return 0;
}

