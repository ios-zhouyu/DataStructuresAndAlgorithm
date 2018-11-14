//
//  main.c
//  053-递归之汉诺塔问题
//
//  Created by zhouyu on 2018/11/14.
//  Copyright © 2018年 zhouyu. All rights reserved.
/*
 汉诺塔问题是一个经典的问题。汉诺塔（Hanoi Tower），又称河内塔，源于印度一个古老传说。大梵天创造世界的时候做了三根金刚石柱子，在一根柱子上从下往上按照大小顺序摞着64片黄金圆盘。大梵天命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，任何时候，在小圆盘上都不能放大圆盘，且在三根柱子之间一次只能移动一个圆盘。问应该如何操作？
 */

#include <stdio.h>
#include <stdlib.h>

int count = 0;

void hanoiTower(int dishCount, int pillar1, int pillar2, int pillar3) {
    if (dishCount == 1) {//终止条件
        printf("将盘子从柱子 %d 移到 柱子 %d\n", pillar1, pillar3);//第二步: 将最下面的盘子从1移到3
        count++;
    } else {
        hanoiTower(dishCount - 1, pillar1, pillar3, pillar2);//第一步: 将n-1个盘子从1移到2
        printf("将盘子从柱子 %d 移到 柱子 %d\n", pillar1, pillar3);
        count++;
        hanoiTower(dishCount - 1, pillar2, pillar1, pillar3);//第三步: 将n-1个盘子从2移到3
    }
}

int main() {
    //盘子数量 : 最终移动次数是2的n次方-1,几何级增长, n是盘子的数量
    int dishCount = 7;
    //三根柱子
    int pillar1 = 1;
    int pillar2 = 2;
    int pillar3 = 3;
    
    hanoiTower(dishCount, pillar1, pillar2, pillar3);
    printf("共移动了%d次\n", count);
    return 0;
}
