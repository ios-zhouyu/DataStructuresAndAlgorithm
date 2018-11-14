//
//  main.c
//  051-递归之斐波那契数列
//
//  Created by zhouyu on 2018/11/14.
//  Copyright © 2018年 zhouyu. All rights reserved.
/*
 斐波那契数列的排列是：0，1，1，2，3，5，8，13，21，34，55，89，144……依次类推下去，你会发现，它后一个数等于前面两个数的和。在这个数列中的数字，就被称为斐波那契数。
 */

#include <stdio.h>
#include <stdlib.h>

int recursiveExpression(int n) {
    int result = 0;
    if (n <= 1) {
        result = n;
    } else {
        result = recursiveExpression(n - 1) + recursiveExpression(n - 2);
    }
    return result;
}

int main(int argc, const char * argv[]) {
    int n = 10;
    int result = recursiveExpression(n);
    printf("%d\n", result);
    return 0;
}
