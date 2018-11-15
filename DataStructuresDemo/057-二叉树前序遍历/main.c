//
//  main.c
//  057-二叉树前序遍历
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

TreeList insertTreeNode(TreeList root, int value) {
    //1. 创建新结点
    TreeList newNode = createNode(value);
    //2. 插入结点(是否是根结点)
    if (root == NULL) {
        root = newNode;
    } else {
        TreeList currentNode = root;
        TreeList fatherNode = NULL;
        while (currentNode != NULL) {
            fatherNode = currentNode;//记录当前结点,作为父结点,接收新结点作为子结点
            if (currentNode->num > newNode->num) {
                currentNode = currentNode->left;
            } else {
                currentNode = currentNode->right;
            }
        }
        //3. 父子结点链接
        if (fatherNode->num > newNode->num) {
            fatherNode->left = newNode;
        } else {
            fatherNode->right = newNode;
        }
    }
    return root;
}

TreeList createTree(TreeList root, int *data, int length) {
    for (int i = 0; i < length; i++) {
        root = insertTreeNode(root, data[i]);
    }
    return root;
}

//递归函数调用图分析--根->左->右
void preLoopTree(TreeList tree) {
    if (tree != NULL) {
        printf("%d\n", tree->num);
        preLoopTree(tree->left);
        preLoopTree(tree->right);
    }
}

int main(int argc, const char * argv[]) {
    TreeList root = NULL;
    int data[MAX_SIZE] = {5,6,4,8,2,3,7,1,9};
    root = createTree(root, data, 9);
    preLoopTree(root);
    return 0;
}
