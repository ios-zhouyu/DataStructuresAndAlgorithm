//
//  main.c
//  041-链栈基础操作
//
//  Created by zhouyu on 2018/11/13.
//  Copyright © 2018年 zhouyu. All rights reserved.
/*
 * 栈的应用场景: 1. 进制转换 2. 括号匹配检验 3.迷宫求解 4. 表达式计算
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

struct Stack {
    int num;
    struct Stack *next;
};
typedef struct Stack Node;
typedef Node * StackList;

StackList createNode() {
    StackList node = (StackList)malloc(sizeof(Node));
    if (!node) {
        printf("create new node failed!\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

StackList pushStack(StackList stackTop, int value) {
    StackList node = createNode();
    node->num = value;
    //本质上使用头插法实现的链表
    node->next = stackTop;
    stackTop = node;
    return stackTop;
}

StackList createStackList(StackList stackTop) {
    for (int i = 0; i < MAX_SIZE; i++) {
        stackTop = pushStack(stackTop, i + 1000);
    }
    return stackTop;
}

StackList popStack(StackList stackTop, int *value) {
    StackList temp = stackTop;
    if (temp != NULL) {
        printf("%d\n", temp->num);
        *value = temp->num;
        free(temp);
        stackTop = temp->next;
    }
    return stackTop;
}

int emptyStack(StackList stackTop) {
    if (stackTop == NULL) {
        printf("空栈\n");
        return 0;
    } else {
        printf("非空栈\n");
        return 1;
    }
}

int main(int argc, const char * argv[]) {
    
    StackList stackTop = NULL;//栈指针
    
    StackList stackList = createStackList(stackTop);
    
    int value = 0;
    
    StackList newStackList = stackList;
    for (int i = 0; i < MAX_SIZE; i++) {
        stackList = popStack(stackList, &value);
        printf("value = %d\n", value);
    }
    
    emptyStack(newStackList);
    
    return 0;
}
