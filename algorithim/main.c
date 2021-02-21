//
//  main.c
//  algorithim
//
//  Created by 程威 on 2020/4/4.
//  Copyright © 2020 程威. All rights reserved.
//

//#include "hanoi.h"
//#include "maze.h"

#include "sort/sort.h"
#include "common/link_list.h"

int main(int argc, const char * argv[]) {
    //hanoi();
    //maze();
    //sort();
    printf("/chengwei haha\n");
    LinkListPtr list = newLinkList();
    list->add(1, list);
    list->add(3, list);
    list->add(5, list);

    LinkListPtr other = newLinkList();
    other->add(2, other);
    other->add(4, other);

    LinkListPtr result = merger_sorted_list(list, other);
    result->print(result);
    return 0;
}
