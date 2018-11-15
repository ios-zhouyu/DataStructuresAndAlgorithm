//
//  main.c
//  059-二叉树递归创建
//
//  Created by zhouyu on 2018/11/15.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

struct Tree {
    int num;
    struct Tree *left;
    struct Tree *right;
};
typedef struct Tree Node;
typedef Node * TreeList;

TreeList createNode(int value) {
    TreeList node = (TreeList)malloc(sizeof(Node));
    if (!node) {
        printf("create new node failed\n");
        exit(1);
    }
    node->num = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeList createTree(int *data, int index) {
    TreeList node;
    if (data[index] == 0 || index > 15) {//循环终止
        return NULL;
    } else {
        
        node = createNode(data[index]);
        //左子树递归
        node->left = createTree(data, 2 * index);
        //右子树递归
        node->right = createTree(data, 2 * index + 1);
    }
    return node;
}

//递归函数调用图分析---左->父->右
void middleLoopTree(TreeList tree) {
    if (tree != NULL) {
        middleLoopTree(tree->left);
        printf("%d\n", tree->num);
        middleLoopTree(tree->right);
    }
}

int main() {
    TreeList root = NULL;
    //缺失的补个占位
    int data[] = {0,5,4,6,2,0,0,8,1,3,0,0,0,0,7,9};
    root = createTree(data, 1);
    middleLoopTree(root);
    return 0;
}
