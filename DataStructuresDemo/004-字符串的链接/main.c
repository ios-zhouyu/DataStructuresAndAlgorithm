//
//  main.c
//  004-字符串的链接
//
//  Created by zhouyu on 2018/11/5.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>

int strLength(char *str) {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

void stringCat(char *newStr, char *originStr) {
    int i = 0;
    
    int newStrLength = strLength(newStr);
    
    while (originStr[i] != '\0') {
        newStr[newStrLength + i] = originStr[i];
        i++;
    }
    
    return ;
}

int main(int argc, const char * argv[]) {
    
    char str[] = "sfsaegfae";
    char str2[100] = "kjogkyjoy";
    
    stringCat(str2, str);
    printf("%s \n", str2);
    
    return 0;
}
