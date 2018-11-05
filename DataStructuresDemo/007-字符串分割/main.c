//
//  main.c
//  007-字符串分割
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

char * strSplit(char *str, char ch) {
    static char temp[10][10];
    
    int i = 0;
    int m = 0;
    int n = 0;
    while (str[i] != '\0') {
        if (str[i] == ch ) {
            m++;
            n = 0;
            temp[m][n] = '\0';
            printf("%s \n", temp[m - 1]);
        } else {
            temp[m][n] = str[i];
            n++;
        }
        i++;
    }
    
    return temp;
}

int main(int argc, const char * argv[]) {
    
    char str[] = "this a params and love";
    
    char *result = strSplit(str, ' ');
    printf("\n");
    return 0;
}
