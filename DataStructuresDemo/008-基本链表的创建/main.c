//
//  main.c
//  008-基本链表的创建
//
//  Created by zhouyu on 2018/11/5.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//定义结构体
struct List {
    int num;
    int age;
    char *name;
};

//定义新类型
typedef struct List Node;
//定义新类型指针
typedef Node * LinkList;

int main(int argc, const char * argv[]) {
    
    LinkList stu;
    stu = (LinkList)malloc(sizeof(Node));
    
    stu->name = "zhouyu";
    stu->num = 123456;
    stu->age = 27;
    
    printf("Hello, World!\n");
    return 0;
}
