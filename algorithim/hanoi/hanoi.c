//
//  hanio.c
//  c
//
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

#include "hanoi.h"

int step = 1;

void hanoi()
{
    int num;
    printf("请输入Hanoi塔大小：");
    scanf("%d",&num);
    do_hanoi(num,'x','y','z');
}

void do_move(char a,int num,char b)
{
    printf("第%d步为：%c--->%c\n",step++,a,b);
}


void do_hanoi(int num,char x,char y,char z)
{
    if(num == 1) {
        do_move(x,1,z);
    }
    else
    {
        do_hanoi(num-1,x,z,y);
        do_move(x,num,z);
        do_hanoi(num-1,y,x,z);
    }
    
}

