//
//  main.c
//  047-循环队列数组控制
//
//  Created by zhouyu on 2018/11/14.
//  Copyright © 2018年 zhouyu. All rights reserved.
/*
 * 设计时,rear和front至少相隔一个元素,避免空队列和全满队列时,rear和front相等的情况
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

int enterQueue(int value) {
    //1. (rear == MAX_SIZE - 1 && front <= 0) 队列只进未出
    //2. (rear + 1 = front) 队列有进有出
    if ((rear == MAX_SIZE - 1 && front <= 0) || (rear + 1 == front)) {//满队列
        return 0;
    } else if (rear == MAX_SIZE) {//防止越界,循环使用
        rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
    return 1;
}

int deleteQueue() {
    int result = 0;
    //判断空队列
    if (rear == front) {
        return result;
    } else if (front == MAX_SIZE) {////防止越界,循环使用
        front = 0;
    }
    front++;
    result = queue[front];
    queue[front] = 0;
    return result;
}

int main() {
    
    for (int i = 0; i < MAX_SIZE; i++) {
        enterQueue(i + 1000);
    }
    
    for (int i = 0; i < MAX_SIZE / 2; i++) {
        deleteQueue();
    }
    
    for (int i = 0; i < MAX_SIZE; i++) {
        enterQueue(i + 1000 * 2);
    }
    
    for (int i = 0; i < MAX_SIZE; i++) {
        deleteQueue();
    }
    
    printf("%p\n",queue);
    return 0;
}
