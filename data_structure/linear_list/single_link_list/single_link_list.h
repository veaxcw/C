//
//  single_link_list.h
//  data_structure
//
//  Created by 程威 on 2020/4/11.
//  Copyright © 2020 程威. All rights reserved.
//

#ifndef single_link_list_h
#define single_link_list_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIST_INIT 100
#define LISTCREMENT 10
#define TURE  1i
#define FALSE 0
#define OK    1
#define ERROR 0
#define INFEASIBLE  - 1
#define OVERFLOW   - 2
#define Y 1
#define N 0
typedef int Status;
typedef struct LNode{
    int data;
    struct LNode  *next;
}LNode,*LinkList;

#endif /* single_link_list_h */
