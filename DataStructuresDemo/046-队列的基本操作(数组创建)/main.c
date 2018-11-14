//
//  main.c
//  046-队列的基本操作
//
//  Created by zhouyu on 2018/11/13.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int enterQueue(int value) {
    if (rear < MAX_SIZE) {
        rear++;
        queue[rear] = value;
    } else {//满队列
        return -1;
    }
    return 1;
}

//判断是否为空就是判断首位标识是否相等
int deleteQueue() {
    int result = 0;
    if (front != rear) {
        front++;
        result = queue[front];
        queue[front] = 0;
    } else {//空列
        printf("queue is empty\n");
        return result;
    }
    return result;
}

int main() {

    for (int i = 0; i < MAX_SIZE; i++) {
        if (enterQueue(i + 1000) == -1) {
            printf("queue is full\n");
            break;
        }
    }
    
    while (front != rear) {
        int result = deleteQueue();
        printf("%d\n", result);
    }
    
    return 0;
}
