//
//  main.c
//  050-递归基本操作
//
//  Created by zhouyu on 2018/11/14.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>

int recursiveNPower(int n) {
    int sum = 0;
    if (n == 0) {
        sum = 1;
    } else {
        sum = n * recursiveNPower(n - 1);
    }
    return sum;
}

int main() {
    
    int n = 10;
    
    int result = recursiveNPower(n);
    
    printf("%d! = %d\n", n, result);
    return 0;
}
