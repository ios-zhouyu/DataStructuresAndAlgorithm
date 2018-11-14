//
//  main.c
//  052-递归之创建链表
//
//  Created by zhouyu on 2018/11/14.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Recursive {
    int num;
    struct Recursive *next;
};
typedef struct Recursive Node;
typedef Node * RecursiveList;

RecursiveList createNode() {
    RecursiveList node = (RecursiveList)malloc(sizeof(Node));
    if (!node) {
        printf("cretae new node failed\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

//根据递归函数调用的本质,先执行index == length,再往上推,调用上一级函数,实质上是尾插法
RecursiveList createList(int *arr, int length, int index) {
    RecursiveList head = NULL;
    if (index == length) {//终止条件
        return  NULL;
    } else {
        head = createNode();
        head->num = arr[index];
        head->next = createList(arr, length, ++index);
        return head;
    }
}

void loopList(RecursiveList list) {
    if (list != NULL) {
        printf("%d\n", list->num);
        loopList(list->next);
    }
}

int main(int argc, const char * argv[]) {
    int arr[MAX_SIZE];
    
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = i + 1000;
    }
    
    RecursiveList list = createList(arr, MAX_SIZE, 0);
    loopList(list);
    
    return 0;
}
