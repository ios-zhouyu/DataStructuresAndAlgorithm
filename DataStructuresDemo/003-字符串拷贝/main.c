//
//  main.c
//  003-字符串拷贝
//
//  Created by zhouyu on 2018/11/5.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>

void strcopy(char *newStr, const char *originStr) {
    int i = 0;
    for (i = 0; originStr[i] != '\0' ; i++) {
        newStr[i] = originStr[i];
    }
    newStr[i] = '\0';
    return ;
}

int main(int argc, const char * argv[]) {
    
    char originStr[] = "sdfjkoiejfoajefio";
    char newStr[100];
    
    strcopy(newStr, originStr);
    printf("%s \n", newStr);
    
    return 0;
}
