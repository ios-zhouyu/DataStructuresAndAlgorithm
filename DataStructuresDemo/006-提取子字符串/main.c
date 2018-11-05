//
//  main.c
//  006-提取子字符串
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

char * subString(char *str, int start, int length) {
    static char temp[100];
    
    if (start + length > strLength(str)) {
        printf("有误\n");
        return "";
    }
    
    int i = 0;
    while (str[i] != '\0' && i < start + length) {
        if (i >= start) {
            temp[i - start] = str[i];
        }
        i++;
    }
    
    return temp;
}

int main(int argc, const char * argv[]) {
    
    char str[] = "fkoeafjjgdruwearnvmxdfger";
    char *substring;
    substring = subString(str, 4, 5);
    
    printf("%s\n", substring);
    return 0;
}
