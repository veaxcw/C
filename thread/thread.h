//
//  thread.h
//  c
//
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

#ifndef thread_h
#define thread_h

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

extern volatile long cnt;

///工作线程 模拟cnt 的自增炒作
/// @param vargp 自增的次数
void *thread(void *vargp);

#endif /* thread_h */
