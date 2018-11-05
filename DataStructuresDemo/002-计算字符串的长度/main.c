//
//  main.c
//  002-计算字符串的长度
//
//  Created by zhouyu on 2018/11/5.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>

//计算字符串的长度
int strLength(char *str) {
    int i = 0;
    for (i = 0; str[i] != '\0'; i++) ; //不能写成双引号
    return i;
}

int main(int argc, const char * argv[]) {
    
    char str[] = "jsfdoaejfoajfas";
    int count = strLength(str);
    printf("%d \n", count);
    return 0;
}
