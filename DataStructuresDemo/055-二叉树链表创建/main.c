//
//  main.c
//  055-二叉树链表创建
//
//  Created by zhouyu on 2018/11/15.
//  Copyright © 2018年 zhouyu. All rights reserved.
/*
 * 结点: left | data | right
 */

/* 二叉树
                5
           4        6
      2                  8
 1        3        7        9
 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Tree {
    int num;
    struct Tree *left;
    struct Tree *reght;
};
typedef struct Tree Node;
typedef Node * TreeList;

TreeList insertTreeNode(TreeList root, int value) {
    TreeList newNode = NULL;//新建结点指针
    TreeList currentNode = NULL;//当前结点指针
    TreeList fatherNode = NULL;//父结点指针
    
    newNode = (TreeList)malloc(sizeof(Node));
    if (!newNode) {
        printf("create new node failed\n");
        exit(1);
    }
    newNode->num = value;
    newNode->left = NULL;
    newNode->reght = NULL;
    
    if (root == NULL) {//根结点
        root = newNode;
    } else {
        currentNode = root;//保留树根指针
        
        //不停地从根指针往下循环, 直到循环到当前结点的左子树或右子树为NULL
        //当前结点的值和新结点值作比较, 判断往当前结点的左子树还是右子树插入结点
        while (currentNode != NULL) {
            fatherNode = currentNode;//保留当前指针作为父结点指针
            if (currentNode->num > newNode->num) {
                currentNode = currentNode->left;//左子树
            } else {
                currentNode = currentNode->reght;//右子树
            }
        }
        
        //接起父子链接
        if (fatherNode->num > newNode->num) {
            fatherNode->left = newNode;
        } else {
            fatherNode->reght = newNode;
        }
    }
    
    return root;//返回根指针
}

TreeList createTree(int *data, int length) {
    TreeList root = NULL;
    for (int i = 0; i < length; i++) {
        root = insertTreeNode(root, data[i]);
        printf("%p\n", root);//地址不变
    }
    return root;
}

int main() {
    //树根指针
    TreeList root = NULL;
    int data[MAX_SIZE] = {5,6,4,8,2,3,7,1,9};
    root = createTree(data, 9);
    
    return 0;
}
