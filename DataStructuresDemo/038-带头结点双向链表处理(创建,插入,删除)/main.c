//
//  main.c
//  038-带头结点双向链表处理
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
        if (temp == NULL) {
            temp = node;
            list = node;
        } else {
            temp->next = node;
            node->pre = temp;
            temp = node;
        }
    }
    
    return list;
}

void loopList(LinkList list) {
    LinkList temp = list;
    while (temp != NULL) {
        printf("%d\n", temp->num);
        temp = temp->next;
    }
}

int getListLength(LinkList list) {
    LinkList temp = list;
    int length = 0;
    while (temp != NULL) {
        temp = temp->next;
        length++;
    }
    return length;
}

LinkList insertNode(LinkList list, LinkList node, int location) {
    LinkList temp = list;
    
    if (location < 1 || location > getListLength(list) + 1) {
        printf("location is not right!\n");
        exit(1);
    }
    
    int length = 0;
    temp = temp->next;//从开始结点起(和无头结点相比,修改这个地方)
    LinkList ptr = temp;
    while (temp != NULL) {
        
        if (location == 1) {//开始结点处
            node->next = temp;
            temp->pre = node;
            
            node->pre = list;//(和无头结点相比,修改这个地方)
            list->next = node;//(和无头结点相比,修改这个地方)
            break;
        }
        
        if (location - 1 == length) {
            node->next = temp;
            ptr->next = node;
        }
        ptr = temp;
        temp = temp->next;
        length++;
        
        if (location - 1 == length) {//最后
            ptr->next = node;
            node->pre = ptr;
        }
    }
    
    return list;
}

//删除结点不用管
LinkList deleteNode(LinkList list, int num) {
    LinkList temp = list;
    while (temp != NULL) {
        if (temp->num == num) {
            if (temp == list) {//开始结点
                list = temp->next;
                free(temp);
                break;
            } else if (temp->next != NULL) {
                temp->next->pre = temp->pre;
                temp->pre->next = temp->next;
                free(temp);
                break;
            } else {//最后一个结点
                temp->pre->next = NULL;
                temp->pre = NULL;
                free(temp);
            }
        }
        temp = temp->next;
    }
    return list;
}

int main() {
    
    LinkList headPointer = NULL;
    LinkList nullList = initializeList(headPointer);
    LinkList list = createList(nullList);
    loopList(list);
    printf("---------------------------------\n");
    
    LinkList node = createNode();
    node->num = 9999;
    node->pre = NULL;
    node->next = NULL;
    LinkList newList = insertNode(list, node, 5);
    loopList(newList);
    printf("---------------------------------\n");
    
    LinkList newList2 = deleteNode(newList, 1004);
    loopList(newList2);
    printf("---------------------------------\n");
    
    return 0;
}

