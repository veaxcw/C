//
//  thread.c
//  c
//
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

#include "thread.h"

volatile long cnt = 0L;

void *thread(void *vargp) {
    long niters = *((long *)vargp);
    
    for (long i = 0;i < niters;i++) {
        cnt++;
    }
    return NULL;
}


