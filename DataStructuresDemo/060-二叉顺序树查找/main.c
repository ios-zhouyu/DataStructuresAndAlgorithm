//
//  main.c
//  060-二叉顺序树查找
//
//  Created by zhouyu on 2018/11/15.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

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

void middleLoopTree(TreeList tree) {
    if (tree != NULL) {
        middleLoopTree(tree->left);
        printf("%d\n", tree->num);
        middleLoopTree(tree->right);
    }
}

//二叉顺序树的查找
TreeList searchNode(TreeList node, int value) {
    while (node != NULL) {
        if (node->num == value) {
            return node;
        } else {
            if (node->num > value) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
    }
    return NULL;
}

//通用二叉树的查找---递归遍历法
TreeList generalSearchNode(TreeList node, int value) {
    TreeList ptrLeft = NULL;
    TreeList ptrRight = NULL;
    if (node != NULL) {
        if (node->num == value) {
            return node;
        } else {
            ptrLeft = generalSearchNode(node->left, value);
            ptrRight = generalSearchNode(node->right, value);
            if (ptrLeft != NULL) {
                return ptrLeft;
            } else {
                return ptrRight;
            }
        }
    }
    return node;
}


int main() {
    TreeList root = NULL;
    //缺失的补个占位
    int data[] = {0,5,4,6,2,0,0,8,1,3,0,0,0,0,7,9};
    root = createTree(data, 1);
    middleLoopTree(root);
    
    printf("-----------------------------------\n");
    TreeList findNode = searchNode(root, 3);
    printf("%d\n", findNode->num);
    
    printf("-----------------------------------\n");
    TreeList generalFindNode = generalSearchNode(root, 8);
    printf("%d\n", generalFindNode->num);
    return 0;
}
