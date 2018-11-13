//
//  main.c
//  044-栈的后续表达式处理
//
//  Created by zhouyu on 2018/11/13.
//  Copyright © 2018年 zhouyu. All rights reserved.
/*
 * 栈的应用场景: 1. 进制转换 2. 括号匹配检验 3.迷宫求解 4. 表达式计算
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
    int num;
    struct Stack *next;
};
typedef struct Stack Node;
typedef Node * StackList;

StackList operatorRandList = NULL;//操作数指针

StackList createNode() {
    StackList node = (StackList)malloc(sizeof(Node));
    if (!node) {
        printf("create new node failed!\n");
        exit(1);
    }
    node->next = NULL;
    return node;
}

StackList pushStack(StackList stack, int value) {
    StackList node = createNode();
    node->num = value;
    node->next = NULL;
    
    //头插法
    node->next = stack;
    stack = node;
    return stack;
}

StackList popStack(StackList stack, int *value) {
    StackList top = NULL;
    if (stack != NULL) {
        top = stack;
        *value = top->num;
        stack = stack->next;
        free(top);
    }
    return stack;
}

int emptyStack(StackList stack) {
    if (stack == NULL) {
        printf("this stack is empty\n");
        return 1;
    } else {
        printf("this stack is not empty\n");
        return 0;
    }
}

int isOperator(char operator) {
    switch (operator) {
        case '+':
        case '-':
        case '*':
        case '/':
            printf("%c is a operator character\n", operator);
            return 1;
        default:
            printf("%c is not a operator character\n", operator);
            return 0;
    }
}

int calculateTwoNums(char operator, int num1, int num2) {
    switch (operator) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            return num1 / num2;
        default:
            return 0;
    }
}

int main(int argc, const char * argv[]) {
    char expression[100] = "69*5+";//后序表达式
    int num1, num2;//取出的相邻两个数
    int result = 0;//两数计算结果
    
    for (int i = 0; expression[i] != '\0' && expression[i] != '\n'; i++) {
        if (isOperator(expression[i])) {//运算符
            //取出两个数
            operatorRandList = popStack(operatorRandList, &num1);
            operatorRandList = popStack(operatorRandList, &num2);
            //将计算的结果存入栈
            int tempResult = calculateTwoNums(expression[i], num1, num2);
            operatorRandList = pushStack(operatorRandList, tempResult);
        } else {//操作数
            operatorRandList = pushStack(operatorRandList, expression[i] - 48);
        }
    }
    operatorRandList = popStack(operatorRandList, &result);
    printf("69*5+ = %d\n", result);
    return 0;
}
