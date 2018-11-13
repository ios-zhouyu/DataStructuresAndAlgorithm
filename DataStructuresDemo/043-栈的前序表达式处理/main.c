//
//  main.c
//  043-栈的前序表达式处理
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

//栈其实就是没有头结点的使用头插法实现的链表
//前序表达式需要建立两个栈: 一个存储原始表达式,一个存储临时数据
StackList operatorRandList = NULL;//栈顶指针初始化
StackList randList = NULL;//操作数栈

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
    //头插法
    node->next = stack;
    stack = node;
    return stack;
}

StackList popStack(StackList stack, int *value) {
    StackList tempTop = stack;
    if (stack != NULL) {
        *value = tempTop->num;
        stack = stack->next;
        free(tempTop);
    }
    return stack;
}

int isEmptyStack(StackList stack) {
    if (stack == NULL) {
        printf("this stack is a empty stack\n");
        return 1;
    }
    return 0;
}

int isOperatorCharacter(char operator) {
    switch (operator) {
        case '+':
        case '-':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int calculateTwoNums(char operator, int num1, int num2) {
    int result = 0;
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
            break;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    
    char expression[100] = "+*67+45";//从右往左读取
    int num1, num2;
    int result = 0;
    int tempOperator = 0;//取出的字符(运算符或操作数)
    
    //栈先存入整个表达式
    for (int i = 0; expression[i] != '\0' && expression[i] != '\n'; i++) {
        operatorRandList = pushStack(operatorRandList, expression[i]);
    }
    //54+76*+
    
    //一一取出计算
    while (!isEmptyStack(operatorRandList)) {
        operatorRandList = popStack(operatorRandList, &tempOperator);
        if (isOperatorCharacter(tempOperator)) {//运算符
            //从数据栈中取出两个数
            randList = popStack(randList, &num1);
            randList = popStack(randList, &num2);
            //计算后再存入数据栈
            int tempResult = calculateTwoNums(tempOperator, num1, num2);
            randList = pushStack(randList, tempResult);
        } else {
            randList = pushStack(randList, tempOperator - 48);//专门存储数据的栈
        }
    }
    //从数据栈中取出最后结果
    randList = popStack(randList, &result);
    printf("+*67+45 = %d\n", result);
    return 0;
}
