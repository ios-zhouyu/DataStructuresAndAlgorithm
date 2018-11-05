//
//  main.c
//  005-字符串插入
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

void strInsert(char *str, char *insertStr, int postion) {
    
    int i = 0;
    
    //保存原来字符串
    char temp[100];
    int j = 0;
    while (str[j] != '\0') {
        temp[j] = str[j];
        j++;
    }
    temp[j] = '\0';
    
    //插入新字符串
    while (insertStr[i] != '\0') {
        str[postion + i] = insertStr[i];
        i++;
    }
    
    //接入指定插入位置原有的字符
    while (temp[postion] != '\0') {
        str[postion + i] = temp[postion];
        postion ++;
    }
    str[postion + i] = '\0';
    
    return ;
}

int main(int argc, const char * argv[]) {
    
    char str1[] = "sfeff";
    char str2[100] = "hrdhgdr";
    
    strInsert(str2, str1, 5);
    
    printf("%s\n", str2);
    return 0;
}
