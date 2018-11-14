//
//  main.c
//  048-队列之链表创建
//
//  Created by zhouyu on 2018/11/14.
//  Copyright © 2018年 zhouyu. All rights reserved.
/*
 * 链表不存在满队列的情况,除非内存不够
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

struct Queue {
    int num;
    struct Queue *next;
};
typedef struct Queue Node;
typedef Node * QueueList;

QueueList front = NULL;
QueueList rear = NULL;

QueueList createNode() {
    QueueList node = (QueueList)malloc(sizeof(Node));
    if (!node) {
        printf("create new node failed\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

QueueList enterQueue(int value) {
    QueueList node = createNode();
    node->num = value;
    if (rear == NULL) {//头一个
        front = node;
        rear = node;
    } else {
        rear->next = node;
        rear = node;
    }
    return front;
}

int deleteQueue() {
    QueueList temp;
    int num;
    if (front == NULL) {
        printf("queue is empty!\n");
        exit(1);
    } else {
        temp = front;
        num = temp->num;
        front = front->next;
        free(temp);
    }
    return num;
}

int main() {
    QueueList list;
    for (int i = 0; i < MAX_SIZE; i++) {
        list = enterQueue(i + 1000);
    }
    
    int result = 0;
    for (int i = 0; i < MAX_SIZE / 2; i++) {
        result = deleteQueue();
        printf("%d\n", result);
    }
    
    printf("%p\n", front);
    return 0;
}
