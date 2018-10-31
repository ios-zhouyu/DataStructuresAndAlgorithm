//
//  main.c
//  001-数组管理学生成绩
//
//  Created by zhouyu on 10/31/18.
//  Copyright © 2018 zhouyu. All rights reserved.
//

#include <stdio.h>

int main() {
    
    struct Grade {
        int math;
        int english;
        int computer;
    };
    
    struct Grade student[5] = {
        {98,66,78},
        {87,78,99},
        {45,78,65},
        {87,83,91},
        {67,90,79}
    };
    
    int mSum = 0, eSum = 0, cSum = 0;
    //int length = sizeof(student) / sizeof(student[0]);
    int length = sizeof(student) / sizeof(struct Grade);
    
    for (int i = 0; i < length; i++) {
        mSum += student[i].math;
        eSum += student[i].english;
        cSum += student[i].computer;
    }
    
    printf(" mSum = %d \n eSum = %d \n cSum = %d \n", mSum, eSum, cSum);
    
    return 0;
}


