//
//  static_link_list.h
//  data_structure
//
//  Created by 程威 on 2020/4/11.
//  Copyright © 2020 程威. All rights reserved.
//

#ifndef static_link_list_h
#define static_link_list_h

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#define TURE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define MAXSIZE 100
typedef struct
{
    char *data;
    int cur; //指示器cur代表指针,指示的节点在数组中的相对位置
} Node,SLinkList[MAXSIZE];

#endif /* static_link_list_h */
