//
//  main.c
//  thread
//
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

#include "thread.h"

int main(int argc, const char * argv[]) {
    
    long niters;
    
    pthread_t tid1,tid2;
    
    niters = atoi(argv[1]);
    
    pthread_create(&tid1, NULL, thread, &niters);
    pthread_create(&tid2, NULL, thread, &niters);
    
    pthread_join(tid1, NULL);
    pthread_join(tid2,NULL);
    
    if ( cnt != (2 * niters)) {
        printf("boom cnt = %ld\n",cnt);
    }else {
        printf("ok cnt = %ld\n",cnt);
    }
    exit(0);
}
