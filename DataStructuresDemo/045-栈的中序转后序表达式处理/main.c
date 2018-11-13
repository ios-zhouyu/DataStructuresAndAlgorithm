//
//  main.c
//  045-栈的中序转后序表达式处理
//
//  Created by zhouyu on 2018/11/13.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int num;
    struct Stack *next;
};
typedef struct Stack Node;
typedef Node * StackList;

StackList operatorCharacterList = NULL;//临时保存运算符的栈

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
        return 1;
    } else {
        return 0;
    }
}

int isOperatorCharacter(char operator) {
    switch (operator) {
        case '(':
        case ')':
        case '+':
        case '_':
        case '*':
        case '/':
            return 1;
        default:
            return 0;
    }
}

int operatorCharacterPriority(char operator) {
    switch (operator) {
        case '*':
        case '/':
            return 3;
        case '+':
        case '-':
            return 2;
        case '(':
            return 1;
        default:
            return 0;
    }
}

int main(int argc, const char * argv[]) {
    char middleExpression[100] = "9*(6+4)";//9*(6+4)       (9+6)*4
    char suffixExpression[100];
    
    int tempOperator = 0;//取出的运算符
    int suffinIndex = 0;
    
    //读取表达式
    for (int i = 0; middleExpression[i] != '\0' && middleExpression[i] != '\n'; i++) {
        if (isOperatorCharacter(middleExpression[i])) {//运算符
            if (isEmptyStack(operatorCharacterList) || middleExpression[i] == '(') {
                operatorCharacterList = pushStack(operatorCharacterList, middleExpression[i]);
            } else {
                if (middleExpression[i] == ')') {//处理()括号
                    while (operatorCharacterList->num != '(') {//查看当前运算符栈顶端是不是(
                        //如果不是'(',取出来放入后序数组中
                        operatorCharacterList = popStack(operatorCharacterList, &tempOperator);
                        suffixExpression[suffinIndex++] = tempOperator;//其他运算符放到suffixExpression中
                    }
                    //如果是'(',取出来,扔掉
                    operatorCharacterList = popStack(operatorCharacterList, &tempOperator);
                } else { //不是(,),当前的运算符和运算符栈顶的运算符,比较优先级
                    while ((operatorCharacterPriority(middleExpression[i]) <= operatorCharacterPriority(operatorCharacterList->num)) && (isEmptyStack(operatorCharacterList) == 0)) {
                        //运算符栈中取出高级别运算符,存入后序表达式
                        operatorCharacterList = popStack(operatorCharacterList, &tempOperator);
                        suffixExpression[suffinIndex++] = tempOperator;
                    }
                    //当前数组中低级别的继续存入运算符栈
                    operatorCharacterList = pushStack(operatorCharacterList, middleExpression[i]);
                }
            }
        } else {//操作数
            suffixExpression[suffinIndex++] = middleExpression[i];
        }
    }
    
    //取出剩下的运算符
    while (isEmptyStack(operatorCharacterList) == 0) {
        operatorCharacterList = popStack(operatorCharacterList, &tempOperator);
        suffixExpression[suffinIndex++] = tempOperator;
    }
    suffixExpression[suffinIndex] = '\0';
    printf("%s\n", suffixExpression);
    return 0;
}
