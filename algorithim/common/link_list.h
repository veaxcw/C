//
// Created by 程威 on 2021/2/21.
//

#ifndef ALGORITHIM_LINK_LIST_H
#define ALGORITHIM_LINK_LIST_H

#include "stdio.h"
#include "stdlib.h"

struct LinkList;
struct Node;

typedef void (* func_add)(int data, struct LinkList*);
typedef void (* func_print)(struct LinkList*);

typedef void (* func_push)(struct Node*, struct LinkList*);

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *pre;
} *NodePtr;

typedef struct LinkList {
    struct Node *head;
    struct Node *tail;
    int size;
    func_add add;
    func_print print;
    func_push push;
} *LinkListPtr;


LinkListPtr newLinkList();

LinkListPtr merger_sorted_list(LinkListPtr one, LinkListPtr other);

#endif //ALGORITHIM_LINK_LIST_H
