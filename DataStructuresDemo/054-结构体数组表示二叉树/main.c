//
//  main.c
//  054-结构体数组表示二叉树
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
    int left;//左子结点索引,没有为-1
    int right;//右子结点索引,没有为-1
};
typedef struct Tree Node;

Node treeArr[15];

void createTree(int *data, int length) {
    //创建根节点
    treeArr[0].num = data[0];
    
    int level = 0;//树的层数
    int location = 0;//-1是左树, 1是右树
    
    for (int i = 1; i < length; i++) {
        level = 0;
        location = 0;
        treeArr[i].num = data[i];
        while (location == 0) {//用循环来找根结点
            //比较左右子树
            if (data[i] > treeArr[level].num) {//右树
                if (treeArr[level].right != -1) {//右树有下一层
                    level = treeArr[level].right;
                } else {
                    location = -1;//是右树
                }
            } else {//左树
                if (treeArr[level].left != -1) {//左树有下一层
                    level = treeArr[level].left;
                } else {
                    location = 1;//是左树
                }
            }
        }
        
        if (location == 1) {
            treeArr[level].left = i;//链接左子树
        } else {
            treeArr[level].right = i;//链接右子树
        }
    }
}

int main() {
    
    int data[MAX_SIZE] = {5,6,4,8,2,3,7,1,9};
    
    //初始化二叉树
    for (int i = 0; i < MAX_SIZE; i++) {
        treeArr[i].num = 0;
        treeArr[i].left = -1;
        treeArr[i].right = -1;
    }
    
    createTree(data, 9);
    
    for (int i = 0; i < MAX_SIZE; i++) {
        if (treeArr[i].num != 0) {
            printf("index %2d: [%2d]   [%2d]   [%2d]\n", i, treeArr[i].left, treeArr[i].num, treeArr[i].right);
        }
    }
    return 0;
}
