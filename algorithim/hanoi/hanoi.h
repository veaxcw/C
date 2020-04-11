//
//  hanio.h
//  c
//  汉诺塔算法
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

#ifndef hanoi_h
#define hanoi_h

#include <stdio.h>

/// 汉诺塔算法入口
void hanoi(void);

///递归实现汉诺塔算法
void do_hanoi(int,char,char,char);

void do_move(char a,int num,char b);

#endif /* hanio_h */
