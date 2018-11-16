//
//  main.c
//  065-线索二叉树
//
//  Created by zhouyu on 2018/11/15.
//  Copyright © 2018年 zhouyu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

//leftThread, rightThread表示left和right用途, 1表示是线索, 0表示是实际指针
struct Tree {
    int num;
    int leftThread;
    int rightThread;
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
    node->leftThread = 1;//线索
    node->rightThread = 1;//线索
    node->left = NULL;
    node->right = NULL;
    return node;
}

TreeList insertNode(TreeList root, int value) {
    TreeList currentNode = NULL;
    TreeList fatherNode = NULL;
    TreeList previousNode = NULL;
    
    TreeList newNode = createNode(value);
    
    currentNode = root->right;//当前结点
    if (currentNode == NULL) {//根结点
        root->right = newNode;
        newNode->left = root;//根结点的left和right都指向头结点
        newNode->right = root;
    }
    fatherNode = root;//父结点
    
    //MARK: 寻找插入点位置
    int position = 0;//决定走向,往左还是往右
    while (currentNode != NULL) {
        if (currentNode->num > newNode->num) {//比较h右子树
            if (position != -1) {//走向不同
                position = -1;
                previousNode = fatherNode;//记录父结点指针
            }
            fatherNode = currentNode;//保留父结点指针
            if (currentNode->leftThread == 0) {//
                currentNode = currentNode->left;
            } else {
                currentNode = NULL;//是线索
            }
        } else {//左子树
            if (position != 1) {
                position = 1;
                previousNode = fatherNode;
            }
            fatherNode = currentNode;
            if (currentNode->rightThread == 0) {
                currentNode = currentNode->right;
            } else {
                currentNode = NULL;
            }
        }
    }
    
    //链接父子结点
    if (fatherNode->num > newNode->num) {
        fatherNode->leftThread = 0;
        fatherNode->left = newNode;
        
        newNode->left = previousNode;
        newNode->right = fatherNode;
    } else {
        fatherNode->rightThread = 0;
        fatherNode->right = newNode;
        
        newNode->right = previousNode;
        newNode->left = fatherNode;
    }
    
    return root;
}

TreeList createTree(int *data, int length) {
    TreeList root = (TreeList)malloc(sizeof(Node));//头结点
    if (!root) {
        printf("create head node failed\n");
        exit(1);
    }
    root->num = 0;
    root->leftThread = 1;//线索
    root->rightThread = 0;//指针
    root->left = root;//左侧指向自己,无实际意义
    root->right = NULL;//右侧留给根结点
    for (int i = 0; i < length; i++) {
        root = insertNode(root, data[i]);
    }
    return root;
}

//线索二叉树中序遍历
void loopTree(TreeList root) {
    TreeList temp = root;
    do {
        if (temp->rightThread == 1) {
            temp = temp->right;
        } else {
            temp = temp->right;
            while (temp->leftThread != 1) {
                temp = temp->left;
            }
        }
        if (temp != root) {
            printf("%d\n", temp->num);
        }
    } while (temp != root);
}

int main(int argc, const char * argv[]) {
    
    TreeList root = NULL;
    int data[] = {5,6,4,8,2,3,7,1,9};
    
    root = createTree(data, 9);
    
    loopTree(root);
    
    return 0;
}
