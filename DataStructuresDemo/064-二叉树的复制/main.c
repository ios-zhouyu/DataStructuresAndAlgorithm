//
//  main.c
//  064-二叉树的复制
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
    TreeList root = NULL;
    
    if (data[index] == 0 || index > 15) {
        return NULL;
    } else {
        root = createNode(data[index]);
        root->left = createTree(data, 2 * index);
        root->right = createTree(data, 2 * index + 1);
    }
    
    return root;
}

void middleLoopTree(TreeList root) {
    if (root != NULL) {
        middleLoopTree(root->left);
        printf("%d\n",root->num);
        middleLoopTree(root->right);
    }
}

TreeList copyTree(TreeList root) {
    TreeList newTree = NULL;
    if (root == NULL) {
        return NULL;
    } else {
        newTree = createNode(root->num);
        newTree->left = copyTree(root->left);
        newTree->right = copyTree(root->right);
        return newTree;
    }
}

int main(int argc, const char * argv[]) {
    TreeList root = NULL;
    //缺失的补个占位
    int data[] = {0,5,4,6,2,0,0,8,1,3,0,0,0,0,7,9};
    root = createTree(data, 1);
    middleLoopTree(root);
    printf("----------------------------\n");
    
    TreeList newTree = copyTree(root);
    middleLoopTree(newTree);
    return 0;
}
